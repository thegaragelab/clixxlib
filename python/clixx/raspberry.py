#!/usr/bin/env python
#----------------------------------------------------------------------------
# Raspberry Pi interface.
#----------------------------------------------------------------------------
import wiringpi2
from clixxbase import ClixxException, Dock, Slot, SerialSlot, TwoWireSlot

#----------------------------------------------------------------------------
# Slot implementations
#----------------------------------------------------------------------------

class PiSlot(Slot):
  """ Slot implementation for basic Digital slots
  """

  def __init__(self, slotinfo):
    """ Initialise the slot
    """
    self.interface = slotinfo[1]
    self.format = slotinfo[2]
    self.pin_input = slotinfo[3]
    self.pin_extra = slotinfo[4]
    self.pin_output = slotinfo[5]

  def read(self):
    """ Read a single value from the slot
    """
    return wiringpi2.digitalRead(self.pin_output)

  def write(self, data):
    """ Write a single value to the slot
    """
    wiringpi2.digitalWrite(self.pin_input, data)

class PiSerialSlot(SerialSlot):
  def __init__(self, slotinfo):
    """ Initialise the slot
    """
    PiSlot.__init__(self, slotinfo)

class PiSpiSlot(SerialSlot):
  def __init__(self, slotinfo):
    """ Initialise the slot
    """
    PiSlot.__init__(self, slotinfo)

class PiTwoWireSlot(TwoWireSlot):
  def __init__(self, slotinfo):
    """ Initialise the slot
    """
    PiSlot.__init__(self, slotinfo)

# Specify the hardware connections for the slots
SLOTS = {
  #                Class,         Interface,    Size,           In, Ex, Out
  Slot.DIGITAL_0: (PiGeneralSlot, Slot.DIGITAL, Slot.SINGLETAB, 22, 0,  18),
  Slot.DIGITAL_1: (PiGeneralSlot, Slot.DIGITAL, Slot.TWINTAB,   17, 16, 18),
  Slot.DIGITAL_2: (PiGeneralSlot, Slot.DIGITAL, Slot.TWINTAB,   20, 19, 16),
  Slot.SPI_0:     (PiSpiSlot,     Slot.SPI,     Slot.SingleTab, 0,  0,  0 ),
  Slot.RS232_0:   (PiSerialSlot,  Slot.RS232,   Slot.SingleTab, 0,  0,  0 ),
  Slot.TWOWIRE_0: (PiTwoWireSlot, Slot.TWOWIRE, Slot.SingleTab, 0,  0,  0 ),
  Slot.TWOWIRE_1: (PiTwoWireSlot, Slot.TWOWIRE, Slot.SingleTab, 0,  0,  0 ),
  Slot.TWOWIRE_2: (PiTwoWireSlot, Slot.TWOWIRE, Slot.SingleTab, 0,  0,  0 ),
  Slot.TWOWIRE_3: (PiTwoWireSlot, Slot.TWOWIRE, Slot.SingleTab, 0,  0,  0 ),
  Slot.TWOWIRE_4: (PiTwoWireSlot, Slot.TWOWIRE, Slot.SingleTab, 0,  0,  0 ),
  Slot.TWOWIRE_5: (PiTwoWireSlot, Slot.TWOWIRE, Slot.SingleTab, 0,  0,  0 ),
  Slot.TWOWIRE_6: (PiTwoWireSlot, Slot.TWOWIRE, Slot.SingleTab, 0,  0,  0 ),
  Slot.TWOWIRE_7: (PiTwoWireSlot, Slot.TWOWIRE, Slot.SingleTab, 0,  0,  0 ),
  Slot.TWOWIRE_8: (PiTwoWireSlot, Slot.TWOWIRE, Slot.SingleTab, 0,  0,  0 ),
  Slot.TWOWIRE_9: (PiTwoWireSlot, Slot.TWOWIRE, Slot.SingleTab, 0,  0,  0 ),
  }

#----------------------------------------------------------------------------
# Dock implementation
#----------------------------------------------------------------------------

class RaspberryDock(Dock):
  """ Implements the Raspberry Pi hardware Dock on GPIO pins.
  """

  def setup(self, **kwargs):
    """ Initialise this particular Dock instance
    """
    # Initialise wiringpi2
    wiringpi2.wiringPiSetupPhys()
    # Set up the hardware interfaces
    global SLOTS
    self.slots = dict()
    for slot in SLOTS:
      info = SLOTS[slot]
      # Initialise the hardware
      if info[3] <> 0:
        wiringpi2.pinMode(info[3], 1)
      if info[4] <> 0:
        wiringpi2.pinMode(info[4], 0)
      if info[5] <> 0:
        wiringpi2.pinMode(info[5], 0)
      # Create the slot instance
      self.slots[slot] = info[0](info)

  def done(self):
    """ Clean up the Dock instance
    """
    pass

  def slot(self, name):
    """ Get a slot by it's name
    """
    if not self.slots.has_key(name):
      return None
    return self.slots[name]

  def available(self):
    """ Return a list of available Slots
    """
    return tuple(sorted(self.slots.keys()))

