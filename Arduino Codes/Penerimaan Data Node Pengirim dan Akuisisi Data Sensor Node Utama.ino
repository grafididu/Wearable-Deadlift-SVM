#include <esp_now.h>
#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_BusIO_Register.h>

Adafruit_MPU6050 mpu1;

// Alamat MAC ESP2
uint8_t esp2Address[] = {0xFC, 0xE8, 0xC0, 0x79, 0x21, 0x5C};

// Struktur untuk menerima data
typedef struct sensor_data {
  float ax;
  float ay;
  float az;
  float gx;
  float gy;
  float gz;
} sensor_data;

sensor_data dataESP2;
bool esp2DataReceived = false;

// Fungsi callback yang akan dieksekusi saat data diterima
void OnDataRecv(const esp_now_recv_info *info, const uint8_t *incomingData, int len) {
  if (memcmp(info->src_addr, esp2Address, 6) == 0) {
    memcpy(&dataESP2, incomingData, sizeof(dataESP2));
    esp2DataReceived = true;
  }
}

void setup() {
  Wire.begin();
  Serial.begin(115200);
  
  WiFi.mode(WIFI_STA);
  
  if (!mpu1.begin()) {
    Serial.println("Failed to find MPU6050 chips");
    while (1) {
      delay(10);
    }
  }
  
  Serial.println("MPU6050 Found!!");
  mpu1.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu1.setGyroRange(MPU6050_RANGE_500_DEG);
  
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  // Mendaftarkan callback untuk menerima data
  esp_now_register_recv_cb(OnDataRecv);
}

void loop() {
  sensors_event_t a1, g1, temp1;
  mpu1.getEvent(&a1, &g1, &temp1);
  
  Serial.print("[");
  
  // Cetak data dari sensor lokal - NODE MAIN (PUNGGUNG BAWAH)
  Serial.print(a1.acceleration.x);
  Serial.print(", ");
  Serial.print(a1.acceleration.y);
  Serial.print(", ");
  Serial.print(a1.acceleration.z);
  Serial.print(", ");
  Serial.print(g1.gyro.x);
  Serial.print(", ");
  Serial.print(g1.gyro.y);
  Serial.print(", ");
  Serial.print(g1.gyro.z);
  
  // Cetak data dari pengirim (dataESP2)
  Serial.print(", ");
  Serial.print(dataESP2.ax);
  Serial.print(", ");
  Serial.print(dataESP2.ay);
  Serial.print(", ");
  Serial.print(dataESP2.az);
  Serial.print(", ");
  Serial.print(dataESP2.gx);
  Serial.print(", ");
  Serial.print(dataESP2.gy);
  Serial.print(", ");
  Serial.print(dataESP2.gz);
  
  Serial.println("]");
  delay(100);
}