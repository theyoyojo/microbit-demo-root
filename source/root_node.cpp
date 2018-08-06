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

#include "root_node.h"
#include "images.h"
#include "MicroBit.h"

#define DEFAULT_ANIMATION_DELAY 100

MicroBit uBit ;

using namespace ECG ;

//uint8_t& indexSelectedSignal

int RootNode::_selectedSignalIndex = 0 ;

uint8_t RootNode::_signals[] = {
    SIG_R,
    SIG_A,
    SIG_B
} ;

size_t RootNode::_signals_size = sizeof(_signals) ;


PacketBuffer RootNode::_tempPacketBuffer(1) ;

RootNode::RootNode() {

    uBit.init() ;
    uBit.radio.enable() ;

    // This is set to the starting index of the array, which
    // incedentally has the same value as SIG_RR itself
    _selectedSignalIndex = 0 ;

    // Ensure the contents of the PacketBuffer are nongarbage
    _tempPacketBuffer[0] = 0 ;


    uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_UP, this, &RootNode::onButtonAUp) ;
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_UP, this, &RootNode::onButtonBUp) ;
}


void RootNode::broadcastAnimation(int msDelay) {

   uBit.display.print(ECG::Images::centerRing) ;
   uBit.sleep(msDelay) ;

   uBit.display.print(ECG::Images::middleRing) ;
   uBit.sleep(msDelay) ;

   uBit.display.print(ECG::Images::outerRing) ;
   uBit.sleep(msDelay) ;

}

void RootNode::broadcastAnimation() {
    broadcastAnimation(DEFAULT_ANIMATION_DELAY) ;
}

// Increment through signal list
void RootNode::onButtonAUp(MicroBitEvent e) {

    // Increment
    _selectedSignalIndex++ ;

    // But if you go to far, loop back to 0
    if (_selectedSignalIndex > _signals_size - 1) {
        _selectedSignalIndex = 0 ;
    }
}

// Decrement through signal list
void RootNode::onButtonBUp(MicroBitEvent e) {

    broadcastAnimation() ;

    _tempPacketBuffer[0] = _signals[_selectedSignalIndex] ;

    uBit.radio.datagram.send(_tempPacketBuffer) ;

    uBit.serial.printf("Broadcast signal: %d\r\n", _tempPacketBuffer[0]) ;
}

void RootNode::loop() {
    uBit.display.print(_signals[_selectedSignalIndex]) ;
    uBit.sleep(10) ;
}