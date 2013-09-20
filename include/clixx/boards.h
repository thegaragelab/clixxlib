/*--------------------------------------------------------------------------*
* ClixxLib - Copyright (c) 2013, Shane Gough (shane@thegaragelab.com)
*            For licensing information see COPYING in the project root.
*---------------------------------------------------------------------------*
* 20-Aug-2013 ShaneG
*
* This file is used to bring in the board specific definitions from the
* appropriate include files.
*--------------------------------------------------------------------------*/
#ifndef __CLIXX_BOARDS_H
#define __CLIXX_BOARDS_H

// Do some sanity checking
#ifndef __CLIXX_H
#  error "Do not include this file directly. Include <clixx.h> instead."
#endif

/** Dock implementation class
 *
 * This extends the public Dock class with implementation specific methods. The
 * implementation of this class is provided by the individual boards.
 */
class DockImpl : public Dock {
  public:
    /** Read a value from a digital slot
     *
     * @param slot the number of the slot to read from
     *
     * @return the value read. Will be zero or 1.
     */
    uint16_t read_digital(int slot);

    /** Write a value to a digital slot.
     *
     * @param slot the number of the slot to write to
     * @param value the value to write. Non-zero values will be written as high.
     */
    void write_digital(int slot, uint16_t value);

    /** Read a value from a analog slot
     *
     * @param slot the number of the slot to read from
     *
     * @return the value read. An unsigned 16 bit value.
     */
    uint16_t read_analog(int slot);

    /** Write a value to an analog slot.
     *
     * @param slot the number of the slot to write to
     * @param value the 16 bit value to write.
     */
    void write_analog(int slot, uint16_t value);

    /** Read a value from a I2C slot
     *
     * @param slot the number of the slot to read from
     *
     * @return the next 8 bit value from the slot.
     */
    uint16_t read_i2c(int slot);

    /** Read a block of data from an I2C slot
     *
     * Will attempt to read up to 'count' bytes from the I2C slot. The read
     * will complete if it times out. The caller must ensure that the memory
     * pointed to by pBuffer is large enough to hold the data read.
     *
     * @param slot the slot number to read from.
     * @param pBuffer pointer to the memory location to store data in.
     * @param offset offset into the buffer to start storing data.
     * @param count the maximum number of bytes to read.
     *
     * @return the number of bytes that were actually read or -1 if an error
     *         occurs.
     */
    int read_i2c(int slot, uint8_t *pBuffer, int offset, int count);

    /** Write a value to an I2C slot.
     *
     * @param slot the number of the slot to write to
     * @param value the value to write. Only the least significant 8 bits will
     *              be written.
     */
    void write_i2c(int slot, uint16_t value);

    /** Write a block of data to an I2C slot
     *
     * Will attempt to write up to 'count' bytes to the I2C slot.
     *
     * @param slot the slot number to write to.
     * @param pBuffer pointer to the memory location to read data from.
     * @param offset offset into the buffer to start reading data.
     * @param count the maximum number of bytes to write.
     *
     * @return the number of bytes that were actually written or -1 if an error
     *         occurs.
     */
    int write_i2c(int slot, uint8_t *pBuffer, int offset, int count);

    /** Read a value from a SPI slot
     *
     * @param slot the number of the slot to read from
     *
     * @return the next 8 bit value from the slot.
     */
    int read_spi(int slot);

    /** Read a block of data from an SPI slot
     *
     * Will attempt to read up to 'count' bytes from the I2C slot. The read
     * will complete if it times out. The caller must ensure that the memory
     * pointed to by pBuffer is large enough to hold the data read.
     *
     * @param slot the slot number to read from.
     * @param pBuffer pointer to the memory location to store data in.
     * @param offset offset into the buffer to start storing data.
     * @param count the maximum number of bytes to read.
     *
     * @return the number of bytes that were actually read or -1 if an error
     *         occurs.
     */
    int read_spi(int slot, uint8_t *pBuffer, int offset, int count);

    /** Write a value to an SPI slot.
     *
     * @param slot the number of the slot to write to
     * @param value the value to write. Only the least significant 8 bits will
     *              be written.
     */
    void write_spi(int slot, uint16_t value);

    /** Write a block of data to an SPI slot
     *
     * Will attempt to write up to 'count' bytes to the I2C slot.
     *
     * @param slot the slot number to write to.
     * @param pBuffer pointer to the memory location to read data from.
     * @param offset offset into the buffer to start reading data.
     * @param count the maximum number of bytes to write.
     *
     * @return the number of bytes that were actually written or -1 if an error
     *         occurs.
     */
    int write_spi(int slot, uint8_t *pBuffer, int offset, int count);

    /** Read a value from a Serial slot
     *
     * @param slot the number of the slot to read from
     *
     * @return the next 8 bit value from the slot.
     */
    int read_serial(int slot);

    /** Read a block of data from a serial slot
     *
     * Will attempt to read up to 'count' bytes from the I2C slot. The read
     * will complete if it times out. The caller must ensure that the memory
     * pointed to by pBuffer is large enough to hold the data read.
     *
     * @param slot the slot number to read from.
     * @param pBuffer pointer to the memory location to store data in.
     * @param offset offset into the buffer to start storing data.
     * @param count the maximum number of bytes to read.
     *
     * @return the number of bytes that were actually read or -1 if an error
     *         occurs.
     */
    int read_serial(int slot, uint8_t *pBuffer, int offset, int count);

    /** Write a value to a serial slot.
     *
     * @param slot the number of the slot to write to
     * @param value the value to write. Only the least significant 8 bits will
     *              be written.
     */
    void write_serial(int slot, uint16_t value);

    /** Write a block of data to a serial slot
     *
     * Will attempt to write up to 'count' bytes to the I2C slot.
     *
     * @param slot the slot number to write to.
     * @param pBuffer pointer to the memory location to read data from.
     * @param offset offset into the buffer to start reading data.
     * @param count the maximum number of bytes to write.
     *
     * @return the number of bytes that were actually written or -1 if an error
     *         occurs.
     */
    int write_serial(int slot, uint8_t *pBuffer, int offset, int count);
  };

#endif // __CLIXX_BOARDS_H

