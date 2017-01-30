#ifndef BITMAP_H_
#define BITMAP_H_

#include <string>
#include <cstdint>

namespace fractalDesign {

class BitMap {
private:
    int m_width{0}; // initialization: only for c++11
    int m_height{0};
    std::unique_ptr<uint8_t[]> m_pPixels{nullptr};

public:
    BitMap(int width, int height);
    void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
    bool write(std::string filename);
    virtual ~BitMap(); 

};

} // namespace fractalDesign

#endif