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
#include "Adafruit_BMP085.h"
#include "CoCo-Barometer.h"
#include "CoCo-IMU.h"
#include "HTTPClient.h"
#include "SPI.h"
#include "Wire.h"
#include "initWifi.h"
#include "scanI2C.h"
#include <Arduino.h>
#include <MPU9250_WE.h>

//* CONSTANTS
#define WIFI_SSID "NGTelemetryNetwork"
#define WIFI_PASSWORD "99733940"
#define HTTP_ADDRESS "http://192.168.95.150:3001/api"
#define IMU_ADDRESS 0x68

//* OBJECTS
HTTPClient http;

MPU9250_WE MPU = MPU9250_WE(IMU_ADDRESS);
IMU imu(IMU_ADDRESS, 2000, MPU);

Adafruit_BMP085 e_Barometer;
Barometer barometer(e_Barometer);

//* GLOBAL VARIABLES

//* FUNCTIONS

void setup() {
	/* FIXME - http.begin(HTTP_ADDRESS); //! Don't forget to change IP
	http.addHeader("Content-Type", "application/json"); */

	Serial.begin(115200);
	Serial.println("Serial started.");

	Wire.begin(21, 22, 400000);
	delay(1000);

	scanner::scan();

	// Initialize WiFi
	// FIXME - Wifi::init(WIFI_SSID, WIFI_PASSWORD);

	// Initialize IMU
	imu.startIMU();

	// Initialize Barometer
	barometer.startBarometer();
}

void loop() {
	barometer.gatherData();
	barometer.printData();
	imu.gatherData();
	imu.plotValues();
}
