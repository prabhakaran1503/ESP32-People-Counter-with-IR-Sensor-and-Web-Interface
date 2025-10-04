#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "YourWiFiSSID";
const char* password = "YourWiFiPassword";

WebServer server(80);

const int irSensorPin = 15;
int peopleCount = 0;
bool lastState = HIGH;
bool currentState;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  Serial.begin(115200);
  pinMode(irSensorPin, INPUT_PULLUP);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\nWiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/count", handleCount);
  server.on("/reset", handleReset);
  
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
  
  int reading = digitalRead(irSensorPin);
  
  if (reading != lastState) {
    lastDebounceTime = millis();
  }
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != currentState) {
      currentState = reading;
      if (currentState == LOW) {
        peopleCount++;
        Serial.print("People count: ");
        Serial.println(peopleCount);
      }
    }
  }
  
  lastState = reading;
  delay(10);
}

void handleRoot() {
  String html = "<!DOCTYPE html><html><head><title>People Counter</title>";
  html += "<meta http-equiv=\"refresh\" content=\"5\">";
  html += "<style>body {font-family: Arial, sans-serif; text-align: center; margin-top: 50px;}";
  html += "h1 {color: #444;} .count {font-size: 48px; color: #2c3e50; font-weight: bold;}";
  html += "button {background-color: #e74c3c; color: white; border: none; padding: 10px 20px;";
  html += "border-radius: 5px; cursor: pointer; font-size: 16px; margin-top: 20px;}</style></head>";
  html += "<body><h1>People Counter System</h1>";
  html += "<p>Current number of people inside:</p>";
  html += "<div class=\"count\">" + String(peopleCount) + "</div>";
  html += "<p><small>(Use webcam to verify actual count)</small></p>";
  html += "<button onclick=\"window.location.href='/reset'\">Reset Counter</button>";
  html += "</body></html>";
  
  server.send(200, "text/html", html);
}

void handleCount() {
  server.send(200, "text/plain", String(peopleCount));
}

void handleReset() {
  peopleCount = 0;
  server.sendHeader("Location", "/");
  server.send(303);
}
