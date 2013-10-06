/*--------------------------------------------------------------------------*
* ClixxLib - Copyright (c) 2013, Shane Gough (shane@thegaragelab.com)
*            For licensing information see COPYING in the project root.
*---------------------------------------------------------------------------*
* 20-Aug-2013 ShaneG
*
* Defines the classes for specific Dock types.
*--------------------------------------------------------------------------*/
#ifndef __DOCKS_H
#define __DOCKS_H

// Do some sanity checking
#if !(defined(__CLIXX_H) && defined(__DOCK_H))
#  error "Do not include this file directly. Include <clixx.h> instead."
#endif

// Required definitions
#include <stdint.h>

/** Definition of an Analog Dock
 */
class AnalogDock : public Dock {
  public:
    //-----------------------------------------------------------------------
    // Construction and initialisation
    //-----------------------------------------------------------------------

    /** Constructor
     */
    AnalogDock(DockInfo *pDockInfo) : Dock() {
      // Nothing to do here
      };

    /** Set up the Dock
     *
     * This method is implemented by the board code.
     */
    virtual bool Setup();

    /** Clean up the Dock
     *
     * This method is implemented by the board code.
     */
    virtual void Cleanup();

    //-----------------------------------------------------------------------
    // Analog API
    //-----------------------------------------------------------------------

    /** Get the resolution of this Analog Dock
     *
     * Returns the resolution (in bits) of the analog input. This value
     * depends on the host CPU or the ADC module being used.
     *
     * @return the number of bits of accuracy this analog input provides.
     *         Usual values are 8, 10, 12 or 16. The maximum supported
     *         value is 16.
     */
    uint8_t Resolution();

    /** Read a value from the Dock
     *
     * Read a value from the Dock. In the case of an analog Dock this is the
     * value returned from an ADC.
     *
     * @param pValue a pointer to the location to store the read value.
     *
     * @return true if a valid value was read - in this case the value read
     *              is stored at the location pointed to by pValue. If the
     *              return value is false this means that pValue is unchanged
     *              or contains an invalid value.
     */
    bool Read(uint16_t *pValue);

    /** Write a value to the Dock
     *
     * @param value the value to write to the DAC output.
     *
     * @return true if the value was set correctly, false if an error occured.
     *              In the case of an error the current output value may be
     *              undefined.
     *
     */
    bool Write(uint16_t value);

  };

/** Definition of a Digital Dock
 */
class DigitalDock : public Dock {
  public:
    //-----------------------------------------------------------------------
    // Construction and initialisation
    //-----------------------------------------------------------------------

    /** Constructor
     */
    DigitalDock(DockInfo *pDockInfo) : Dock() {
      // Nothing to do here
      };

  protected:
    /** Set up the Dock
     *
     * This method is implemented by the board code.
     */
    virtual bool Setup();

    /** Clean up the Dock
     *
     * This method is implemented by the board code.
     */
    virtual void Cleanup();

  public:
    //-----------------------------------------------------------------------
    // Digital API
    //-----------------------------------------------------------------------

    /** Read a value from the Dock
     *
     * Read a value from the Dock. In the case of an digital Dock this is the
     * value returned on the IO pin.
     *
     * @param pValue a pointer to the location to store the read value.
     *
     * @return true if a valid value was read - in this case the value read
     *              is stored at the location pointed to by pValue. If the
     *              return value is false this means that pValue is unchanged
     *              or contains an invalid value.
     */
    bool Read(bool *pValue);

    /** Write a value to the Dock
     *
     * @param value the value to write to the DAC output.
     *
     * @return true if the value was set correctly, false if an error occured.
     *              In the case of an error the current output value may be
     *              undefined.
     *
     */
    bool Write(bool value);

  };

/** Definition of a Serial Dock
 */
class SerialDock : public Dock {
  public:
    //-----------------------------------------------------------------------
    // Construction and initialisation
    //-----------------------------------------------------------------------

    /** Constructor
     */
    SerialDock(DockInfo *pDockInfo) : Dock() {
      // Nothing to do here
      };

  protected:
    /** Set up the Dock
     *
     * This method is implemented by the board code.
     */
    virtual bool Setup();

    /** Clean up the Dock
     *
     * This method is implemented by the board code.
     */
    virtual void Cleanup();

  public:
    //-----------------------------------------------------------------------
    // Serial API
    //-----------------------------------------------------------------------

    /** Read a value from the Dock
     *
     * Read a value from the Dock. In the case of an digital Dock this is the
     * value returned on the IO pin.
     *
     * @param pValue a pointer to the location to store the read value.
     *
     * @return true if a valid value was read - in this case the value read
     *              is stored at the location pointed to by pValue. If the
     *              return value is false this means that pValue is unchanged
     *              or contains an invalid value.
     */
    int Read(uint8_t *pBuffer, int size);

    /** Read a line of text from the input
     *
     */
    int ReadLine(uint8_t *pBuffer, int size);

    /** Write a value to the Dock
     *
     * @param value the value to write to the DAC output.
     *
     * @return true if the value was set correctly, false if an error occured.
     *              In the case of an error the current output value may be
     *              undefined.
     *
     */
    int Write(uint8_t *pBuffer, int size = -1);

    /** Write a line of text to the Dock
     *
     */
    int WriteLine(uint8_t *pBuffer, int size = -1);

  };

/** Definition of a TwoWire Dock
 */
class TwoWireDock : public Dock {
  public:
    //-----------------------------------------------------------------------
    // Construction and initialisation
    //-----------------------------------------------------------------------

    /** Constructor
     */
    TwoWireDock(DockInfo *pDockInfo) : Dock() {
      // Nothing to do here
      };

  protected:
    /** Set up the Dock
     *
     * This method is implemented by the board code.
     */
    virtual bool Setup();

    /** Clean up the Dock
     *
     * This method is implemented by the board code.
     */
    virtual void Cleanup();

  public:
    //-----------------------------------------------------------------------
    // TwoWire API
    //-----------------------------------------------------------------------

    /** Read a value from the Dock
     *
     */
    bool Read(uint8_t address, uint8_t *pData, uint16_t size);

    /** Write a value to the Dock
     */
    bool Write(uint8_t address, uint8_t *pData, uint16_t size);

  };

/** Definition of an SPI Dock
 */
class SPIDock : public Dock {
public:
  //-----------------------------------------------------------------------
  // Construction and initialisation
  //-----------------------------------------------------------------------

  /** Constructor
   */
  SPIDock(DockInfo *pDockInfo) : Dock() {
    // Nothing to do here
    };

protected:
  /** Set up the Dock
   *
   * This method is implemented by the board code.
   */
  virtual bool Setup();

  /** Clean up the Dock
   *
   * This method is implemented by the board code.
   */
  virtual void Cleanup();

public:
  //-----------------------------------------------------------------------
  // SPI API
  //-----------------------------------------------------------------------

  /** Read a value from the Dock
   *
   */
  bool Read(uint8_t *pData, uint16_t size);

  /** Write a value to the Dock
   */
  bool Write(uint8_t *pData, uint16_t size);

  };

#endif /* __DOCKS_H */
