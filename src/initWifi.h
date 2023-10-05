#include "WiFi.h"
#include <Arduino.h>

namespace Wifi {
void init(String ssid, String password) {
	WiFi.mode(WIFI_STA);
	WiFi.begin(ssid, password);

	Serial.println("---------- Wifi initialization started ----------");
	Serial.println("Connecting to WiFi...");

	while (WiFi.status() != WL_CONNECTED) {
		Serial.print(".");
		delay(500);
	}

	Serial.println("Connected to WiFi!");
	Serial.println("IP Address: " + String(WiFi.localIP()));
	Serial.println("RSSI:" + String(WiFi.RSSI()) + "dBm");

	Serial.println("---------- WiFi initialization finished ----------");
	delay(1000);
}
} // namespace Wifi