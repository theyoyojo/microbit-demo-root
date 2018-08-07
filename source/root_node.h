/*
The MIT License (MIT)

Copyright (c) 2018 Joel Savitz

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

/**
  root_node.h

  This file declares a class that represents the device and functionality of a
  network node that is intended to be used as an interface to control the
  demonstration game implemented by this project and it's user (network access)
  companion project.
**/

#ifndef ROOT_NODE_H
#define ROOT_NODE_H

#include "MicroBit.h"
#include "signals.h"

namespace ECG {

class RootNode {

private:

// A packet buffer used to broadcast signals
static PacketBuffer _tempPacketBuffer ;

// The currently selected signal
static int _selectedSignal ;

public:

  /**
    * Default constructor
    * 
    * Builds animations and registers event handlers
    */
  RootNode() ;

  /**
    * Event handler for A-U
    * 
    * @param e: An object representing the raised event passed
    * to the function via the messageBus
    */
  void onButtonAUp(MicroBitEvent e) ;

  /**
    * Event handler for B-U
    * 
    * @param e: An object representing the raised event passed
    * to the function via the messageBus
    */ 
  void onButtonBUp(MicroBitEvent e) ;

  /**
    * Primary execution loop called by main
    */
  void loop() ;

} ; // class RootNode

} // namspace ECG

#endif // ROOT_NODE_H