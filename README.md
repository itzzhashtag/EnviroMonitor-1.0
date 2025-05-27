<div align="center">

# 🌡️💨 EnviroMonitor-1.0 🏠  
**by [Aniket Chowdhury](mailto:micro.aniket@gmail.com) (aka `#Hashtag`)**

<img src="https://img.shields.io/badge/Status-Working-brightgreen?style=for-the-badge&logo=arduino" alt="Status Badge" />
<img src="https://img.shields.io/badge/Built%20with-Arduino-blue?style=for-the-badge&logo=arduino" alt="Arduino Badge" />
<img src="https://img.shields.io/badge/License-Personal--Use-orange?style=for-the-badge" alt="License Badge" />

</div>

---

## 🧠 Overview

This project is a **DIY Smart Room Environment Monitor** that checks:

- 🌡️ Temperature
- 💧 Humidity
- ☣️ Air Quality (PPM)
- 📟 Dual LCD feedback
- 🔴🟢🔵 RGB LED indicators for instant visual alerts

It uses **DHT22**, **MQ135**, **I2C LCDs**, and **custom pixel icons** to make data both informative and fun!

---

## 🔋 Hardware Used

| 🧩 Component       | 🔢 Qty | 📘 Notes                            |
|-------------------|--------|-------------------------------------|
| Arduino UNO/Nano  | 1      | Main microcontroller                |
| DHT22             | 1      | Humidity + Temperature Sensor       |
| MQ135             | 1      | Gas/Air Quality Sensor              |
| I2C 16x2 LCD      | 2      | For displaying PPM & Humidity       |
| RGB LEDs          | 3      | Status colors (R, G, B)             |
| Resistors         | 3      | For LEDs                            |
| Breadboard        | 1      | Optional for prototyping            |
| Jumper Wires      | Several| Connections                         |

---

## 🔌 Pin Configuration

| Device   | Arduino Pin |
|----------|-------------|
| DHT22    | D7          |
| MQ135    | A0          |
| Red LED  | D9          |
| Green LED| D10         |
| Blue LED | D11         |
| LCD #1 (I2C: 0x27) | SDA/SCL |
| LCD #2 (I2C: 0x23) | SDA/SCL |

📝 _Check and modify I2C addresses in the code if necessary._

---

## 📊 Sensor Thresholds

| Air Quality (PPM) | Description     | LED Color |
|-------------------|-----------------|-----------|
| `< 60`            | ✅ Good          | 🟢 Green  |
| `60 - 120`        | ⚠️ Moderate      | 🔵 Blue   |
| `> 120`           | 🚨 Dangerous     | 🔴 Red    |

---

## 🛠️ Libraries Used

- `DHT.h` → For reading temperature and humidity
- `LiquidCrystal_I2C.h` → For I2C LCDs
- `Wire.h` → I2C communication

📦 Install via **Arduino Library Manager**.

---

## 👤 Author & Contact

👨 **Name:** Aniket Chowdhury (aka Hashtag)  
📧 **Email:** [micro.aniket@gmail.com](mailto:micro.aniket@gmail.com)  
💼 **LinkedIn:** [itzz-hashtag](https://www.linkedin.com/in/itzz-hashtag/)  
🐙 **GitHub:** [itzzhashtag](https://github.com/itzzhashtag)  
📸 **Instagram:** [@itzz_hashtag](https://instagram.com/itzz_hashtag)

---

## 🖼️ Live Demo & Images

> 🖼️ Add your project images here!

```bash
📟 LCD1: Shows Temperature & Humidity
📟 LCD2: Displays Air Quality (PPM)
