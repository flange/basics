#include <algorithm>
#include <iostream>
#include <cassert>
#include <cmath>
#include <functional>
#include <limits>
#include <string>
#include <sstream>
#include <utility>
#include <vector>


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

  Point& operator=(Point&& other) {

    std::swap(x, other.x);
    std::swap(y, other.y);

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

class Line {
public:

  Point a, b;

  int x, y;
  bool is_vertical, is_horizontal, is_diagonal;

  Line() {}

  Line(const Point& a, const Point& b)
  : a{a}, b{b}, is_vertical{false}, is_horizontal{false}, is_diagonal{false}
  {
    assert(a != b && "Line(): end points need to be different");

    if (a.x == b.x) {
      x = a.x;
      is_vertical = true;
      return;
    }

    if (a.y == b.y) {
      y = a.y;
      is_horizontal = true;
      return;
    }

    is_diagonal = true;
  }

  Line(const Line& other) = default;

  Line& operator=(const Line& other) {
    Line tmp{other};

    std::swap(a, tmp.a);
    std::swap(b, tmp.b);
    std::swap(is_vertical, tmp.is_vertical);
    std::swap(is_horizontal, tmp.is_horizontal);

    if (is_vertical)
      std::swap(x, tmp.x);
    else if (is_horizontal)
      std::swap(y, tmp.y);

    return *this;
  }


  friend bool operator==(const Line& l1, const Line& l2) {
    return (l1.a == l2.a) && (l1.b == l2.b);
  }


  std::string toString() const {
    std::stringstream res;

    res << a.toString() << " -- " << b.toString();

    return res.str();
  }

};


int distance(const Point& a, const Point& b)
{
  return (std::abs(a.x - b.x) + std::abs(a.y - b.y));
}

void closest_pair_bf(const std::vector<Point>& pvec)
{
  std::pair<Point, Point> closest;

  int dist;
  int min_distance = std::numeric_limits<int>::max();

  for (auto it_a = pvec.begin(); it_a != (pvec.end() - 1); ++it_a) {
    for (auto it_b = (it_a + 1); it_b != pvec.end(); ++it_b) {

      std::cout << "a: " << it_a->toString() << " b: " << it_b->toString() << " d: " << distance(*it_a, *it_b) << "\n";

      dist = distance(*it_a, *it_b);

      if (dist < min_distance) {
        min_distance = dist;
        closest.first = *it_a;
        closest.second = *it_b;
      }

    }
    std::cout << "\n";
  }

  std::cout << "closest points: " << closest.first.toString() << " - " << closest.second.toString() << "\n";
}

bool lines_parallel(const Line& l1, const Line& l2) {
  return (l1.is_vertical && l2.is_vertical) || (l1.is_horizontal && l2.is_horizontal);
}

bool lines_intersect(const Line& l1, const Line& l2)
{
  if (lines_parallel(l1, l2)) // includes l1 == l2
    return false;

  if (l1.is_vertical && l2.is_horizontal) {

    if (!((l2.a.x < l1.x) && (l1.x < l2.b.x)))
      return false;

    if (!((l1.a.y < l2.y) && (l2.y < l1.b.y)))
      return false;

    return true;
  }

  if (l1.is_horizontal && l2.is_vertical) {

    if (!((l1.a.x < l2.x) && (l1.x < l1.b.x)))
      return false;

    if (!((l2.a.y < l1.y) && (l1.y < l2.b.y)))
      return false;

    return true;
  }

  return false;
}


void print(const std::vector<Point>& pvec) {
  for (const Point& p : pvec)
    std::cout << p.toString() << " ";

  std::cout << std::endl;
}

void partition_by_x(std::vector<Point>& pvec, const int& xval)
{
  std::partition(pvec.begin(), pvec.end(), [&xval](const Point& p) {
    return p.x < xval;
  });
}

int min_x(const std::vector<Point>& pvec)
{
  auto min_elem = std::min_element(pvec.begin(), pvec.end(), [](const Point& a, const Point& b) {
    return a.x < b.x;
  });

  return min_elem->x;
}


std::array<int, 4> find_boundaries(const std::vector<Point>& pvec)
{
  int min_x{std::numeric_limits<int>::max()};
  int max_x{std::numeric_limits<int>::min()};

  int min_y{std::numeric_limits<int>::max()};
  int max_y{std::numeric_limits<int>::min()};

  for (const Point& p : pvec) {
    if (p.x < min_x)
      min_x = p.x;

    if (p.x > max_x)
      max_x = p.x;

    if (p.y < min_y)
      min_y = p.y;

    if (p.y > max_y)
      max_y = p.y;
  }

  return std::array<int, 4>{min_x, max_x, min_y, max_y};
}

class BoundingBox {
public:

  Line a, b, c, d;
  Point ll, ul, ur, lr;

  BoundingBox(const std::vector<Point>& pvec) {

    auto minmax = find_boundaries(pvec);

    int min_x = minmax[0];
    int max_x = minmax[1];
    int min_y = minmax[2];
    int max_y = minmax[3];

    ll = Point{min_x, min_y};
    ul = Point{min_x, max_y};
    ur = Point{max_x, max_y};
    lr = Point{max_x, min_y};

    a = Line{ll, ul};
    b = Line{ul, ur};
    c = Line{ur, lr};
    d = Line{lr, ll};
  }

  std::string toString() const {
    std::stringstream res;

    res << ul.toString() << " " << ur.toString() << "\n";
    res << ll.toString() << " " << lr.toString();

    return res.str();;
  }

};

bool bbox_intersect(const BoundingBox& b1, const BoundingBox& b2) {

  if (lines_intersect(b1.a, b2.b) ||
      lines_intersect(b1.a, b2.d) ||

      lines_intersect(b1.b, b2.a) ||
      lines_intersect(b1.b, b2.c) ||

      lines_intersect(b1.c, b2.b) ||
      lines_intersect(b1.c, b2.d) ||

      lines_intersect(b1.d, b2.a) ||
      lines_intersect(b1.d, b2.c))
    return true;

  return false;
}


int main()
{
  //std::vector<Point> pvec{{1, 1}, {2, 2}, {2, 3}, {3, 4}, {4, 2}, {4, 5}};

  //Point p1{1, 1}, p2{1, 3}, p3{0, 2}, p4{2, 2}, p5{0,0}, p6{2, 0}, p8{4, 2};


  std::vector<Point> pvec1{{0, 0}, {2, 1}};
  std::vector<Point> pvec2{{1, 0}, {3, 1}};

  BoundingBox b1{pvec1};
  BoundingBox b2{pvec2};

  std::cout << b1.toString() << "\n\n";
  std::cout << b2.toString() << "\n\n";


  std::cout << bbox_intersect(b1, b2) << "\n\n";

  std::cout << b1.b.toString() << "\n";
  std::cout << b2.a.toString() << "\n";



  return 0;
}
