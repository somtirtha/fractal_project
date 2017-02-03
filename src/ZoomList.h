/*
 * ZoomList.h
 *
 *  Created on: Feb 3, 2017
 *      Author: somtirtha
 */

#ifndef SRC_ZOOMLIST_H_
#define SRC_ZOOMLIST_H_

#include "Zoom.h"
#include <vector>
#include <utility>

namespace fractalDesign {

class ZoomList {
private:
	int m_width{0};
	int m_height{0};
	std::vector<Zoom> zoomList;

public:
	ZoomList(int width, int height);
	void add(const Zoom& zoom);
	std::pair<double, double> doZoom(int x, int y);

};

} /* namespace fractalDesign */

#endif /* SRC_ZOOMLIST_H_ */
