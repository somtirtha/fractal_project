
#include "BitMap.h"
#include <fstream>
#include <string>
#include "BitMapInfoHeader.h"
#include "BitMapFileHeader.h" 

using namespace fractalDesign;
using namespace std;

namespace fractalDesign {

BitMap::BitMap(int width, int height): m_width(width), m_height(height), m_pPixels(new uint8_t[width*height*3]{}) {

}

void BitMap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
	uint8_t *pPixel = m_pPixels.get();
	pPixel += (y*3)*m_width + (x*3);
	pPixel[0] = blue;
	pPixel[1] = green;
	pPixel[2] = red;
}

bool BitMap::write(std::string filename) {
	BitMapFileHeader fileHeader;
	BitMapInfoHeader infoHeader;

	fileHeader.fileSize = sizeof(BitMapFileHeader) + sizeof(BitMapInfoHeader) + m_height*m_width*3;
	fileHeader.dataOffset = sizeof(BitMapFileHeader) + sizeof(BitMapInfoHeader);

	infoHeader.width = m_width;
	infoHeader.height = m_height;

	ofstream file;
	file.open(filename, ios::out|ios::binary);

	if(!file) {
		return false;
	}

	file.write((char *)&fileHeader, sizeof(fileHeader));
	file.write((char *)&infoHeader, sizeof(infoHeader));
	file.write((char *)m_pPixels.get(), m_width*m_height*3);

	file.close();

	if(!file) {
		return false;
	}

    return true;
}

BitMap::~BitMap() {

}


} // namespace fractalDesign