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

Foo createFoo() {
  Foo f1;
  std::cout << std::endl;

  return f1;
}

int main() {

  std::cout << "before block\n" << std::endl;

  {
    Foo f1 = createFoo();
  }

  std::cout << "\nafter block" << std::endl;


  return 0;
}
