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

/*
    This header filed declares references to a a number of useful
    MicroBitImage objects. 
*/

#ifndef IMAGES_H
#define IMAGES_H "images.h"

#include "MicroBitImage.h"

namespace ECG {

struct Images {

// Stages of broadcast/download animation
static MicroBitImage& centerRing ;
static MicroBitImage& middleRing ;
static MicroBitImage& outerRing ;

// A smile (currently unused)
static MicroBitImage& smile ;

// Shapes used for team identification
static MicroBitImage& square_hollow ;
static MicroBitImage& square_filled ;
static MicroBitImage& triangle_hollow ;
static MicroBitImage& triangle_filled ;

// Arrows used for user direction
static MicroBitImage& left_arrow ;
static MicroBitImage& right_arrow ;

} ; // struct Images

} // namespace ECG

#endif // IMAGES_H