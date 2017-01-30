#ifndef BITMAPINFOHEADER_H_
#define BITMAPINFOHEADER_H_

#include <cstdint>

/* this makes C++ align the data in 2 byte boundaries and prevents additional 
padding to align the data most efficiently */
#pragma pack(2) 

namespace fractalDesign  {

struct BitMapInfoHeader {
    // add all the bytes in the member variables ( 32 = 4bytes; 4*9 + 4*2 = 40)
    int32_t headerSize{40}; // initialization: only for c++11
    int32_t width;
    int32_t height;
    int16_t planes{1};
    int16_t bitsPerPixel{24};
    int32_t compression{0}; // compression should be intialized for bitmap file to be written
    int32_t dataSize{0};
    int32_t horizontalResolution{2400};
    int32_t verticalResolution{2400};
    int32_t colors{0};
    int32_t importantColors{0};

};

}

#endif


