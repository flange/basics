#ifndef __BOUNDINGBOX_H__
#define __BOUNDINGBOX_H__

#include <string>
#include <sstream>

#include "Line.h"
#include "Point.h"
#include "PointCloud.h"


class BoundingBox {
public:

  Point ll, ul, ur, lr;
  Line a, b, c, d;

  BoundingBox(const PointCloud& pc)
    : ll{pc.min_x(), pc.min_y()}, ul{pc.min_x(), pc.max_y()},
      ur{pc.max_x(), pc.max_y()}, lr{pc.max_x(), pc.min_y()},
      a{ll, ul}, b{ul, ur}, c{ur, lr}, d{lr, ll}
  {}

  std::string toString() const {
    std::stringstream res;

    res << ul.toString() << " --- " << ur.toString() << "\n";
    res << "  |          |\n";
    res << "  |          |\n";
    res << ll.toString() << " --- " << lr.toString();

    return res.str();
  }

};



namespace BoundingBoxes {

  bool overlap(const BoundingBox& b1, BoundingBox& b2) {

    if (Lines::intersect(b1.a, b2.b) ||
        Lines::intersect(b1.a, b2.d) ||

        Lines::intersect(b1.b, b2.a) ||
        Lines::intersect(b1.b, b2.c) ||

        Lines::intersect(b1.c, b2.d) ||
        Lines::intersect(b1.c, b2.b) ||

        Lines::intersect(b1.d, b2.a) ||
        Lines::intersect(b1.d, b2.c)
    )
      return true;

    return false;
  }
}



#endif // __BOUNDING_BOX_H__
