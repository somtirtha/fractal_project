#include <iostream>
#include <cstdint>
#include <memory>
#include <cmath>
#include "BitMapFileHeader.h"
#include "BitMapInfoHeader.h"
#include "BitMap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"

using namespace std;
using namespace fractalDesign;

int main() {
	int const WIDTH = 800;
	int const HEIGHT = 600;
	BitMap bitmap(WIDTH, HEIGHT);

	double min = 999999;
	double max = 999999;

	unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS] { 0 });
	unique_ptr<int[]> fractal(new int[WIDTH * HEIGHT] { 0 });

	// get Mandelbrot iterations and construct the histogram
	for (int y = 0; y < HEIGHT; ++y) {
		for (int x = 0; x < WIDTH; ++x) {
			double xFractal = (x - WIDTH / 2 - 220) * 2.0 / HEIGHT; // scaling by same factor on both axes to prevent the Mandelbrot fractal from stretching.
			double yFractal = (y - HEIGHT / 2) * 2.0 / HEIGHT;

			int iterations = Mandelbrot::getIterations(xFractal, yFractal);
			fractal[y * WIDTH + x] = iterations;
			/* getting rid of the iterations = MAX_ITERATIONS as histogram[MAX_ITERATIONS]
			 is large and it introduces a lot of noise in the image. */
			if (iterations != Mandelbrot::MAX_ITERATIONS) {
				histogram[iterations]++;
			}

		}
	}

	// get the total number of iterations
	int total = 0;
	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; ++i) {
		total += histogram[i];
	}

	// set bitmap pixels from histogram
	for (int y = 0; y < HEIGHT; ++y) {
		for (int x = 0; x < WIDTH; ++x) {

			uint8_t red = 0;
			uint8_t green = 0;
			uint8_t blue = 0;

			int iterations = fractal[y * WIDTH + x];

			if (iterations != Mandelbrot::MAX_ITERATIONS) {
				double hue = 0.0;
				for (int i = 0; i < iterations; ++i) {
					hue += (double) histogram[i] / total;
				}

				green = pow(255, hue);
			}

			bitmap.setPixel(x, y, red, green, blue);
//			if (color < min)
//				min = color;
//			if (color > max)
//				max = color;
		}
	}

	bitmap.write("images/test.bmp");

	cout << "Done" << endl;
	return 0;
}
