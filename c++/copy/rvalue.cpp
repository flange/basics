#include <iostream>
#include <stdio.h>

class Foo {
public:
  int x;

  Foo(int n) : x{n} {
    //printf("x: %p\n", (void*) &x);
  }

  void foo() {
    std::cout << "foo lvalue\n";
  }

  void foo() const {
    std::cout << "foo const\n";
  }


};



int main() {

  Foo f{5};
  const Foo f2{11};

  std::move(f).foo();





  return 0;
}
