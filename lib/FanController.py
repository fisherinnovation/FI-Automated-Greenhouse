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

#import RPi.GPIO as io
#io.setmode(io.BCM) 

class FanController(object):
    FANS_ON = False         # Used to monitor the status of the fans    
    CONFIGURATION = False   #
    

    def __init__(self, conf):
        ''' Initialize LightController. '''

        print("> NOTICE: Activating Fan Control System...")

        CONFIGURATION = conf

        #io.setup(CONFIGURATION.FAN_CONTROL_PIN, io.OUT)
        #io.output(CONFIGURATION.FAN_CONTROL_PIN, False)

        print("> NOTICE: Fan Control System Active!")


    def turnFanOn(self):
        ''' Turn the fans on. '''

        if(FANS_ON == True): 
            return
      
        FANS_ON = True
      
        print("> NOTICE: Fans Active! ")
        print(" Temp: ")
        print(CURRENT_TEMP, DEC)
        print(" Humidity: ")
        print(CURRENT_HUMIDITY, DEC)
      
        io.output(FanControlPin, True)
    

    def turnFanOff(self):
        ''' Turn the fans on. '''

        if(FANS_ON == False): return
      
        FANS_ON = False
      
        print("> NOTICE: Fans Deactive!")
        print(" Temp: ")
        print(CURRENT_TEMP, DEC)
        print(" Humidity: ")
        print(CURRENT_HUMIDITY, DEC)
      
        io.output(FanControlPin, False)
    

    def getFansActiveState(self):
        ''' Returns the current state of the fan system. '''

        return FANS_ON
