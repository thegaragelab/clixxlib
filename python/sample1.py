#!/usr/bin/env python
#----------------------------------------------------------------------------
# Module initialisation.
#----------------------------------------------------------------------------
from clixx import DefaultDock, Slot

if __name__ == "__main__":
  dock = DefaultDock()
  dock.setup()
  slot = dock.slot(Slot.DIGITAL_0)
  while True:
    pass

