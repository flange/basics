#include <iostream>
#include <stdio.h>

class Foo {
public:
  int x;

  Foo(int n) : x{n} {
    printf("x: %p\n", (void*) &x);
  }

  int& get() {
    return x;
  }
};


int main() {

  Foo f{3};

  int a = f.get();
  std::cout << "a: " << a << "\n";

  a = 11;
  std::cout << "a: " << a << "\n";
  std::cout << "x: " << f.get() << "\n\n";


  int& b = f.get();
  std::cout << "b: " << b << "\n";

  b = 13;
  std::cout << "b: " << b << "\n";
  std::cout << "x: " << f.get() << "\n";

  return 0;
}
