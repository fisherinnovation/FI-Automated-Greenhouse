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

import os
from setuptools import setup

def read(fname):
    return open(os.path.join(os.path.dirname(__file__), fname)).read()

setup(
    name = "FI-Automated Greenhouse",
    version = "0.0.1",
    author = "Matt Fisher",
    author_email = "fisher.matt@gmail.com",
    description = ("The Fisher Innovation Automated Greenhouse is a experimental prototype contained hydroponic greenhouse with automated climate control for use in small spaces."),
    license = "MIT",
    keywords = "raspberry pi automated greenhouse",
    url = "https://github.com/fisherinnovation/FI-Automated-Greenhouse",
    packages=['an_example_pypi_project', 'tests'],
    long_description=read('README'),
    classifiers=[
        "Development Status :: 1 - Alpha",
        "Topic :: Utilities",
        "License :: MIT License",
    ],