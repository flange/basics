#ifndef __LINE_H__
#define __LINE_H__

#include <algorithm>
#include <cassert>

#include "Point.h"

class Line {
public:

  Point a, b;
  bool is_vertical, is_horizontal;

  int min_x, x, max_x;
  int min_y, y, max_y;

  Line() {}

  Line(const Point& a, const Point& b)
  : a{a}, b{b},
    is_vertical{false}, is_horizontal{false},
    min_x{0}, x{0}, max_x{0},
    min_y{0}, y{0}, max_y{0}
  {
    if (a.x == b.x) {
      is_vertical = true;

      x = a.x;
      min_y = std::min(a.y, b.y);
      max_y = std::max(a.y, b.y);

      return;
    }

    if (a.y == b.y) {
      is_horizontal = true;

      y = a.y;
      min_x = std::min(a.x, b.x);
      max_x = std::max(a.x, b.x);

      return;
    }

    assert(true && "Line() is_diagonal");
  }

  Line(const Line& other) = default;
  Line& operator=(const Line& other) = default;


  friend bool operator==(const Line& l1, const Line& l2) {
    return (l1.a == l2.a) && (l1.b == l2.b);
  }


  std::string toString() const {
    std::stringstream res;
    res << a.toString() << " - " << b.toString();

    return res.str();
  }

  void printStats() const {
    std::stringstream res;

    res << toString() << ":\n";

    if (is_horizontal) {
      res << "  horizontal\n";
      res << "  y: " << y << "\n";
      res << "  min_x: " << min_x << "\n";
      res << "  max_x: " << max_x << "\n";
    }

    if (is_vertical) {
      res << "  vertical\n";
      res << "  x: " << x << "\n";
      res << "  min_y: " << min_y << "\n";
      res << "  max_y: " << max_y << "\n";
    }

    std::cout << res.str() << "\n";
  }

};

namespace Lines {

  bool parallel(const Line& l1, const Line& l2) {
    return (l1.is_vertical && l2.is_vertical) || (l1.is_horizontal && l2.is_horizontal);
  }

  bool intersect(const Line& l1, const Line& l2) {
    assert(!parallel(l1, l2));

    Line vertical, horizontal;

    if (l1.is_vertical) {
      vertical = l1;
      horizontal = l2;
    } else {
      vertical = l2;
      horizontal = l1;
    }

    if (
      ((vertical.min_y <= horizontal.y) && (horizontal.y <= vertical.max_y)) &&
      ((horizontal.min_x <= vertical.x) && (vertical.x <= horizontal.max_x))
    )
      return true;

    return false;
  }
}

#endif // __LINE_H__
