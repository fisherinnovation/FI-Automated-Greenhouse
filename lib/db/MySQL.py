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
import MySQLdb

class MySQL(object):
	CONFIGURATION = False
	CONNECTION = False

	def __init__(self, conf):
		print("> NOTICE: Activating MySQL Database Connection...")

		self.CONFIGURATION = conf

		try:
			self.CONNECTION = MySQLdb.connect(
				host = self.CONFIGURATION.DB_HOST,
				user = self.CONFIGURATION.DB_USERNAME,
				passwd = self.CONFIGURATION.DB_PASSWORD,
				db = self.CONFIGURATION.DB_DATABASE
			) 
		except MySQLdb.Error, e:
  		    print "> ERROR: %d: %s" % (e.args[0], e.args[1])
		    #sys.exit(1)
		finally:
		    if self.CONNECTION:
		        self.CONNECTION.close()

		print("> NOTICE: MySQL Database Active!")


	def connect(self):
		''' Connects to the MySQL Database. '''

		print("> ") 