#include <iostream>

#include "Line.h"
#include "Point.h"
#include "PointCloud.h"
#include "BoundingBox.h"


namespace PointClouds {
  bool overlap(const PointCloud& pc1, const PointCloud& pc2) {
    BoundingBox b1{pc1};
    BoundingBox b2{pc2};

    return BoundingBoxes::overlap(b1, b2);
  }
}

int main() {

  Point p1{1, 2}, p2{3, 2}, p3{2, 1}, p4{2, 3};

  PointCloud pc1{{1, 1}, {2, 0}, {3, 1}, {2, 2}};
  PointCloud pc2{{4, 1}, {5, 0}, {6, 1}, {5, 2}};
  PointCloud pc3{{2, 2}, {3, 1}, {4, 2}, {3, 3}};
  PointCloud pc4{{2, 1}, {3, 0}, {4, 1}, {3, 3}};
  PointCloud pc5{{3, 1}, {4, 0}, {5, 1}, {4, 2}};




  std::cout << PointClouds::overlap(pc1, pc5) << "\n";


  return 0;
}
