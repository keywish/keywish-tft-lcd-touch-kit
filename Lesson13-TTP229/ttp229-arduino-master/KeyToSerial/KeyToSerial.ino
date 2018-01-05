/***********************************************************************
 *       __                                                          _
 *      / /        _____  __    __  _          _   (_)   ________   | |
 *     / /____   / _____) \ \  / / | |   __   | |  | |  (  ______)  | |_____
 *    / / ___/  | |_____   \ \/ /  | |  /  \  | |  | |  | |______   |  ___  |
 *   / /\ \     | |_____|   \  /   | | / /\ \ | |  | |  (_______ )  | |   | |
 *  / /  \ \__  | |_____    / /    | |/ /  \ \| |  | |   ______| |  | |   | |
 * /_/    \___\  \______)  /_/      \__/    \__/   |_|  (________)  |_|   |_|
 *
 *
 * KeyWay Tech firmware
 *
 * Copyright (C) 2015-2020
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, in version 3.
 * learn more you can see <http://www.gnu.org/licenses/>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.
 *
 *
 * [Title]      TTP229 TouchPad
 * [Diagram]
 *         Arduino PIN 5V   ===================  TTP229 VCC
 *         Arduino PIN GND  ===================  TTP229 GND
 *         Arduino PIN 2    ===================  TTP229 SCL
 *         Arduino PIN 3    ===================  TTP229 SDO
 */
#include <TTP229.h>

const int SCL_PIN = 2;  // The pin number of the clock pin.
const int SDO_PIN = 3;  // The pin number of the data pin.

TTP229 ttp229(SCL_PIN, SDO_PIN); // TTP229(sclPin, sdoPin)

void setup()
{
	Serial.begin(115200);
	Serial.println("Start Touching One Key At a Time!");
}

void loop()
{
	uint8_t key = ttp229.ReadKey16(); // Blocking
	if (key) Serial.println(key);

//  uint8_t key = ttp229.GetKey16(); // Non Blocking
//  Serial.println(key);
}
