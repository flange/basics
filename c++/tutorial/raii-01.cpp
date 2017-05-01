#include <iostream>

class Foo {
public:
  Foo() {
    std::cout << "  Foo ctor" << std::endl;
  }

  ~Foo() {
    std::cout << "  Foo dtor" << std::endl;
  }
};

int main() {

  std::cout << "before block" << std::endl;

  {
    Foo f;
  }

  std::cout << "after block" << std::endl;

  return 0;
}
