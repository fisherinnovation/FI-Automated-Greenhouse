#!/usr/bin/env python

##
# Fisher Innovation Automated Greenhouse Controller
# @author Matt Fisher (Fisher Innovation) [fisher.matt@gmail.com]
#
# Copyright (c) 2013 Fisher Innovation
# Licensed the MIT license.
#
# http:#www.fisherinnovation.com
# https:#github.com/fisherinnovation/FI-Automated-Greenhouse
##

import time 
import RPi.GPIO as io 
io.setmode(io.BCM)
sys.path.append('lib/LightController')
import Configuration

#DHT22 myDHT22(DHT22_PIN); # Setup a DHT22 instance.
#RTC_Millis RTC;           # Setup a DS1307 instance.

class AutomatedGreenhouse(): 
  CURRENT_TEMP = 0;      # Global reference to the current system temperature. 
  CURRENT_HUMIDITY = 0;  # Global reference to the current system humidity.
  CURRENT_TIME[3];       # Global reference to the current system date.
  CURRENT_DATE[3];       # Global reference to the current system time.
  WIFI_LOG_INTERVAL = 0;

  ##########################################################################################

  ## System Configuration
  # Temperature Configuration
  MAX_GREENHOUSE_TEMP = 26; # Maximum greenhouse temperature.

  # Humidity Configuration
  MAX_GREENHOUSE_HUMIDITY = 70; # Maximum greenhouse humidity (as percentage)

  # Lighting Configuration
  LIGHTS_ON_TIME = 12; # What hour (24h format) to turn the lights on. (-1 = 24h lights on).

  # LCD Display Configuration
  LCD_ENABLED = true; # Enable or disable the use of a LCD on Serial1.

  # Serial Communications Configuration
  SERIAL_BAUD_RATE = 9600;  # Serial baud rate for external debug connections (USB).
  LCD_BAUD_RATE = 9600;     # Serial baud rate for connected LCD display (default 9600 baud).

  ##########################################################################################

  ## Application Setup
  def __init__(self):
    #Serial.begin(SERIAL_BAUD_RATE);  # Serial communications
    #Serial1.begin(LCD_BAUD_RATE);    # LCD Display
    
    print("--------------------------------------------------------")
    print("Fisher Innovation - Automated Greenhouse Controller")
    print("Created By: Matt Fisher <fisher.matt@gmail.com>")
    print("https:#github.com/fisherinnovation/FI-Automated-Greenhouse")
    print("--------------------------------------------------------")
    print("");
    print("> NOTICE: Activating system...");
    
    # Following line sets the RTC to the date & time this sketch was compiled.
    # Note: Comment out this after initial setting of time on the RTC.
    #print("> NOTICE: Setting System Date and Time...");
    #RTC.begin(DateTime(__DATE__, __TIME__));
    
    # Init controllers
    setupLightController()  # Light controller
    setupFanController()    # Fan controller
    
    print("> NOTICE: System Startup Complete.")
    print("> NOTICE: Greenhouse Startup Complete!")


  ## System Loop.
  def loop(self):
    checkSerialInput() # Check for serial input.
    updateLCDDisplay() # Update the LCD display.
    mainLoop()

  ## Main Application Loop
  def mainLoop(self):
    # Update the clock values.
    readDS1307()
    
    # Aquire the latest DHT22 dataset (temperature & humidity).
    # Calling this method will result in the 'CURRENT_TEMP' and 'CURRENT_HUMIDITY' 
    # varibles to be updated. The sensor also requires a cool down time which will
    # result in a 2 second delay during the call.
    getDHT22Data()
    
    # Check if the system temperature is higher then configured. 
    if(CURRENT_TEMP > MAX_GREENHOUSE_TEMP):
      # Temperature is too high.
      # Make sure fans are on.
      turnFanOn()
    else:
      # Temperature is at a stable reading.
      if(CURRENT_HUMIDITY > MAX_GREENHOUSE_HUMIDITY):
        turnFanOn() # Humidity is too high. Make sure fans are on.
      else:
        turnFanOff() # Humidity is at a stable reading. Make sure fans are off.
    
    # Check lighting system conditions.
    # Check if it is time to turn on the lights.
    if(CURRENT_TIME[0] >= LIGHTS_ON_TIME):
      turnLightsOn() # Turn lights on.
    else:
      turnLightsOff() # Turn lights off.

    # Wifi
    WIFI_LOG_INTERVAL++;
    if(WIFI_LOG_INTERVAL == 100):
      print("Attempting to log data over wifi...") 
      logSystemData()
      WIFI_LOG_INTERVAL = 0
  

greenhouse = AutomatedGreenhouse()