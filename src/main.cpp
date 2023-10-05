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

//* IMPORTS
#include <Arduino.h>
#include "initWifi.h"
#include "SPI.h"
#include "HTTPClient.h"
#include <Deneyap_6EksenAtaletselOlcumBirimi.h>
#include "CoCo-IMU.h"

//* CONSTANTS
#define WIFI_SSID "NGTelemetryNetwork"
#define WIFI_PASSWORD "99733940"
#define HTTP_ADDRESS "http://192.168.95.150:3001/api"
#define INTEGRATED_IMU_ADDRESS 0x6A

//* OBJECTS
HTTPClient http;
LSM6DSM i_IMU;
IMU imu(INTEGRATED_IMU_ADDRESS, 2000, i_IMU);

//* GLOBAL VARIABLES

//* FUNCTIONS

void setup() {
  http.begin(HTTP_ADDRESS); //! Don't forget to change IP
	http.addHeader("Content-Type", "application/json");

	Serial.begin(115200);
	Serial.println("Serial started.");

  // Initialize WiFi
  Wifi::init(WIFI_SSID, WIFI_PASSWORD);
}

void loop() {
}
