#ifndef __POINT_H__
#define __POINT_H__

#include <algorithm>
#include <string>
#include <sstream>

class Point {
public:
  int x;
  int y;

  Point() : x{0}, y{0} {}
  Point(const int& x, const int& y) : x{x}, y{y} {}
  Point(const Point& other) : x{other.x}, y{other.y} {}

  Point& operator=(const Point& other) {
    Point tmp{other};

    std::swap(x, tmp.x);
    std::swap(y, tmp.y);

    return *this;
  }

  friend bool operator==(const Point& a, const Point& b) {
    return (a.x == b.x) && (a.y == b.y);
  }

  friend bool operator!=(const Point& a, const Point& b) {
    return (a.x != b.x) || (a.y != b.y);
  }


  std::string toString() const {
    std::stringstream res;
    res << "(" << x << ", " << y << ")";

    return res.str();
  }

};

namespace Points {

  int distance(const Point& a, const Point& b) {
    return (std::abs(a.x - b.x) + std::abs(a.y - b.y));
  }

  bool less_x(const Point& a, const Point& b) {
    return (a.x < b.x);
  }

  bool less_y(const Point& a, const Point& b) {
    return (a.y < b.y);
  }
}





#endif // __POINT_H__
