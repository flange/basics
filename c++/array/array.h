#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <sstream>
#include <type_traits>

template <typename T, std::size_t N>
class Array {

private:
  T m_data[N];

public:
  class iterator {
    friend class Array;

  public:
    iterator() : m_iter{nullptr} {}
    iterator(const iterator& other) : m_iter{other.m_iter} {}

  private:
    iterator(T* t) : m_iter{t} {}

  public:
    T& operator=(const T& other) {
      iterator tmp{other};
      std::swap(m_iter, tmp.m_iter);

      return *this;
    }

    T operator*() {
      return *m_iter;
    }

    iterator& operator++() {
      m_iter++;
      return *this;
    }

    iterator operator++(int) {
      iterator tmp{*this};
      m_iter++;

      return tmp;
    }

    bool operator==(const iterator& other) {
      return (m_iter == other.m_iter);
    }

    bool operator!=(const iterator& other) {
      return (m_iter != other.m_iter);
    }

    friend std::ostream& operator<<(std::ostream& os, const iterator& iter) noexcept {
      return os << *(iter.m_iter);
    }

  private:
    T* m_iter;
  };

  explicit Array() : m_data{} {}

  iterator begin() {
    iterator b{m_data};
    return b;
  }

  iterator end() {
    iterator e{m_data + N};
    return e;
  }



  T& operator[](const std::size_t& index)
  {
    return m_data[index];
  }




  std::string toString()
  {
    std::stringstream res;

    res << "[ ";

    for (int i = 0; i < N; ++i)
      res << m_data[i] << " ";

    res << "]";

    return res.str();
  }

};



#endif // __ARRAY_H__
