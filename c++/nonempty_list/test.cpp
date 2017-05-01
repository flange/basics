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


template <int... Ns>
struct list {};

template <int N, int... Ns>
class list<N, Ns...>  {
public:

  Int<N> head;
  list<Ns...> tail;

  template <int T>
  list<N, Ns..., T> append(const Int<T>&) {
    return list<N, Ns..., T>{};
  }

  std::string toString() const {
    std::stringstream res;

    res << N << " ";
    res << tail.toString();

    return res.str();
  }

  friend std::ostream& operator<<(std::ostream& os, const list<N, Ns...>& l) {
    os << "[ ";
    os << l.toString();
    return os << "]";
  }

};

template <>
class list<> {
public:
  template <int N>
  list<N> append(const Int<N> &) {
    return list<N>{};
  }

  std::string toString() const {
    return "";
  }

  friend std::ostream& operator<<(std::ostream& os, const list<>&) {
    return os << "[]";
  }
};

int main() {

  list<> l;
  std::cout << l << "\n";

  list<1> l1 = l.append(Int<1>{});
  std::cout << l1 << "\n";

  list<1, 2> l2 = l1.append(Int<2>{});
  std::cout << l2 << "\n";

  auto l3 = l2.tail;
  std::cout << l3 << "\n";

  return 0;
}
