/**
 * Fisher Innovation Automated Greenhouse Controller
 * @author Matt Fisher (Fisher Innovation) [fisher.matt@gmail.com]
 *
 * Copyright (c) 2012 Fisher Innovation
 * Licensed the MIT license.
 *
 * http://www.fisherinnovation.com
 * https://github.com/fisherinnovation/FI-Automated-Greenhouse
 */

#include <Wire.h>
#include "RTClib.h" // DS1307 Real Time Clock.
#include <DHT22.h>  // DHT22 Temperature and Humidity Sensor.
#include <stdio.h>  // Only used for sprintf.

#include <Arduino.h>
#include <Time.h>
#include <SoftwareSerial.h>
#include <Streaming.h>
#include <PString.h>
#include <WiFlySerial.h>
#include "Credentials.h"
#include "MemoryFree.h"

#define DHT22_PIN 7     // DHT22 Temperature and Humidity Sensor to pin D7.

DHT22 myDHT22(DHT22_PIN); // Setup a DHT22 instance.
RTC_Millis RTC;           // Setup a DS1307 instance.

int CURRENT_TEMP = 0;      // Global reference to the current system temperature. 
int CURRENT_HUMIDITY = 0;  // Global reference to the current system humidity.
int CURRENT_TIME[3];       // Global reference to the current system date.
int CURRENT_DATE[3];       // Global reference to the current system time.
int WIFI_LOG_INTERVAL = 0;

/***********************************************************************************/

/* System Configuration */
// Temperature Configuration
const int MAX_GREENHOUSE_TEMP = 26; // Maximum greenhouse temperature.

// Humidity Configuration
const int MAX_GREENHOUSE_HUMIDITY = 70; // Maximum greenhouse humidity (as percentage)

// Lighting Configuration
const int LIGHTS_ON_TIME = 12; // What hour (24h format) to turn the lights on. (-1 = 24h lights on).

// LCD Display Configuration
const boolean LCD_ENABLED = true; // Enable or disable the use of a LCD on Serial1.

// Serial Communications Configuration
const int SERIAL_BAUD_RATE = 9600;  // Serial baud rate for external debug connections (USB).
const int LCD_BAUD_RATE = 9600;     // Serial baud rate for connected LCD display (default 9600 baud).

// Wifi Configuration
const int WIFI_BAUD_RATE = 9600;
const char WIFI_PASSPHRASE[] = "passphrase";
const char WIFI_SSID[] = "ssid";

/***********************************************************************************/

/**
 * Application Setup
 */
void setup () {
  Serial.begin(SERIAL_BAUD_RATE);  // Serial communications
  Serial1.begin(LCD_BAUD_RATE);    // LCD Display
  
  Serial.println("--------------------------------------------------------");
  Serial.println("Fisher Innovation - Automated Greenhouse Controller");
  Serial.println("Created By: Matt Fisher <fisher.matt@gmail.com>");
  Serial.println("https://github.com/fisherinnovation/FI-Automated-Greenhouse");
  Serial.println("--------------------------------------------------------");
  Serial.println("");
  Serial.println("> NOTICE: Activating system...");
  
  displayLCDMessage("     Fisher     ", "   Innovation   ", true, 1); 
  displayLCDMessage("   Automated    ", "   Greenhouse   ", true, 1); 
  
  // Following line sets the RTC to the date & time this sketch was compiled.
  // Note: Comment out this after initial setting of time on the RTC.
  //Serial.println("> NOTICE: Setting System Date and Time...");
  RTC.begin(DateTime(__DATE__, __TIME__));
  
  // Init controllers
  //setupWifiController();   // Wifi controller
  setupLightController();  // Light controller
  setupFanController();    // Fan controller
  
  Serial.println("> NOTICE: System Startup Complete.");
  Serial.println("> NOTICE: Greenhouse Startup Complete!");
}

/**
 * System Loop.
 */
void loop() {
  checkSerialInput(); // Check for serial input.
  updateLCDDisplay(); // Update the LCD display.
  
  mainLoop();
}

/**
 * Main Application Loop
 */
void mainLoop() {
  // Update the clock values.
  readDS1307();
  
  // Aquire the latest DHT22 dataset (temperature & humidity).
  // Calling this method will result in the 'CURRENT_TEMP' and 'CURRENT_HUMIDITY' 
  // varibles to be updated. The sensor also requires a cool down time which will
  // result in a 2 second delay during the call.
  getDHT22Data();
  
  // Check if the system temperature is higher then configured. 
  if(CURRENT_TEMP > MAX_GREENHOUSE_TEMP) {
    // Temperature is too high.
    // Make sure fans are on.
    turnFanOn();
  } else {
    // Temperature is at a stable reading.
    if(CURRENT_HUMIDITY > MAX_GREENHOUSE_HUMIDITY) {
      turnFanOn(); // Humidity is too high. Make sure fans are on.
    } else {
      turnFanOff(); // Humidity is at a stable reading. Make sure fans are off.
    }
  }
  
  // Check lighting system conditions.
  // Check if it is time to turn on the lights.
  if(CURRENT_TIME[0] >= LIGHTS_ON_TIME) {
    turnLightsOn(); // Turn lights on.
  } else {
    turnLightsOff(); // Turn lights off.
  }
  
  // Wifi
  WIFI_LOG_INTERVAL++;
  if(WIFI_LOG_INTERVAL == 100) {
    Serial.println("Attempting to log data over wifi..."); 
    logSystemData();
    WIFI_LOG_INTERVAL = 0;
  }
}
