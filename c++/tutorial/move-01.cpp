#include <iostream>

class Foo {
public:
  Foo() {
    std::cout << "  [" << this << "] Foo ctor" << std::endl;
  }

  Foo(const Foo& other) {
    std::cout << "  [" << this << "] Foo copy from " << &other << std::endl;
  }

  ~Foo() {
    std::cout << "  [" << this << "] Foo dtor" << std::endl;
  }

};

int main() {

  std::cout << "before block\n" << std::endl;

  {
    Foo{};
  }

  std::cout << "\nafter block" << std::endl;


  return 0;
}
