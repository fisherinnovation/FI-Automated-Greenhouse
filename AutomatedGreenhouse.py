#!/usr/bin/env python

##
# Fisher Innovation Automated Greenhouse Controller
# @author Matt Fisher (Fisher Innovation - http://fisherinnovation.com) [fisher.matt@gmail.com]
#
# Copyright (c) 2013 Fisher Innovation
# Licensed the MIT license.
#
# http://www.fisherinnovation.com
# https://github.com/fisherinnovation/FI-Automated-Greenhouse
##

import time
import sys
import os
#import RPi.GPIO as io 
#io.setmode(io.BCM)
sys.path.append('conf')
import Configuration
sys.path.append('lib')
import LightController
import FanController
import TemperatureController
import WaterController
sys.path.append('lib/db')
import MySQL
import re

class AutomatedGreenhouse():
  CONFIGURATION = False
  DATABASE = False
  LIGHTCONTROLLER = False
  FANCONTROLLER = False
  TEMPERATURECONTROLLER = False
  WATERCONTROLLER = False
 
  def __init__(self):
    ''' Application Setup '''

    # Clear screen on application instantiation.
    if os.name == 'nt':
      os.system('cls')    # Windows
    else:
      os.system('clear')  # Linux / OSX

    print("--------------------------------------------------------")
    print("Fisher Innovation - Automated Greenhouse Controller")
    print("Created By: Matt Fisher <fisher.matt@gmail.com>")
    print("https://github.com/fisherinnovation/FI-Automated-Greenhouse")
    print("--------------------------------------------------------")
    print("")
    #print("> NOTICE: Activating system...")

    #inpput = raw_input(">")
    #print inpput
    
    self.CONFIGURATION = Configuration.Configuration()
    self.DATABASE = MySQL.MySQL(self.CONFIGURATION)

    # Init controllers
    self.LIGHTCONTROLLER = LightController.LightController(self.CONFIGURATION)
    self.FANCONTROLLER = FanController.FanController(self.CONFIGURATION)
    self.WATERCONTROLLER = WaterController.WaterController(self.CONFIGURATION)
    self.TEMPERATURECONTROLLER = TemperatureController.TemperatureController(self.CONFIGURATION)
    
    print("> NOTICE: System Startup Complete.")
    print("> NOTICE: Greenhouse Startup Complete!")

    #self.mainLoop()


  def mainLoop(self):
    ''' Main Application Loop. '''

    # Read Water Flow Values
    self.WATERCONTROLLER.readFlowSensor()

    # Read Internal Greenhouse Temperature and Humidity
    self.TEMPERATURECONTROLLER.readGreenhouseTemperature()
    self.TEMPERATURECONTROLLER.readWaterTemperature()

    # Water Temperature Checks
    self.TEMPERATURECONTROLLER.regulateWaterTemperature()

    '''
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
    '''

greenhouse = AutomatedGreenhouse()