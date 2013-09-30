#!/usr/bin/env python
#----------------------------------------------------------------------------
# Base classes
#----------------------------------------------------------------------------

class ClixxException(Exception):
  """ Exception class used for the Clixx.Py library
  """

  def __init__(self, message):
    self.message = message

  def __str__(self):
    return repr(self.message)

class Dock:
  """ A Dock is a collection of Slot instances that communicate with hardware.
  """

  def setup(self, **kwargs):
    """ Initialise this particular Dock instance
    """
    raise ClixxException("Not yet implemented.")

  def done(self):
    """ Clean up the Dock instance
    """
    pass

  def get_slot(self, slot_index):
    """ Get a slot by it's name
    """
    raise ClixxException("Not yet implemented.")

class Slot:
  """ A Slot is a single connector in a Dock.
  """

  def read(self):
    """ Read a single value from the slot
    """
    raise ClixxException("Not yet implemented.")

  def read_data(self, data, offset, length):
    """ Read a sequence of data from the slot
    """
    raise ClixxException("Not yet implemented.")

  def write(self, data):
    """ Write a single value to the slot
    """
    raise ClixxException("Not yet implemented.")

  def write_data(self, data, offset, length):
    """ Write a sequence of data to the slot
    """
    raise ClixxException("Not yet implemented.")

class Tab:
  """ A Tab is a peripheral hardware board attached to a Slot.
  """
  pass

