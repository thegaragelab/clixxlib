#!/usr/bin/env python
#----------------------------------------------------------------------------
# Module initialisation.
#----------------------------------------------------------------------------
from clixxbase import Dock, Slot, Tab

# Set up the default dock
DefaultDock = None

# Allow SmartDock only if PySerial is available
try:
  from smartdock import SmartDock
  DefaultDock = SmartDock()
except:
  pass # Ignore it

# Allow Raspberry Pi dock only if WiringPi 2 is available
try:
  from raspberry import RaspberryDock
  DefaultDock = RaspberryDock()
except:
  pass # Ignore it for now

