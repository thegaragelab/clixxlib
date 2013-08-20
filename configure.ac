AC_INIT(clixxlib, 0.1, shane@thegaragelab.com)
AC_CONFIG_AUX_DIR(config)
AC_CONFIG_MACRO_DIR(m4)
AC_CONFIG_SRCDIR(src/docks.cpp)
AC_CANONICAL_SYSTEM

AM_INIT_AUTOMAKE([subdir-objects])
LT_INIT

AC_PROG_CC
AC_PROG_CXX

#----------------------------------------------------------------------------
# Check board selection
#----------------------------------------------------------------------------

AC_ARG_WITH([board],
  AS_HELP_STRING([--with-board], [Specify the board to build for.]))

# Make sure the target is valid
if test "x$with_board" == "xarduino"; then
  AC_MSG_NOTICE([Targeting Arduino board.])
  TARGET_BOARD=arduino
  TARGET_DEFINE=TARGET_ARDUINO
elif test "x$with_board" == "xclixxdock"; then
  AC_MSG_NOTICE([Targeting ClixxDock station.])
  TARGET_BOARD=clixxdock
  TARGET_DEFINE=TARGET_CLIXXDOCK
elif test "x$with_board" == "xlaunchpad"; then
  AC_MSG_NOTICE([Targeting Stellaris Launchpad board.])
  TARGET_BOARD=launchpad
  TARGET_DEFINE=TARGET_LAUNCHPAD
elif test "x$with_board" == "xlpc1114"; then
  AC_MSG_NOTICE([Targeting LPC1114FN28 based boards.])
  TARGET_BOARD=lpc1114
  TARGET_DEFINE=TARGET_LPC1114
elif test "x$with_board" == "xraspi"; then
  AC_MSG_NOTICE([Targeting Raspberry Pi boards.])
  TARGET_BOARD=raspi
  TARGET_DEFINE=TARGET_RASPI
else
  AC_MSG_ERROR([
** You must specify a valid target board. Options are:
**
**   arduino   - AVR based Arduino boards and compatibles.
**   clixxdock - ClixxDock docking station over USB serial connection.
**   launchpad - Stellaris Launchpad.
**   lpc1114   - NXP LPC1114FN28 based ARM boards
**   raspi     - Raspberry Pi (Model A or Model B)])
fi
AC_SUBST(TARGET_BOARD)
AC_SUBST(TARGET_RASPI)

#----------------------------------------------------------------------------
# TODO: Check for required libraries
#----------------------------------------------------------------------------

#----------------------------------------------------------------------------
# TODO: Verify board specific requirements
#----------------------------------------------------------------------------

#----------------------------------------------------------------------------
# Generate output files
#----------------------------------------------------------------------------

AC_OUTPUT(
  Makefile
  )

