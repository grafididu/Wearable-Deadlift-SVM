#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_MPU6050.h>
#include <esp_now.h>
#include <WiFi.h>

Adafruit_MPU6050 mpu;

// Ganti dengan alamat MAC penerima
uint8_t receiverAddress[] = {0xFC, 0xE8, 0xC0, 0x79, 0x62, 0xB8};

typedef struct sensor_data {
  float ax;
  float ay;
  float az;
  float gx;
  float gy;
  float gz;
} sensor_data;

sensor_data myData;
esp_now_peer_info_t peerInfo;

// Callback saat data dikirim
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nStatus Pengiriman Paket Terakhir:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Success" : "Failed");
}

void setup() {
  // Memulai Serial Monitor
  Serial.begin(115200);
  
  // Inisialisasi I2C
  Wire.begin();
  
  // Inisialisasi sensor MPU6050
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chips");
    while (1) {
      delay(10);
    }
  }
  
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  
  // Inisialisasi WiFi dalam mode Station
  WiFi.mode(WIFI_STA);
  
  // Inisialisasi ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  // Registrasi callback untuk status pengiriman data
  esp_now_register_send_cb(OnDataSent);
  
  // Menambahkan peer (penerima)
  memcpy(peerInfo.peer_addr, receiverAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;
  
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Gagal menambahkan peer");
    return;
  }
}

void loop() {
  // Mendapatkan data dari sensor
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  
  // Menyimpan data akselerometer dan giroskop ke struktur data
  myData.ax = a.acceleration.x;
  myData.ay = a.acceleration.y;
  myData.az = a.acceleration.z;
  myData.gx = g.gyro.x;
  myData.gy = g.gyro.y;
  myData.gz = g.gyro.z;
  
  // Mengirim data ke penerima
  esp_err_t result = esp_now_send(receiverAddress, (uint8_t *)&myData, sizeof(myData));
  
  // Jeda sebelum pembacaan berikutnya
  delay(100);
}