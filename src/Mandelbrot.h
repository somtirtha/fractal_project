#ifndef BITMAP_H_
#define BITMAP_H_

namespace designFractal {

class Mandelbrot {
public:
	static const int MAX_ITERATIONS = 100;
	
public:
	Mandelbrot();
	virtual ~Mandelbrot();

	static int getIteratons(double x, double y);
};

}


#endif