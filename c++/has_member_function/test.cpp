#include <iostream>
#include <string>
#include <vector>
#include <type_traits>


template <typename T>
struct hasEmpty {

  template <typename U, bool (U::*)() const>
  struct sfinae {};

  template <typename U>
  static char test(sfinae<U, &U::empty>*);

  template <typename U>
  static int test(...);

  static const bool value = sizeof(test<T>(nullptr)) == sizeof(char);
};



class Foo {
public:
  bool empty() const;
};

class Bar {
public:
  int empty();
};

int main() {

  //std::cout << has_iterator<A>::value << "\n";

  std::cout << hasEmpty<Foo>::value << "\n";
  std::cout << hasEmpty<Bar>::value << "\n";


  return 0;
}
