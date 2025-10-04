# ESP32-People-Counter-with-IR-Sensor-and-Web-Interface
"ESP32-based people counting system using an IR sensor with a real-time web interface to monitor and reset the count."


ESP32 People Counter with IR Sensor and Web Interface

This project implements a people counting system using an ESP32 and an IR sensor, with a simple web interface to monitor and reset the count. The ESP32 hosts a web server that shows the number of people detected in real-time.

Features

Counts people passing through an IR sensor.

Real-time display of the count via a web interface.

Automatic page refresh every 5 seconds.

Reset the count from the web page.

Debounce logic to avoid multiple counts for a single person.

Components Required

ESP32 Development Board

IR Sensor (e.g., IR obstacle sensor module)

Jumper wires

USB cable for programming and power

Circuit Diagram
IR Sensor VCC  -->  3.3V on ESP32
IR Sensor GND  -->  GND on ESP32
IR Sensor OUT  -->  GPIO 15 on ESP32


Installation

Clone this repository:
git clone https://github.com/your-username/esp32-people-counter.git
cd esp32-people-counter
Open in Arduino IDE or VS Code with PlatformIO.

Install required libraries:

WiFi.h (comes with ESP32 boards in Arduino IDE)

WebServer.h (comes with ESP32 boards in Arduino IDE)

Update WiFi credentials in the sketch.ino file:

const char* ssid = "YourWiFiSSID";
const char* password = "YourWiFiPassword";

Upload the code to your ESP32 board.

How to Use

Connect the ESP32 to power and ensure the IR sensor is correctly wired.

Open the Serial Monitor to see the WiFi connection status and IP address.

Open a browser and navigate to the ESP32 IP address (e.g., http://192.168.1.123).

The web page displays the current number of people detected.

Click Reset Counter to reset the count.
