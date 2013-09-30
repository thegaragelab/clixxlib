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

    This class is meant to be a base class only, all methods throw a
    ClixxException when invoked as they are intended to be overwritten by a
    child class.
  """

  # Digital Slot names
  DIGITAL_0 = "D0"
  DIGITAL_1 = "D1"
  DIGITAL_2 = "D2"
  DIGITAL_3 = "D3"
  DIGITAL_4 = "D4"
  DIGITAL_5 = "D5"
  DIGITAL_6 = "D6"
  DIGITAL_7 = "D7"
  DIGITAL_8 = "D8"
  DIGITAL_9 = "D9"

  # Analog Slot names
  ANALOG_0 = "A0"
  ANALOG_1 = "A1"
  ANALOG_2 = "A2"
  ANALOG_3 = "A3"
  ANALOG_4 = "A4"
  ANALOG_5 = "A5"
  ANALOG_6 = "A6"
  ANALOG_7 = "A7"
  ANALOG_8 = "A8"
  ANALOG_9 = "A9"

  # TwoWire (I2C) Slot names
  TWOWIRE_0 = "T0"
  TWOWIRE_1 = "T1"
  TWOWIRE_2 = "T2"
  TWOWIRE_3 = "T3"
  TWOWIRE_4 = "T4"
  TWOWIRE_5 = "T5"
  TWOWIRE_6 = "T6"
  TWOWIRE_7 = "T7"
  TWOWIRE_8 = "T8"
  TWOWIRE_9 = "T9"

  # SPI Slot names
  SPI_0 = "S0"
  SPI_1 = "S1"
  SPI_2 = "S2"
  SPI_3 = "S3"
  SPI_4 = "S4"
  SPI_5 = "S5"
  SPI_6 = "S6"
  SPI_7 = "S7"
  SPI_8 = "S8"
  SPI_9 = "S9"

  # RS232 (Serial) Slot names
  RS232_0 = "R0"
  RS232_1 = "R1"
  RS232_2 = "R2"
  RS232_3 = "R3"
  RS232_4 = "R4"
  RS232_5 = "R5"
  RS232_6 = "R6"
  RS232_7 = "R7"
  RS232_8 = "R8"
  RS232_9 = "R9"

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

class Slot:
  """ A Slot is a single connector in a Dock.

    As with the Dock class this is a base class and designed to be overwritten
    by a child class. Each child *MUST* implement the methods defined here.

    In addition to the methods each child implementation is expected to provide
    instance variables representing the interface provided by the slot (eg:
    Slot.DIGITAL, Slot.ANALOG, etc) as well as the size of the slot (eg:
    Slot.SINGLETAB, Slot.TWINTAB)
  """

  # Slot interfaces
  DIGITAL = "D"
  ANALOG  = "A"
  TWOWIRE = "T"
  SPI     = "S"
  RS232   = "R"

  # Slot sizes
  SINGLETAB = "ST"
  TWINTAB   = "TT"

  #--------------------------------------------------------------------------
  # Interface methods
  #--------------------------------------------------------------------------

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

