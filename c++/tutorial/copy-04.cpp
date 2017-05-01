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

  Foo& operator=(const Foo& other) {
    std::cout << "  [" << this << "] Foo copy assigned from " << &other << std::endl;

    return *this;
  }

};

int main() {

  std::cout << "before block\n" << std::endl;

  {
    Foo f1;
    Foo f2;
    std::cout << std::endl;

    f2 = f1;
    std::cout << std::endl;
  }

  std::cout << "\nafter block" << std::endl;


  return 0;
}
