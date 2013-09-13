/*--------------------------------------------------------------------------*
* ClixxLib - Copyright (c) 2013, Shane Gough (shane@thegaragelab.com)
*            For licensing information see COPYING in the project root.
*---------------------------------------------------------------------------*
* 20-Aug-2013 ShaneG
*
* Defines the base Dock class.
*--------------------------------------------------------------------------*/
#ifndef __DOCK_H
#define __DOCK_H

// Do some sanity checking
#ifndef __CLIXX_H
#  error "Do not include this file directly. Include <clixx.h> instead."
#endif

/** Represents a single Slot containing a Tab
 */
class Slot {
  public:
    /** Defines the supported voltage levels.
     *
     * This enum specifies the supported voltage level for the peripherals
     * plugged into the dock. This defines both the voltage provided for
     * power and the signal voltage levels.
     *
     * In the case of digital docks (including those supporting a serial
     * protocol such as Serial, TwoWire or SPI) the 0 level is generally
     * a voltage less than 20% of the level and a 1 level is generally
     * a voltage more than 80% of the level. For Analog boards this
     * defines the maximum allowed input voltage, the minimum is always
     * 0V (GND).
     *
     * As some devices may support multiple voltage levels this value
     * is treated like a flag. You must test explicitly for the voltage
     * level you want to use.
     */
    enum Level {
      V033 = 0x01, //!< The level is 3.3V
      V050 = 0x02, //!< The level is 5.0V
      };

    /** Defines the available dock types.
     *
     * Clixx.IO support a number of dock types which define the interface to
     * the various peripheral boards. Each dock is of a specific type and
     * types cannot be mixed (you cannot plug an Analog peripheral into a
     * Serial dock and expect it to work).
     */
    enum Type {
      Custom = 0, //!< A custom interface for end user modifications.
      Analog,     //!< An analog interface.
      Digital,    //!< A digital interface.
      Serial,     //!< A serial interface for data exchange.
      TwoWire,    //!< A two wire communications interface (I2C).
      SPI,        //!< An SPI interface.
      };

    /** Defines the available dock sizes.
     *
     * In the Clixx.IO system there are two sizes of dock - a SingleTab and
     * a TwinTab dock. The SingleTab dock has two power connectors and two
     * data connectors - one for input, the other for ouput. The TwinTab
     * dock has two power connectors and three data connectors - input and
     * output as per the SingleTab and an 'extra' connector. In some case
     * the 'extra' connector is defined by the type of the Dock, in others
     * it can be defined by the user.
     */
    enum Size {
      SingleTab = 0, //!< A SingleTab (4 pin) dock
      TwinTab,       //!< A TwinTab (5 pin) dock
      };

    /** A single structure containing information about a slot
     */
    struct SlotInfo {
      Level m_level; //! Supported voltage levels
      Type  m_type;  //! The slot type
      Size  m_size;  //! The size of the slot
      };

  public:
    //-----------------------------------------------------------------------
    // Informational methods
    //-----------------------------------------------------------------------

    /** Get information about this Slot
     *
     * @return a SlotInfo structure describing the properties of this Slot
     */
    virtual SlotInfo *getSlotInfo() = 0;

    /** Get the type of this Slot
     *
     * @return the type of this slot (one of the Slot::Type constants)
     */
    inline Type getType() {
      return getSlotInfo()->m_type;
      }

    /** Get the size of this Slot
     *
     * @return the size of this slot (one of the Slot::Size constants)
     */
    inline Size getSize() {
      return getSlotInfo()->m_size;
      }

    //-----------------------------------------------------------------------
    // Read/Write operations
    //-----------------------------------------------------------------------

    /** Read data from a Slot
     *
     * Read the current value of the input pin of this slot. The value returned
     * is always a 16 bit unsigned value, the actual meaning of the value
     * depends on the type of the Slot.
     *
     * For a digital slot the value is either 0 or 1, for analog it is the
     * current ADC value and for communications slots (I2C, SPI or Serial)
     * it will be the next byte of data.
     *
     * @return the value read from the input pin.
     */
    virtual uint16_t read() = 0;

    /** Write data to a Slot
     *
     * Write a new value to the output pin of this slot. The interpretation of
     * the value depends on the type of the Slot being implemented.
     *
     * For a digital slot the output will be set low if the value is 0 and set
     * high for any other value. For an analog slot the data will be written
     * to the DAC (or PWM) channel. For communications slots (I2C, SPI or Serial)
     * the least significant 8 bits will be sent as a single data byte.
     *
     * @param value the value to write to the slot.
     */
    virtual bool write(uint16_t value) = 0;

    /** Read data from the 'extra' pin on a TwinTab Slot
     *
     * Read the current value of the extra pin of this slot. The extra pin is
     * always a digital pin. The value returned is either 0 or 1.
     *
     * @return the value read from the extra pin.
     */
    virtual uint16_t readExtra() = 0;

    /** Write data to the 'extra' pin on a TwinTab Slot
     *
     * Write a value to the extra pin of this slot. The extra pin is always
     * digital, the output will be set low if the value is 0 and set high for
     * any other value.
     *
     * @param value the value to write to the slot.
     */
    virtual bool writeExtra(uint16_t value) = 0;
  };

/** This class is the base for all types of Dock instances.
 *
 */
class Dock {
  public:
    /** Initialise the Dock
     *
     * Initialises the Dock by setting up the hardware. This method must
     * be called first, all other access methods will fail if a successful
     * call to init has not been made.
     *
     * @return true if the initialisation succeeded, false if it failed.
     */
    virtual bool init() = 0;

    /** Get the number of slot's available
     *
     * @return the number of slots available
     */
    virtual int getSlots() = 0;

    /** Get a reference to a specific slot
     */
    virtual Slot& getSlot(int slotNumber) = 0;

  };

/** Every platform provides a default Dock instance */
extern Dock SystemDock;

/** Represents a single Tab or peripheral board
 */
class Tab {
  public:
    /** Get the SlotInfo structure describing the type of Slot required.
     */
    virtual SlotInfo *getRequiredSlotInfo() = 0;

    /** Attach this Tab to a Slot
     */
    virtual bool attach(Slot &slot) = 0;

  };


#endif /* __DOCK_H */
