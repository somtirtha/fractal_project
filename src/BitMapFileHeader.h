
#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

#include <cstdint>

/* this makes C++ align the data in 2 byte boundaries and prevents additional 
padding to align the data most efficiently */
#pragma pack(2) 

namespace fractalDesign {

struct BitMapFileHeader {
    char header[2]{'B', 'M'}; // initialization: only for c++11
    int32_t fileSize;
    int32_t reserved{0};
    int32_t dataOffset;
};

}

#endif