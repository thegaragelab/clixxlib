#!/usr/bin/env python
#----------------------------------------------------------------------------
# Module initialisation.
#----------------------------------------------------------------------------
from clixxbase import Dock, Slot, SerialSlot, TwoWireSlot, Tab

# Set up the default dock
DefaultDock = None

# SmartDock will be available if PySerial is installed
try:
  from smartdock import SmartDock
  DefaultDock = SmartDock
except:
  pass # Ignore it

# RaspberryDock will be available if WiringPi2 is installed
try:
  from raspberry import RaspberryDock
  DefaultDock = RaspberryDock
except:
  pass # Ignore it for now

# Make sure we have a Dock implementation available
if DefaultDock is None:
  print """
No Dock hardware could be found on this machine. Please make sure you have the
appropriate support libraries installed.
"""
  exit(1)

