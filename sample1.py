#!/usr/bin/env python
#----------------------------------------------------------------------------
# Module initialisation.
#----------------------------------------------------------------------------
from clixxio import RaspberryDock, Slot

if __name__ == "__main__":
  dock = RaspberryDock()
  slot = dock.slot(Slot.DIGITAL_0)
  while True:
    pass

