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

class LightController(object):
	LightRelayPin = 8	# Lighting on pin D8.
	LIGHTS_ON = false	# Status of the lights.

	## Setup the Relay Controller.
	def __init__(self):
		print("> NOTICE: Activating 120VAC Lighting Relay System...")
	  
	  	io.setup(LightRelayPin, io.OUT)
		io.output(LightRelayPin, False)
	  	print("> NOTICE: Lighting System Active.")
	
	## Tests the light relays.
	def testLights(self):
		print("> NOTICE: Testing Relay #1..")  
		io.output(LightRelayPin, True)
		time.sleep(5);
		io.output(LightRelayPin, False)
		print("> NOTICE: Relay #1 Test Complete!")
		time.sleep(5);
	
	## Turns the lights on.
	def turnLightsOn(self):
		if(LIGHTS_ON == true):
			return

		LIGHTS_ON = true
		print("> NOTICE: Activating Lights")
		displayLCDMessage("Lighting System", "Activating", true, 1)
		io.output(LightRelayPin, True)
	
	## Turns the lights off.
	def turnLightsOff(self):
		if(LIGHTS_ON == false):
			return

		LIGHTS_ON = false
		print("> NOTICE: Deactivating Lights")
		displayLCDMessage("Lighting System", "Deactivaing", true, 1)
		io.output(LightRelayPin, False)

	## Returns the current active state of the lighting system.
	def getLightsActiveState(self):
		return LIGHTS_ON
