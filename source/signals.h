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

#ifndef SIGNALS_H
#define SIGNALS_H

// Definition of signals for upcoming demo system
// See specification for more information

// Root signals

// Reset all nodes to boot state (DEMO)
#define SIG_RR 0

// Set all nodes to DEMO state
#define SIG_RD 1

// Set all nodes to LISTEN state
#define SIG_RL 2

// Set all nodes to MESSAGE state (display their welcome message)
#define SIG_RMSG 3

// Begin an new game on the network (Set all nodes to GAME_UNASSIGNED state)
#define SIG_RNG 4

// End the network's current game (Set all nodes to LISTEN state)
#define SIG_RGG 5

// Unassign an assigned node if they are listening for the signal
#define SIG_RU 6

// User signals

// Set all devices in GAME_LISTEN_A state to GAME_TEAM_A state
#define SIG_UA 100

// Set all devices in GAME_LISTEN_B state to GAME_TEAM_B state
#define SIG_UB 101

#endif // SIGNALS_H