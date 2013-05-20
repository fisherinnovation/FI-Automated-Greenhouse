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

class Configuration(): 
	''' System Configuration. '''

	# MySQL Database Configuration
	DB_HOST = 'localhost'	# MySQL hostname.
	DB_DATABASE = ''		# MySQL database name.
	DB_USERNAME = ''		# MySQL user name.
	DB_PASSWORD = ''		# MySQL password.


	# Temperature Configuration
	TEMPERATURE_FORMAT = 'C' # Temperature Format (C = Cecius, F = Fahrenheit)

	GREENHOUSE_TEMPERATURE_PIN = 24 # GPIO Pin for Greenhouse Temperature & Humidity Sensor.

	MAX_GREENHOUSE_TEMP = 26 # Maximum greenhouse temperature.
	MIN_GREENHOUSE_TEMP = 23 # Minimum greenhouse temperature.


	# Humidity Configuration
	MAX_GREENHOUSE_HUMIDITY = 80 # Maximum greenhouse humidity (as percentage).
	MIN_GREENHOUSE_HUMIDITY = 70 # Minimum greenhouse humidity (as percentage).


	# Water Temperature
	MAX_WATER_TEMPERATURE = 75	# Maximum water temperature.
	MIN_WATER_TEMPERATURE = 70	# Minimum water temperature.


	# Lighting Configuration
	LIGHTS_ON_TIME = 12 	# What hour (24h format) to turn the lights on. (-1 = 24h lights on).
	LIGHTS_OFF_TIME = 24 	# What hour (24h format) to turn the lights on. (-1 = 24h lights on).

	LIGHT_RELAY_PIN = 8 	# Light Relay Pin.


	# Fan Configuration
	FAN_CONTROL_PIN = 4;	# Setup Fan Control MOSFET on pin D4.