#include <iostream>
#include <stdexcept>
#include <type_traits>

template <int N>
class ct_int {
public:
  const int value = N;

  friend std::ostream& operator<<(std::ostream& os, const ct_int<N>& n) {
    return os << n.value;
  }
};

template <int A, int B>
ct_int<A + B> operator+(const ct_int<A>&, const ct_int<B>&) {
  return ct_int<A + B>{};
}

template <int A, int B>
ct_int<A - B> operator-(const ct_int<A>&, const ct_int<B>&) {
  return ct_int<A - B>{};
}

template <int A, int B>
ct_int<A * B> operator*(const ct_int<A>&, const ct_int<B>&) {
  return ct_int<A * B>{};
}

template <int A, int B, std::enable_if_t<B != 0, int>* = nullptr>
ct_int<A / B> operator/(const ct_int<A>&, const ct_int<B>&) {
  return ct_int<A / B>{};
}

class rt_int {
public:
  int value;

  rt_int(const int& n) : value{n} {}

  friend std::ostream& operator<<(std::ostream& os, const rt_int& n) {
    return os << n.value;
  }
};

rt_int operator+(const rt_int& a, const rt_int& b) {
  return rt_int{a.value + b.value};
}

rt_int operator-(const rt_int& a, const rt_int& b) {
  return rt_int{a.value - b.value};
}

rt_int operator*(const rt_int& a, const rt_int& b) {
  return rt_int{a.value * b.value};
}

rt_int operator/(const rt_int& a, const rt_int& b) {

  if (b.value == 0)
    throw std::runtime_error{"div by 0"};

  return rt_int{a.value / b.value};
}

template <int N>
rt_int operator+(const rt_int& a, const ct_int<N>& b) {
  return rt_int{a.value + N};
}

template <int N, std::enable_if_t<N != 0, int>* = nullptr>
rt_int operator/(const rt_int& a, const ct_int<N>& b) {
  return rt_int{a.value / N};
}


int main() {

  rt_int a{5};
  ct_int<0> b;

  rt_int c = a / b;

  std::cout << c << std::endl;


  return 0;
}
