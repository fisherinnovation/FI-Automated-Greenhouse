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
#import RPi.GPIO as io
#io.setmode(io.BCM)

class WaterController(object):
	CONFIGURATION = False

	CURRENT_WATER_TEMPERATURE = 0
	TOTAL_WATER_VOLUME_PUMPED = 0
	CURRENT_WATER_FLOW_RATE = 0


	def __init__(self, conf):
		''' Setup the Water Controller. '''

		print("> NOTICE: Activating Water Controller.")

		self.CONFIGURATION = conf

		print("> NOTICE: Water Controller Active!")


	def readFlowSensor(self):
		''' Reads the water pump flow sensor. 

		Liquid Flow Meter - Plastic 1/2" NPT Threaded
		http://www.adafruit.com/products/828

		Sensor Frequency (Hz) = 7.5 * Q (Liters/min)
		Liters = Q * time elapsed (seconds) / 60 (seconds/minute)
		Liters = (Frequency (Pulses/second) / 7.5) * time elapsed (seconds) / 60
		Liters = Pulses / (7.5 * 60)
		'''

		print("> NOTICE: Reading the water pump flow sensor.")
