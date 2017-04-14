#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>


template <typename T>
void print(const T& t) {

  using value_type = typename T::value_type;

  for (const value_type& e : t)
    std::cout << e << " ";

  std::cout << std::endl;
}







template<class ForwardIt, class UnaryPredicate>
ForwardIt my_part(ForwardIt first, ForwardIt last, UnaryPredicate p)
{
    first = std::find_if_not(first, last, p);
    if (first == last) return first;

    for(ForwardIt i = std::next(first); i != last; ++i){
        if(p(*i)){
            std::iter_swap(i, first);
            ++first;
        }
    }
    return first;
}

bool even(const int& n) {
  return (n % 2) == 0;
}

bool less_than_five(const int& n) {
  return n < 5;
}

bool less(const int& a, const int& b) {

  std::cout << "less() a: " << a << " b: " << b << "\n";


  return (a < b);
}

/*
std::vector<int>::const_iterator lb(const std::vector<int>& r, int v) {
  return std::find_if_not(r.begin(), r.end(), std::bind(std::less<int>(), std::placeholders::_1, v));
}
*/

template <typename T>
typename T::const_iterator lb(const T& r, const int& v) {
  return std::find_if_not(r.begin(), r.end(), std::bind(std::less<int>(), std::placeholders::_1, v));
}

class Foo {

};


int main() {

  std::vector<int> vec{1, 2, 1, 2, 1, 2, 1, 2, 1, 2};

  std::vector<int> vec2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int> vec3{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

  //auto res = lb(vec2, 3);
  //std::cout << *res << "\n";

  Foo f;

  auto res = lb(f, 3);




  //auto uless = std::bind(less, 3, std::placeholders::_1);








  return 0;
}
