#include <array>
#include <cassert>
#include <exception>
#include <functional>
#include <iostream>
#include <vector>

#include "array.h"


class Foo {
public:
  int x;

  Foo(int n) : x{n} { std::cout << "Foo[" << x << "] ctor\n"; }
  ~Foo() { std::cout << "Foo[" << x << "] dtor\n"; }
};


int main() {









  return 0;
}
