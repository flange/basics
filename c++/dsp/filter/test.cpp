#include <array>
#include <iostream>
#include <tuple>
#include <experimental/optional>
#include <functional>
#include <memory>
#include <vector>
#include <utility>
#include <string>
#include <sstream>

using namespace std::experimental;

using RawData = std::vector<double>;
using rdIter = RawData::const_iterator;

class Data {
public:
  std::shared_ptr<RawData> dptr;

  rdIter start;
  rdIter end;

  Data(const std::shared_ptr<RawData>& rdptr, const rdIter& start, const rdIter& end)
    : dptr{rdptr}, start{start}, end{end}
  {}

  std::string toStr() const {
    std::stringstream res;

    for (rdIter iter = start; iter != end; ++iter)
      res << *iter << " ";

    return res.str();
  }
};

class Stream {
public:

  std::shared_ptr<RawData> dptr;

  rdIter index;
  rdIter end;

  std::function<Data(const std::shared_ptr<RawData>& dptr, const rdIter& index)> f;

  Stream(const std::shared_ptr<RawData>& rdptr, const rdIter& start, const rdIter& end,
      std::function<Data(const std::shared_ptr<RawData>& dptr, const rdIter& index)> f)
    : dptr{rdptr}, index{start}, end{end}, f{f}
  {}


  optional<Data> next() {

    if (index == end)
      return optional<Data>{};

    Data res = f(dptr, index);
    index++;

    return optional<Data>{res};
  }

  void operator|(const std::function<void(const Data& d)> f) {
    while(optional<Data> d = next())
      f(*d);
  }

};

class SimpleStream {
public:

  std::shared_ptr<RawData> dptr;

  rdIter start;
  rdIter index;
  rdIter end;

  optional<std::function<double(const double&)>> _f;

  SimpleStream(const std::shared_ptr<RawData>& rdptr, const rdIter& start, const rdIter& end)
    : dptr{rdptr}, start{start}, index{start}, end{end}
  {}

  SimpleStream(const std::shared_ptr<RawData>& rdptr, const rdIter& start, const rdIter& end,
    std::function<double(const double&)> f)
    : dptr{rdptr}, index{start}, end{end}, _f{f}
  {}



  optional<double> next() {

    if (index == end)
      return optional<double>{};

    double res;

    if (_f)
      res = (*_f)(*index);
    else
      res = *index;

    index++;

    return optional<double>{res};
  }

  SimpleStream operator|(const std::function<double(const double&)>& func) {
    return SimpleStream{dptr, start, end, func};
  }

  void operator|(const std::function<void(const double& d)> f) {
    while(optional<double> d = next())
      f(*d);
  }

};

int main() {

  std::shared_ptr<RawData> rdptr = std::make_shared<RawData>(RawData{0, 1, 2, 3, 4});

  Stream ds{rdptr, rdptr->begin(), rdptr->end(),
    [](const auto& ptr, const auto& idx) {
      return Data{ptr, idx, idx + 1};
  }};

/*
  ds
  | [] (const Data& d) {std::cout << d.toStr() << "\n"; };
*/

  SimpleStream ss{rdptr, rdptr->begin(), rdptr->end()};

  ss
  | [] (const double& d) -> double { return 2 * d; }
  | [] (const double& d) {std::cout << d << "\n"; };

  return 0;
}
