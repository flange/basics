#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <array>
#include <memory>
#include <string>
#include <sstream>
#include <type_traits>

template <typename T, std::size_t N>
class Array {

private:
  std::shared_ptr<std::array<T, N>> m_array;

public:


  // Fundamental types have indetermined value in std::array.
  // -> Need to initialize manually.
  template<
    typename T_ = T,
      std::enable_if_t<std::is_fundamental<T_>::value
    >* = nullptr
  >
  explicit Array() : m_array{std::make_shared<std::array<T, N>>()}
  {
    m_array->fill(0);
  }

  template<
    typename T_ = T,
    std::enable_if_t<
      !std::is_fundamental<T_>::value
    >* = nullptr
  >
  explicit Array() : m_array{std::make_shared<std::array<T, N>>()}
  {}









  T& operator[](const std::size_t& index)
  {
    return *(m_array)[index];
  }






  std::string toString()
  {
    std::stringstream res;

    res << "[ ";

    for (const T& e : *m_array)
      res << e << " ";

    res << "]";

    return res.str();
  }








};

#endif // __ARRAY_H__
