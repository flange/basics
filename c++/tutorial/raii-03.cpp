#include <iostream>

class Foo {
public:
  Foo() {
    std::cout << "  [" << this << "] Foo ctor" << std::endl;
  }

  ~Foo() {
    std::cout << "  [" << this << "] Foo dtor" << std::endl;
  }
};

class Bar {
public:
  Foo f1;
  Foo f2;
};

int main() {

  std::cout << "before block\n" << std::endl;

  {
    Bar b;
  }

  std::cout << "\nafter block" << std::endl;

  return 0;
}
