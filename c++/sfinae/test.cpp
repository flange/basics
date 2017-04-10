#include <iostream>
#include <string>
#include <vector>



template <typename T>
T negate(T i) {
  std::cout << "yo\n";
  return -i;
}

template <typename T>
typename T::value_type negate(const T& t) {
  return -t();
}

int main() {

  std::cout << negate<int>(3) << "\n";

  return 0;
}




