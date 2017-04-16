#include <iostream>
#include <string>
#include <vector>
#include <type_traits>

class A {
public:
  int x;
};

class B {
};

template <typename T, typename = int>
struct has_iterator : std::false_type {};

template <typename T>
struct has_iterator<T, decltype((void) T::x, 0)> : std::true_type {};


int main() {

  std::cout << has_iterator<A>::value << "\n";
  std::cout << has_iterator<B>::value << "\n";




  return 0;
}
