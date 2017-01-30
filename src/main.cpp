
#include <iostream>
#include "BitMapFileHeader.h"
#include "BitMapInfoHeader.h"
#include "BitMap.h"

using namespace std;
using namespace fractalDesign;


int main() {
	int const WIDTH = 800;
	int const HEIGHT = 600;
    BitMap bitmap(WIDTH, HEIGHT);

    double min = 999999;
    double max = 999999;
    for(int y=0; y<WIDTH; ++y) {
    	for(int x=0; x<HEIGHT; ++x) {
    		double xFractal = (x - HEIGHT/2)*2.0/HEIGHT;
    		double yFractal = (r - WIDTH/2)*2.0/WIDTH;

    		if(xFractal < min) min = xFractal;
    		if(xFractal < max) max = xFractal;
    	}	
    }
    bitmap.write("images/test.bmp");

    cout << "Done" << endl;
    return 0;
}