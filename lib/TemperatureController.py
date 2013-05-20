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
import subprocess
import os
import glob
#import RPi.GPIO as io
#io.setmode(io.BCM)

class TemperatureController(object):
	CONFIGURATION = False

	CURRENT_GREENHOUSE_TEMPERATURE = 0
	CURRENT_GREENHOUSE_HUMIDITY = 0
	CURRENT_WATER_TEMPERATURE = 0


	def __init__(self, conf):
		''' Setup the Relay Controller. '''

		print("> NOTICE: Activating Temperature Controller.")

		self.CONFIGURATION = conf
		self.setupWaterTemperatureSensor()

		print("> NOTICE: Temperature Controller Active!")


	def readGreenhouseTemperature(self):
		''' Reads the greenhouse temperature. 

		Configured for a DHT22/RHT03/AM2302(wired DHT22) Temperature & Humidity Sensor
		https://www.sparkfun.com/products/10167
		http://www.adafruit.com/products/393

		NOTE: Be sure to only call this method only once every two seconds.
		'''
		print("> NOTICE: Reading the greenhouse internal temperature...")

		DHT22 = subprocess.call("sudo ./Adafruit_DHT 2302 " + self.CONFIGURATION.GREENHOUSE_TEMPERATURE_PIN, shell=True)

		# TODO: Parse this data...


	def setupWaterTemperatureSensor(self):
		''' Initializes the water temperature sensors. '''

		os.system('modprobe w1-gpio')
		os.system('modprobe w1-therm')
		
		try:
			base_dir = '/sys/bus/w1/devices/'
			device_folder = glob.glob(base_dir + '28*')[0]
			device_file = device_folder + '/w1_slave'
		except:
			print '> ERROR: Failed to connect to water temperature sensor!'


	def readWaterTemperature(self):
		''' Reads the water temperature. '''
		print("> NOTICE: Reading the water temperature...")

		lines = read_temp_raw()

		while lines[0].strip()[-3:] != 'YES':
			time.sleep(0.2)
			lines = read_temp_raw()
	    
		equals_pos = lines[1].find('t=')
	    
		if equals_pos != -1:
			temp_string = lines[1][equals_pos+2:]
			temp_c = float(temp_string) / 1000.0
			temp_f = temp_c * 9.0 / 5.0 + 32.0

	        if self.CONFIGURATION.TEMPERATURE_FORMAT == 'C':
	        	CURRENT_WATER_TEMPERATURE = temp_c
	        else:
	        	CURRENT_WATER_TEMPERATURE = temp_f

	        #return temp_c, temp_f


	def regulateGreenhouseTemperature(self):
		''' Run system and temperature checks on the greenhouse enviroment. '''
		print("> NOTICE: Regulating greenhouse temperature.")

		# Check for an active and regulated water flow.

		if(self.CURRENT_GREENHOUSE_TEMPERATURE > self.CONFIGURATION.MAX_GREENHOUSE_TEMP):
			self.deactivacteWaterHeater()
		elif(self.CURRENT_GREENHOUSE_TEMPERATURE < self.CONFIGURATION.MIN_GREENHOUSE_TEMP):
			self.activacteWaterHeater()


	def regulateWaterTemperature(self):
		''' Run system and temperature checks on the water heating system. '''
		print("> NOTICE: Regulating water heating system.")

		# Check for an active and regulated water flow.

		if(self.CURRENT_WATER_TEMPERATURE > self.CONFIGURATION.MAX_WATER_TEMPERATURE):
			self.deactivacteWaterHeater()
		elif(self.CURRENT_WATER_TEMPERATURE < self.CONFIGURATION.MIN_WATER_TEMPERATURE):
			self.activacteWaterHeater()


	def activacteWaterHeater(self):
		''' Turns the water heating system on. '''
		print("> NOTICE: Activating water heating system...")


	def deactivacteWaterHeater(self):
		''' Turns the water heating system off. '''
		print("> NOTICE: Deactivating water heating system...")