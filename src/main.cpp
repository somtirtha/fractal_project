
#include <iostream>
#include <cstdint>
#include "BitMapFileHeader.h"
#include "BitMapInfoHeader.h"
#include "BitMap.h"
#include "Mandelbrot.h"

using namespace std;
using namespace fractalDesign;


int main() {
	int const WIDTH = 800;
	int const HEIGHT = 600;
    BitMap bitmap(WIDTH, HEIGHT);

    double min = 999999;
    double max = 999999;
    for(int y=0; y<HEIGHT; ++y) {
    	for(int x=0; x<WIDTH; ++x) {
    		double xFractal = (x - WIDTH/2)*2.0/WIDTH;
    		double yFractal = (y - HEIGHT/2)*2.0/HEIGHT;

            int iterations = Mandelbrot::getIterations(xFractal, yFractal);
            uint8_t red = (uint8_t)(256*(double)iterations/Mandelbrot::MAX_ITERATIONS);

            bitmap.setPixel(x, y, red, 0, 0);
    		if(red < min) min = red;
    		if(red > max) max = red;
    	}	
    }
    bitmap.write("images/test.bmp");

    cout << "Done" << endl;
    return 0;
}