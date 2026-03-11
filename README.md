# ESP32 People Counter with IR Sensor (PBL Project)

This project is a **people counting system using ESP32 and an IR sensor**.
The ESP32 runs a **web server** that shows the number of people detected in real time through a simple web page.

This project was developed as part of my **College PBL (Project Based Learning)**.

---

## 🛠️ Technologies Used

* ESP32
* IR Sensor
* Arduino IDE
* WiFi (ESP32 Web Server)

---

## ⚙️ Features

* Detects people using an **IR sensor**
* Counts the number of people passing the sensor
* Displays the **live count on a web page**
* Web page **auto refresh every 5 seconds**
* **Reset button** to clear the counter
* Debounce logic to prevent multiple counts for one person

---

## 📂 Project Structure

```
ESP32-People-Counter/
│
├── sad2.ino
└── README.md
```

---

## 🔌 Hardware Required

* ESP32 Development Board
* IR Sensor Module
* Jumper Wires
* USB Cable

---

## 🔗 Circuit Connection

IR Sensor → ESP32

* VCC → 3.3V
* GND → GND
* OUT → GPIO 15

---

## 🚀 How It Works

1. ESP32 connects to WiFi.
2. IR sensor detects when a person passes.
3. The counter increases when the sensor is triggered.
4. ESP32 hosts a **web page showing the current people count**.
5. The page refreshes every 5 seconds to show updated values.
6. The **Reset button** clears the counter.

---

## 👨‍💻 Author

Prabhakaran

