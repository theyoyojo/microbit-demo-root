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
  signals.h

  This file implements an enum that contains the definitions
  of signals used on the network and a variable that contains the number of signals
**/

#ifndef SIGNALS_H
#define SIGNALS_H

namespace ECG {

typedef enum signal {
  SIG_R, // Reset all nodes to their default state (UNASSIGNED)
  SIG_A, // Set all devices in GAME_LISTEN_A state to GAME_TEAM_A state
  SIG_B  // Set all devices in GAME_LISTEN_B state to GAME_TEAM_B state
} Signal ;

// The number of signals that exist in this system
const int nSignals = 3 ;

} // namespace ECG

#endif // SIGNALS_H