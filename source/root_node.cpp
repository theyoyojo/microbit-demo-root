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
  root_node.cpp

  This file implements class RootNode as declared and described in root_node.h
**/

#include "root_node.h"


using namespace ECG ;

MicroBit RootNode::_uBit ;

int RootNode::_selectedSignal = 0 ;

PacketBuffer RootNode::_tempPacketBuffer(1) ;

RootNode::RootNode() {

  // Device initialization
  _uBit.init() ;
  _uBit.radio.enable() ;

  // Set the selected signal to the first signal
  _selectedSignal = SIG_R ;

  // Ensure the contents of the PacketBuffer payload match the initial
  // selected signal
  _tempPacketBuffer[0] = _selectedSignal ;

  // Register button event handlers

  // Button A
  _uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_UP,
  this, &RootNode::onButtonAUp) ;

  // Button B
  _uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_UP,
  this, &RootNode::onButtonBUp) ;
}

// Increment through signals
void RootNode::onButtonAUp(MicroBitEvent e) {

  // Increment signal
  _selectedSignal++ ;

  // But if you go to far, loop back to 0
  if (_selectedSignal >= nSignals ) {
    _selectedSignal = SIG_R ;
  }
}

// Broadcast signal
void RootNode::onButtonBUp(MicroBitEvent e) {

  // Put the signal in the PacketBuffer payload
  _tempPacketBuffer[0] = _selectedSignal ;

  // Send it.
  _uBit.radio.datagram.send(_tempPacketBuffer) ;

  _uBit.serial.printf("Broadcast signal: %d\r\n", _tempPacketBuffer[0]) ;
}

// Primary execution loop
void RootNode::loop() {

  // Display selected signal
  _uBit.display.print(_selectedSignal) ;

  // Refresh display every 10 ms
  _uBit.sleep(10) ;

}