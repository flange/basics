#include <iostream>
#include <string>
#include <type_traits>
#include <vector>


// base case : gilt für wirklich alles
template <typename T, typename = int>
struct HasX : std::false_type {};

// success case
template <typename T>
struct HasX <T, decltype((void) T::x, 0)> : std::true_type {
};

struct A {
  int x;
};

struct B {
  bool f;
};






template <typename T>
struct is_int : std::false_type {};

template <>
struct is_int<int> : std::true_type {};




template<typename U>
struct ClassName
{
private:
  template<typename>
  static constexpr std::false_type test(...);

  template<typename T = U>
  static decltype((Expr), std::true_type{}) test(int) ;

public:
  static constexpr bool value = decltype(test<U>(0))::value;
};










int main() {







  return 0;
}
