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

import sys
import time
sys.path.append('conf')
import Configuration
#import RPi.GPIO as io
#io.setmode(io.BCM)

class LightController(object):
	LIGHTS_ON = False		# Status of the lights.
	CONFIGURATION = False 	# Reference to the global configuration.

	
	def __init__(self, conf):
		''' Setup the Relay Controller. '''

		print("> NOTICE: Activating Light Controller...")
	  	
	  	self.CONFIGURATION = conf

	  	#io.setup(self.CONFIGURATION.LIGHT_RELAY_PIN, io.OUT)
		#io.output(self.CONFIGURATION.MAX_GREENHOUSE_TEMP, False)
	  	
	  	print("> NOTICE: Lighting Controller Active!")
	

	def testLights(self):
		''' Tests the light relays. '''

		print("> NOTICE: Testing Relay #1..")  
		#io.output(self.CONFIGURATION.LIGHT_RELAY_PIN, True)
		time.sleep(5);
		#io.output(self.CONFIGURATION.LIGHT_RELAY_PIN, False)
		print("> NOTICE: Relay #1 Test Complete!")
		time.sleep(5);
	

	def turnLightsOn(self):
		''' Turns the lights on. '''

		if(self.LIGHTS_ON == True):
			return

		self.LIGHTS_ON = True
		
		print("> NOTICE: Activating Lights")
		
		io.output(self.CONFIGURATION.LIGHT_RELAY_PIN, True)
	

	def turnLightsOff(self):
		''' Turns the lights off. '''

		if(self.LIGHTS_ON == False):
			return

		self.LIGHTS_ON = False
		
		print("> NOTICE: Deactivating Lights")
		
		io.output(self.CONFIGURATION.LIGHT_RELAY_PIN, False)


	def getLightsActiveState(self):
		''' Returns the current active state of the lighting system. '''

		return self.LIGHTS_ON
