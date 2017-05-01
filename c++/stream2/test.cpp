#include <experimental/optional>
#include <functional>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <thread>
#include <utility>
#include <vector>

#include <unistd.h>

using namespace std::experimental;

using Data = std::vector<double>;
using dPtr = std::shared_ptr<Data>;
using dIter = std::vector<double>::iterator;
using wSize = std::size_t;
using Range = std::pair<dIter, dIter>;


class Window {
public:
  dPtr dptr;
  dIter _begin, _end;

  Window(const dPtr& ptr)
    : dptr{ptr}, _begin{ptr->begin()}, _end{ptr->end()}
  {}

  Window(const dPtr& ptr, const dIter& b, const dIter& e)
    : dptr{ptr}, _begin{b}, _end{e}
  {}

  dIter begin() const {
    return _begin;
  }

  dIter end() const {
    return _end;
  }

  std::string toStr() const {
    std::stringstream res;

    for (const double& d : *this)
      res << d << " ";

    return res.str();
  }
};

class WindowIterator {
public:
  dPtr dptr;
  dIter begin, end;
  wSize ws;

  WindowIterator(const dPtr& ptr, const wSize& ws)
    : dptr{ptr}, begin{ptr->begin()}, end{ptr->begin() + ws}, ws{ws}
  {}

  optional<Window> next() {

    if (end > dptr->end())
      return optional<Window>{};

    return Window{dptr, begin++, end++};
  }

};

using wIter = WindowIterator;

class Filter1 {
public:
  dPtr in_ptr, out_ptr;

  double filter_comp(const Window& w) {
    double res = 0;

    for (const double& d : w)
      res += 0.5 * d;

    return res;
  }

  Filter1(const dPtr& ptr)
    : in_ptr{ptr}, out_ptr{std::make_shared<Data>(ptr->size() - 1)}
  {
    wIter in_iter{in_ptr, 2};
    dIter out_iter{out_ptr->begin()};

    while (optional<Window> w = in_iter.next())
      *(out_iter++) = filter_comp(*w);
  }

  dPtr getResult() {
    return out_ptr;
  }

};


int main() {

  std::shared_ptr<Data> data = std::make_shared<Data>(Data{0, 1, 2, 3, 4});

  Filter1 f{data};

  wIter witer{f.getResult(), 1};

  while (optional<Window> w = witer.next())
    std::cout << w->toStr() << "\n";


  return 0;
}
