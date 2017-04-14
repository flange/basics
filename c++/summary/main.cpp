#include <algorithm>
#include <iostream>
#include <type_traits>
#include <utility>


class Foo {
public:
  int x;

  Foo() : x{-1} {}

  Foo(int n) : x{n} {
    std::cout << "Foo ctor: " << this << "\n";
  }

  Foo(const Foo& o) : x{o.x} {
    std::cout << "Foo copy ctor: " << this << "\n";
  }

  Foo(Foo&& o) : x{std::move(o.x)} {
    std::cout << "Foo move ctor: " << this << "\n";
  }

  ~Foo() {
    std::cout << "Foo dtor: " << this << "\n";
  }

  Foo& operator=(const Foo& o) {
    std::cout << "Foo& op=: " << this << "\n";

    Foo tmp{o};
    std::swap(x, tmp.x);

    return *this;
  }

  Foo& operator=(Foo&& o) {
    std::cout << "Foo&& op=: " << this << "\n";

    x = std::move(o.x);

    return *this;
  }



};




Foo createFoo() {
  std::cout << "createFoo\n";

  Foo f{11};
  return f;
}


int main() {

  Foo f1{3};
  Foo f2{5};
  std::cout << "\n\n";


  f2 = std::move(f1);
  std::cout << "\n\n";


  std::cout << f1.x << "\n";
  std::cout << f2.x << "\n";


  decltype(Foo(std::decltype(int()))) f3;


  std::cout << "\n\n";

  return 0;
}


