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
 
##
# Fan Controller
#
# Controls MOSFET gate with pin D4. Used to turn the fan system on and off.
# Currently using 2 x 120mm computer case fans - 12VDC @ 0.5A. 
# 
# N-Channel MOSFET 60V 30A - https://www.sparkfun.com/products/10213
#
# TODO: Add variable speed control to the fans as well as RPM monitoring by adding connections 
# to the two remaining pin outs from the fans.
##

import RPi.GPIO as io
io.setmode(io.BCM) 

class FanController(object):
    FanControlPin = 4;  # Setup Fan Control MOSFET on pin D4
    FANS_ON = false;    # Used to monitor the status of the fans    

    ##
    # Initialize LightController.
    ##
    def __init__(self):
        print("> NOTICE: Activating Fan Control System...")
        io.setup(FanControlPin, io.OUT)
        io.output(FanControlPin, False)
        print("> NOTICE: Fan Control System Active!")

    ## Turn the fans on.
    def turnFanOn(self):
        if(FANS_ON == true) return
      
        FANS_ON = true
      
        print("> NOTICE: Fans Active! ")
        print(" Temp: ")
        print(CURRENT_TEMP, DEC)
        print(" Humidity: ")
        print(CURRENT_HUMIDITY, DEC)
      
        io.output(FanControlPin, True)
    
    ## Turn the fans on.
    def turnFanOff(self):
        if(FANS_ON == false) return
      
        FANS_ON = false
      
        print("> NOTICE: Fans Deactive!")
        print(" Temp: ")
        print(CURRENT_TEMP, DEC)
        print(" Humidity: ")
        print(CURRENT_HUMIDITY, DEC)
      
        io.output(FanControlPin, False)
    
    ## Returns the current state of the fan system.
    def getFansActiveState(self):
      return FANS_ON
