#include <iostream>
#include <string>
#include <vector>
#include <type_traits>


template<typename T, typename = void>
struct is_iterator : std::false_type
{};

template<typename T>
struct is_iterator<T,
  typename std::enable_if<!std::is_same<typename std::iterator_traits<T>::value_type, void>::value>::type>
  : std::true_type
{};

int main() {

  std::cout << is_iterator<int>::value << "\n";
  std::cout << is_iterator<std::vector<int>::iterator>::value << "\n";





  return 0;
}
