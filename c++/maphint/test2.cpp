#include <iostream>
#include <vector>

template <typename T>
void print(const T& t) {

  std::cout << "\nprint():\n";

  for (const auto& e : t)
    std::cout << &e << " " << e.x << "\n";

  std::cout << std::endl;
  std::cout << std::endl;
}

class Foo {
public:

  int x;

  Foo(int n) : x{n} {
    std::cout << this << " Foo ctor\n";
  }

  Foo(const Foo& o) {
    std::cout << this << " Foo copy from " << &o << "\n";
    x = o.x;
  }

  Foo(const Foo&& o) {
    std::cout << this << " Foo move from " << &o << "\n";
    x = o.x;
  }

  Foo& operator=(const Foo& o) {
    std::cout << this << " Foo copy = from " << &o << "\n";
    x = o.x;

    return *this;
  }

  Foo& operator=(const Foo&& o) {
    std::cout << this << " Foo move = from " << &o << "\n";
    x = o.x;

    return *this;
  }

};

int main() {

  std::vector<Foo> vec;
  std::cout << "\n";

  //Foo f1{1};
  //Foo f2{2};
  std::cout << "\n";

//  vec.insert(vec.end(), f1);

  vec.emplace(vec.end(), 13);
  std::cout << "\n";



//  std::cout << "\n";


  print(vec);

  return 0;
}
