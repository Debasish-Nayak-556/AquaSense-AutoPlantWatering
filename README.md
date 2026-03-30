# 🌱 AquaSense — Automatic Plant Watering System

> Arduino-based smart irrigation system that monitors soil moisture in real time and automatically waters plants when needed — eliminating manual effort.

![Arduino](https://img.shields.io/badge/Arduino-Uno-00979D?style=for-the-badge&logo=arduino&logoColor=white)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![IDE](https://img.shields.io/badge/IDE-Arduino_IDE_2.x-teal?style=for-the-badge)
![Cost](https://img.shields.io/badge/Cost-~₹800-green?style=for-the-badge)
![Build Time](https://img.shields.io/badge/Build_Time-Under_1_Week-orange?style=for-the-badge)

---

## 🔍 Overview

Plants often suffer due to overwatering or underwatering. AquaSense solves this using automation:

Read Moisture → Compare Threshold → Pump ON/OFF → Repeat

### ✨ Features
- Real-time soil monitoring
- Automatic watering
- Auto shut-off
- Live Serial Monitor output
- LED indicator
- Configurable system

---

## 🔧 Hardware Components

- Arduino Uno
- Soil Moisture Sensor
- Relay Module
- Water Pump
- Battery
- Jumper Wires

---

## ⚡ Circuit Connections

A0 → Soil Sensor  
D7 → Relay  
D13 → LED  

---

## 💻 Software

- Arduino IDE
- C++

```cpp
const int SOIL_SENSOR_PIN = A0;
const int RELAY_PIN       = 7;
const int DRY_THRESHOLD   = 600;
const int PUMP_ON_TIME    = 5000;
const int CHECK_INTERVAL  = 3000;
```

---

## 🚀 How to Run

1. Install Arduino IDE  
2. Upload code  
3. Open Serial Monitor  

---

## 🎛️ Calibration

- Dry soil → ~700–900  
- Wet soil → ~200–400  

---

## 🔮 Future Improvements

- ESP32 WiFi control  
- OLED display  
- Temperature sensor  
- Solar power  

---

# 👨‍💻 Developer

Debasish  
IoT & Embedded Systems Enthusiast  

GitHub: https://github.com/Debasish-Nayak-556  
Email: dn193951@gmail.com  

---

⭐ Star this repo if you like it!
