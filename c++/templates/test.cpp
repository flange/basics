#include <iostream>
#include <type_traits>


template <typename T, std::enable_if_t<
  std::is_arithmetic<T>::value>* = nullptr
>
T foo(T t) {
  return t++;
}

template <typename T>
T bar(T t) {
  static_assert(std::is_arithmetic<T>::value, "");
  return t++;
}








int main() {

  std::cout << foo<int>(3) << "\n";
  //std::cout << foo<std::string>("hi") << "\n";

  std::cout << bar<int>(5) << "\n";
  std::cout << bar<std::string>("hi") << "\n";



}
