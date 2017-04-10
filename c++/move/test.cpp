#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <type_traits>
#include <vector>


class Foo {
public:
  explicit Foo(int n = -1);
  Foo(Foo& other);
  Foo(const Foo&& other);

  ~Foo();

  Foo& operator=(Foo& other);
  Foo& operator=(Foo&& other);



  int *_x;
};

Foo::Foo(int n) : _x{new int(n)}
{
  std::cout << "Foo ctor\n";
}

Foo::Foo(Foo& other) : _x{new int(*(other._x))}
{
  std::cout << "Foo copy ctor\n";
}

Foo::Foo(const Foo&& other) : _x{new int(*(other._x))}
{
  std::cout << "Foo move ctor\n";
}

Foo::~Foo()
{
  delete _x;
}

Foo& Foo::operator=(Foo& other)
{
  std::cout << "Foo copy assignment\n";

  Foo tmp{other};
  std::swap(_x, tmp._x);

  return *this;
}

Foo& Foo::operator=(Foo&& other)
{
  std::cout << "Foo move assignment\n";

  return *this;
}




Foo createFoo(int n)
{
  Foo f{n};
  return f;
}








template <typename T, typename = int>
struct has_x : std::false_type {};

template <typename T>
struct has_x<T, decltype((void) T::_x, 0)> : std::true_type {};


template <typename T, std::enable_if_t<has_x<T>::value, T>* = nullptr>
void print(const T& t)
{
  std::cout << *(t._x) << "\n";
  return;
}

template <typename T, typename... Ts, std::enable_if_t<has_x<T>::value, T>* = nullptr>
void print(const T& t, Ts... ts)
{
  std::cout << *(t._x) << "\n";
  print(ts...);
}








int main() {

  Foo f1{createFoo(3)};

  print(f1);











  return 0;
}
