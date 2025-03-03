# 📌 Sistem Wearable untuk Deteksi Postur Awal Deadlift Menggunakan MPU6050 dan SVM  

🚀 **Deskripsi Singkat**  
Sistem ini merupakan wearable device yang menggunakan sensor **MPU6050** untuk mendeteksi postur awal tubuh saat melakukan **conventional deadlift**. Data dari sensor diproses menggunakan **Support Vector Machine (SVM)** untuk menentukan apakah postur sudah benar atau perlu diperbaiki sebelum memulai angkatan.  

## 📖 Fitur  
✅ Mendeteksi postur awal deadlift secara real-time  
✅ Menggunakan sensor **MPU6050** pada **punggung atas, punggung tengah, dan paha**  
✅ Mengklasifikasikan postur menggunakan **Support Vector Machine (SVM)**  
✅ Memberikan feedback kepada pengguna untuk mencegah cedera  

## 📌 Arsitektur Sistem  
- **Hardware**:  
  - **ESP32** (Sebagai penerima & pemroses data)  
  - **MPU6050** (Sensor IMU untuk mendeteksi sudut tubuh)  
  - **Switch 3 Pin, TP4056, Baterai 18650** (Sistem daya)  
- **Software & Algoritma**:  
  - **Python** (Untuk pengolahan data & training SVM)  
  - **ESP-NOW** (Untuk komunikasi antar ESP32)  
  - **Machine Learning** (SVM untuk klasifikasi postur)  

## 📂 Struktur Direktori 
