/*
 * Zoom.h
 *
 *  Created on: Feb 3, 2017
 *      Author: somtirtha
 */

#ifndef SRC_ZOOM_H_
#define SRC_ZOOM_H_

namespace fractalDesign {

struct Zoom {
	int x { 0 };
	int y { 0 };
	double scale { 0.0 };
	Zoom(int x, int y, double scale) :x(x), y(y), scale(scale) {};
};

} /* namespace fractalDesign */

#endif /* SRC_ZOOM_H_ */
