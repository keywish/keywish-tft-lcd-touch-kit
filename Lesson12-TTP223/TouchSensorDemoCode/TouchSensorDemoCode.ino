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
 * [Title]      TTP223 TouchSensor
 * [Diagram]
 *         Arduino PIN 3     ===================  TTP223 PIN SIG
 *         Arduino PIN 5V    ===================  TTP223 PIN VCC
 *         Arduino PIN GND   ===================  TTP223 PIN GND
 *         Arduino PIN 2     ===================  LED PIN 5V
 *         Arduino PIN GND   ===================  LED PIN GND
 */
#define TOUCH_SENSOR 3//the touch sensor is connected with D3 of Arduino/Catduino
#define BUZZER 2//the buzzer is connected with D2 of Arduino/Catduino
void setup() {
  Serial.begin(115200);
  pinMode(TOUCH_SENSOR, INPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  int sensorValue = digitalRead(TOUCH_SENSOR);
  if(sensorValue)
  {
    Serial.println("Touch");
    digitalWrite(BUZZER,HIGH);
    delay(40);
    digitalWrite(BUZZER,LOW);
    while(digitalRead(TOUCH_SENSOR) == HIGH);
    Serial.println("Nobody touch");
  }
}



