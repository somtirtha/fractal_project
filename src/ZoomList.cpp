/*
 * ZoomList.cpp
 *
 *  Created on: Feb 3, 2017
 *      Author: somtirtha
 */

#include "ZoomList.h"
//#include <utility>

namespace fractalDesign {

ZoomList::ZoomList(int width, int height):  m_width(width), m_height(height){
	// TODO Auto-generated constructor stub

}

void ZoomList::add(const Zoom& zoom) {
	zoomList.push_back(zoom);
}

std::pair<double, double> ZoomList::doZoom(int x, int y) {
	return std::pair<double, double>(0,0);
}

} /* namespace fractalDesign */
