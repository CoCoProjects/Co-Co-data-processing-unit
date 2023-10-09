/************************************************************************
																																				Source
Code Form License Notice
																								-------------------------------------------

	This Source Code Form is subject to the terms of the Mozilla Public
	License, v. 2.0. If a copy of the MPL was not distributed with this
	file, You can obtain one at http://mozilla.org/MPL/2.0/.

If it is not possible or desirable to put the notice in a particular
file, then You may include the notice in a location (such as a LICENSE
file in a relevant directory) where a recipient would be likely to look
for such a notice.
*************************************************************************/

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