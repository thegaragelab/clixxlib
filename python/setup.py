#!/usr/bin/env python
#----------------------------------------------------------------------------
# Setup tools for Clixx.Py Python library.
#----------------------------------------------------------------------------
import os
from setuptools import setup

# Utility function to read the README file.
# Used for the long_description.  It's nice, because now 1) we have a top level
# README file and 2) it's easier to type in the README file than to put a raw
# string in below ...
def read(fname):
    return open(os.path.join(os.path.dirname(__file__), fname)).read()

setup(
    name = "clixx_py",
    version = "0.0.1",
    author = "Shane Gough",
    author_email = "shane@thegaragelab.com",
    description = ("Interface library for Clixx.IO peripherals and docks."),
    license = "BSD",
    keywords = "example documentation tutorial",
    url = "http://packages.python.org/clixx_py",
    packages=[ 'clixx', ],
    long_description=read('README'),
    classifiers=[
        "Development Status :: 3 - Alpha",
        "Environment :: Console",
        "License :: OSI Approved :: GNU General Public License v3 or later (GPLv3+)",
        "Operating System :: Microsoft :: Windows",
        "Operating System :: POSIX :: Linux",
        "Topic :: Scientific/Engineering",
    ],
)
