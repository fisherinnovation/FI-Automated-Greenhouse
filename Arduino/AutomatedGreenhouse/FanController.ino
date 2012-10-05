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
 
 /**
 * Fan Controller
 *
 * Controls MOSFET gate with pin D4. Used to turn the fan system on and off.
 * Currently using 2 x 120mm computer case fans - 12VDC @ 0.5A. 
 * 
 * N-Channel MOSFET 60V 30A - https://www.sparkfun.com/products/10213
 *
 * TODO: Add variable speed control to the fans as well as RPM monitoring by adding connections 
 * to the two remaining pin outs from the fans.
 */
 
const int FanControlPin = 4; // Setup Fan Control MOSFET on pin D4
boolean FANS_ON = false;     // Used to monitor the status of the fans


/**
 * Setup the Fan Controller.
 */
void setupFanController() {
  Serial.println("> NOTICE: Activating Fan Control System...");
  pinMode(FanControlPin, OUTPUT);
  Serial.println("> NOTICE: Fan Control System Active!");
}

/**
 * Turn the fans on.
 */
void turnFanOn() {
  if(FANS_ON == true) return;
  
  FANS_ON = true;
  
  Serial.print("> NOTICE: Fans Active! ");
  Serial.print(" Temp: ");
  Serial.print(CURRENT_TEMP, DEC);
  Serial.print(" Humidity: ");
  Serial.println(CURRENT_HUMIDITY, DEC);
  
  digitalWrite(FanControlPin, HIGH);
}

/**
 * Turn the fans on.
 */
void turnFanOff() {
  if(FANS_ON == false) return;
  
  FANS_ON = false;
  
  Serial.print("> NOTICE: Fans Deactive!");
  Serial.print(" Temp: ");
  Serial.print(CURRENT_TEMP, DEC);
  Serial.print(" Humidity: ");
  Serial.println(CURRENT_HUMIDITY, DEC);
  
  digitalWrite(FanControlPin, LOW);
}

/**
 * Returns the current state of the fan system.
 */
boolean getFansActiveState() {
  return FANS_ON;
}
