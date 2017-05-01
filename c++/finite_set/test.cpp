#include <deque>
#include <iostream>
#include <functional>
#include <list>
#include <string>
#include <sstream>
#include <vector>
#include <experimental/optional>

template <int N>
class Int {
public:
  static const int value = N;

  friend std::ostream& operator<<(std::ostream& os, const Int& n) {
    return os << n.value;
  }
};






int main() {



  return 0;
}
