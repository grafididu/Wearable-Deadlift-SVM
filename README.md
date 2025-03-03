# 📌 Wearable System for Initial Posture Detection in Deadlifts Using MPU6050 and SVM  

🚀 **Project Overview**  
This project is a **wearable device** that uses an **MPU6050** sensor to detect the initial posture of the body before performing a **conventional deadlift**. The sensor data is processed using a **Support Vector Machine (SVM)** model to determine whether the posture is correct or needs adjustment to prevent injuries.  

## 📖 Features  
✅ Real-time initial deadlift posture detection  
✅ Uses **MPU6050** sensors placed on the **upper back, mid-back, and thigh**  
✅ Classifies posture using **Support Vector Machine (SVM)**  
✅ Provides feedback to users to prevent injuries  

## 📌 System Architecture  
- **Hardware**:  
  - **ESP32** (Acts as both receiver & processor)  
  - **MPU6050** (IMU sensor for angle detection)
  - **Buzzer** (Output)
  - **3-Pin Switch, 18650 Battery Shield V3, 18650 Battery** (Power system)  
- **Software & Algorithms**:  
  - **Python** (For data processing & SVM training)  
  - **ESP-NOW** (For ESP32 communication)  
  - **Support Vector Machine** (Machine for posture classification)  
