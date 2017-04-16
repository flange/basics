#ifndef __POINTCLOUD_H__
#define __POINTCLOUD_H__

#include <algorithm>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#include "Point.h"


class BoundingBox;

namespace BoundingBoxes {
  bool overlap(const BoundingBox& b1, BoundingBox& b2);
}

class PointCloud {
public:
  std::vector<Point> pcloud;

  std::pair<int, int> minmax_x;
  std::pair<int, int> minmax_y;

  PointCloud(const std::initializer_list<Point>& l) : pcloud{l} {

    auto pminmax_x = std::minmax_element(pcloud.begin(), pcloud.end(), Points::less_x);
    minmax_x.first = pminmax_x.first->x;
    minmax_x.second = pminmax_x.second->x;

    auto pminmax_y = std::minmax_element(pcloud.begin(), pcloud.end(), Points::less_y);
    minmax_y.first = pminmax_y.first->y;
    minmax_y.second = pminmax_y.second->y;
  }

  int min_x() const {
    return minmax_x.first;
  }

  int max_x() const {
    return minmax_x.second;
  }

  int min_y() const {
    return minmax_y.first;
  }

  int max_y() const {
    return minmax_y.second;
  }


  std::string toString() {
    std::stringstream res;

    for (const Point& p : pcloud)
      res << p.toString() << " ";

    return res.str();
  }


};




#endif // __POINTCLOUD_H__
