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

/** This class is the base for all types of Dock instances.
 *
 */
class Dock {
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

    /** Defines a structure defining basic information about a Dock
     *
     */
    struct DockInfo {
      Size        m_size;      //!< The size of the dock
      Type        m_type;      //!< The type of the dock
      Level       m_level;     //!< The voltage level(s) supported
      const void *m_pHardware; //!< Hardware details about the dock
      };

  protected:
    //--- Instance variables
    const DockInfo *m_pDockInfo;  //!< Information about this dock
    bool            m_bAvailable; //!< Set to 'true' if the dock is usable

  protected:
    //-----------------------------------------------------------------------
    // Construction and initialisation
    //-----------------------------------------------------------------------

    /** Constructor
     *
     * The constructor for a generic Dock saves the internal state and then
     * calls the Setup() method implemented by the child class.
     *
     * Please note that the Setup() method is called before the code for the
     * child class constructor is executed. The Init() method is provided as
     * a way of doing post construction initialisation. It should be the
     * last method called by the constructor implementation of child classes.
     *
     * @see Dock::Setup
     * @see Dock::Init
     *
     * @param pDockInfo information about the Dock being initialised.
     */
    Dock(DockInfo *pDockInfo);

    /** Set up the Dock
     *
     * This function is required to setup the hardware interface for the
     * defined Dock. Implementations of this function are found in the
     * source for board definitions.
     *
     * @return true if the setup procedure succeeded, false if it failed.
     */
    virtual bool Setup() = 0;

    /** Initialise the Dock
     *
     * Initialises the Dock after the hardware setup has been completed. The
     * Setup() method is called from the base constructor, the Init() method
     * must be explicitly called from the child class constructor.
     *
     * If implemented the parent implementation of Init() must be called
     * prior to performing any local initialisation. This method is mainly
     * implemented by module child classes.
     *
     * @return true if the initialisation succeeded, false if it failed.
     */
    virtual bool Init();

    /** Clean up the Dock
     *
     */
    virtual void Cleanup();

  public:
    //-----------------------------------------------------------------------
    // Cleanup
    //-----------------------------------------------------------------------

    /** Destructor
     *
     * The destructor simply calls the Cleanup() method defined by the child
     * class to do whatever is needed to disable the Dock.
     *
     * @see Dock::Cleanup
     */
    virtual ~Dock();

    //-----------------------------------------------------------------------
    // Informational methods
    //-----------------------------------------------------------------------

    /** Is this dock usable ?
     *
     */
    inline bool isUsable() {
      return m_bAvailable;
      }

    /** Determine if the voltage level is supported
     *
     */
    inline bool isLevelSupported(Level level) {
      if((m_pDockInfo->m_level&level)==level)
        return true;
      return false;
      }

    /** Get the type of the dock
     *
     */
    inline Type getType() {
      return m_pDockInfo->m_type;
      }

    /** Get the size of the dock
     *
     */
    inline Size getSize() {
      return m_pDockInfo->m_size;
      }

  };

#endif /* __DOCK_H */
