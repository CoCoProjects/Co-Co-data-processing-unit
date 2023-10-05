//* IMPORTS
#include <Arduino.h>
#include "WiFi.h"
#include "SPI.h"
#include "HTTPClient.h"

//* CONSTANTS
#define WIFI_SSID "NGTelemetryNetwork"
#define WIFI_PASSWORD "99733940"
#define HTTP_ADDRESS "http://192.168.95.150:3001/api"
#define INTEGRATED_IMU_ADDRESS 0x6A

//* OBJECTS
HTTPClient http;

//* GLOBAL VARIABLES

//* FUNCTIONS
void initWifi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.println("---------- Wifi initialization started ----------");
  Serial.println("Connecting to WiFi...");

  while(WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("Connected to WiFi!");
  Serial.println("IP Address: " + String(WiFi.localIP()));
  Serial.println("RSSI:" + String(WiFi.RSSI()) + "dBm");

  Serial.println("---------- WiFi initialization finished ----------");
  delay(1000);
}

void setup() {
  http.begin(HTTP_ADDRESS); //! Don't forget to change IP
	http.addHeader("Content-Type", "application/json");

	Serial.begin(115200);
	Serial.println("Serial started.");

  // Initialize WiFi
  initWifi();
}

void loop() {
}
