#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

template <typename T>
struct is_void {
  static const bool value = false;
};

template <>
struct is_void<void> {
  static const bool value = true;
};




template <typename T>
struct is_const {
  static const bool value = false;
};

template <typename T>
struct is_void<const T> {
  static const bool value = true;
};




int main() {

  std::cout << std::integral_constant<bool, false>::value << "\n";
  std::cout << std::integral_constant<int, 3>::value << "\n";

  std::cout << std::false_type::value << "\n";







  return 0;
}
