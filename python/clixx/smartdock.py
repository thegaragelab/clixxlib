#!/usr/bin/env python
#----------------------------------------------------------------------------
# SmartDock (RS232 based dock) interface.
#----------------------------------------------------------------------------
import serial
from clixxbase import ClixxException, Dock, Slot

class SmartDock(Dock):
  """ Implements the SmartDock protocol over a serial port.
  """

  #--------------------------------------------------------------------------
  # Interface methods
  #--------------------------------------------------------------------------

  def setup(self, **kwargs):
    """ Initialise this particular Dock instance
    """
    raise ClixxException("Not implemented.")

  def done(self):
    """ Clean up the Dock instance
    """
    pass

  def slot(self, name):
    """ Get a slot by it's name
    """
    raise ClixxException("Not implemented.")

  def available(self):
    """ Return a list of available Slots
    """
    raise ClixxException("Not implemented.")

