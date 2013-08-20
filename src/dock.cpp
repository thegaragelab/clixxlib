/*--------------------------------------------------------------------------*
* ClixxLib - Copyright (c) 2013, Shane Gough (shane@thegaragelab.com)
*            For licensing information see COPYING in the project root.
*---------------------------------------------------------------------------*
* 20-Aug-2013 ShaneG
*
* This implements the common methods for the Dock classes and their
* derivatives.
*--------------------------------------------------------------------------*/
#include <stdlib.h>
#include <clixx.h>

//---------------------------------------------------------------------------
// Implementation of the 'Dock' base class
//---------------------------------------------------------------------------

/** Constructor
 */
Dock::Dock(DockInfo *pDockInfo) {
  // Save the info about the Dock
  m_bAvailable = (m_pDockInfo = pDockInfo) != NULL;
  if(!m_bAvailable)
    return;
  // TODO: Check and/or mark this Dock as being used
  // Setup the hardware associated with the Dock
  m_bAvailable &= this->Setup();
  if(!m_bAvailable)
    return;
  }

/** Destructor
 *
 * The destructor simply calls the Cleanup() method defined by the child
 * class to do whatever is needed to disable the Dock.
 *
 * @see Dock::Cleanup
 */
Dock::~Dock() {
  Cleanup();
  }

/** Initialise the Dock
 */
bool Dock::Init() {
  // Nothing to do in this implementation
  }
