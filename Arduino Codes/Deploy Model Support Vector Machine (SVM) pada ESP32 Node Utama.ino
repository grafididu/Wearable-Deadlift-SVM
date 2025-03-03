#include <esp_now.h>
#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_MPU6050.h>

#if __has_include("svm_model_minmax_scaler_baru.h")
  #include "svm_model_minmax_scaler_baru.h"
#else
  #error "File svm_model_minmax_scaler_baru.h tidak ditemukan!"
#endif

using namespace Eloquent::ML::Port;

Adafruit_MPU6050 mpu1;

// Alamat MAC Pengirim
uint8_t esp2Address[] = {0xFC, 0xE8, 0xC0, 0x79, 0x21, 0x5C};

// Struktur Data Untuk Menerima Data dari Pengirim
typedef struct sensor_data {
  float ax;
  float ay;
  float az;
} sensor_data;

sensor_data dataESP2;
bool esp2DataReceived = false;

// Konfigurasi Pin Buzzer
#define BUZZER_PIN 2
unsigned long lastReceivedTime = 0;
const unsigned long timeoutInterval = 5000; // 5 Detik timeout untuk data node pengirim

// Fungsi untuk normalisasi Fitur
void normalizeFeatures(float *features) {
  // Nilai Min dan Max berdasarkan analisis dataset
  const float minValues[6] = {-1.33, -5.02, -4.87, -3.06, -14.81, -9.12};
  const float maxValues[6] = {12.62, 8.65, 11.12, 14.63, 4.22, 10.87};

  for (int i = 0; i < 6; i++) {
    features[i] = (features[i] - minValues[i]) / (maxValues[i] - minValues[i]);
    if (features[i] < 0) features[i] = 0; // Clamp ke 0 jika underflow
    if (features[i] > 1) features[i] = 1; // Clamp ke 1 jika overflow
  }
}

// Fungsi callback untuk menerima data
void OnDataRecv(const esp_now_recv_info *info, const uint8_t *incomingData, int len) {
  if (memcmp(info->src_addr, esp2Address, 6) == 0) {
    memcpy(&dataESP2, incomingData, sizeof(dataESP2));
    esp2DataReceived = true;
    lastReceivedTime = millis(); // Reset timer saat data diterima
  }
}

void setup() {
  Wire.begin();
  Serial.begin(115200);
  pinMode(BUZZER_PIN, OUTPUT);

  WiFi.mode(WIFI_STA);

  if (!mpu1.begin()) {
    Serial.println("Failed to find MPU6050 chips");
    while (1) delay(10);
  }

  mpu1.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu1.setGyroRange(MPU6050_RANGE_500_DEG);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_recv_cb(OnDataRecv);
}

void loop() {
  // Periksa timeout untuk data node pengirim
  if (millis() - lastReceivedTime > timeoutInterval) {
    Serial.println("Timeout: Tidak ada data dari node pengirim!");
    esp2DataReceived = false;
  }

  sensors_event_t a1, g1, temp1;
  mpu1.getEvent(&a1, &g1, &temp1);

  float features[6] = {a1.acceleration.x, a1.acceleration.y, a1.acceleration.z};

  if (esp2DataReceived) {
    features[3] = dataESP2.ax;
    features[4] = dataESP2.ay;
    features[5] = dataESP2.az;

    // Normalisasi fitur sebelum klasifikasi
    normalizeFeatures(features);

    // Debug Data Normalisasi
    Serial.println("Fitur setelah normalisasi:");
    for (int i = 0; i < 6; i++) {
      Serial.print("Feature ");
      Serial.print(i);
      Serial.print(": ");
      Serial.println(features[i]);
    }

    // Hitung waktu komputasi
    unsigned long startTime = millis();

    DeadliftSVM svm;
    int predictedClass = svm.predict(features);

    unsigned long endTime = millis();
    unsigned long computationTime = endTime - startTime;

    // Tampilkan waktu komputasi
    Serial.print("Waktu komputasi (ms): ");
    Serial.println(computationTime);

    Serial.print("Predicted Class: ");
    Serial.println(predictedClass);

    // Logika buzzer berdasarkan hasil prediksi
    if (predictedClass == 0) { // Kelas "Benar"
      Serial.println("Posisi Awal BENAR!!");
      digitalWrite(BUZZER_PIN, HIGH);
      delay(1000);
      digitalWrite(BUZZER_PIN, LOW);
      delay(3000);
    } else if (predictedClass == 1) { // Kelas "Salah"
      Serial.println("Posisi Awal SALAH!!");
      digitalWrite(BUZZER_PIN, LOW);
      delay(500);
    } else if (predictedClass == 2) { // Kelas "Idle"
      Serial.println("Posisi Awal IDLE!!");
      digitalWrite(BUZZER_PIN, LOW);
      delay(500);
    }
  } else {
    Serial.println("Data dari node pengirim tidak diterima!");
  }
  delay(10);
}