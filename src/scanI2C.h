#include "Wire.h"

namespace scanner {

void scan() {
	byte start_address = 0;
	byte end_address = 127;

	byte rc;

	Serial.print("Scanning I2C bus from ");
	Serial.print(start_address, DEC);
	Serial.print(" to ");
	Serial.print(end_address, DEC);
	Serial.println("...");

	for (byte addr = start_address;
			 addr <= end_address;
			 addr++) {
		Wire.beginTransmission(addr);
		rc = Wire.endTransmission();

		if (addr < 16)
			Serial.print("0");
		Serial.print(addr, HEX);
		if (rc == 0) {
			Serial.print(" found!");
		} else {
			Serial.print(" ");
			Serial.print(rc);
			Serial.print("     ");
		}
		Serial.print((addr % 8) == 7 ? "\n" : " ");
	}

	Serial.println("\n-------------------------------\nPossible devices:");

	for (byte addr = start_address;
			 addr <= end_address;
			 addr++) {
		Wire.beginTransmission(addr);
		rc = Wire.endTransmission();
		if (rc == 0) {
			Serial.print(addr, HEX);
			Serial.print(" = ");
			switch (addr) {
			case 0x77:
				Serial.println("BMP180");
				break;
			case 0x69:
				Serial.println("MPU9250");
				break;
			default:
				Serial.println("Unknown");
				break;
			}
		}
	}

	Serial.println("\ndone");
}
} // namespace scanner