#include <iostream>
#include <typeinfo>
#include <type_traits>


template<typename... Args>
class List;

template<typename T>
class List<T>
{
public:
  using type = T;

  List(T t) : t{t} {}

  T head() {
    return t;
  }

  List<T, T> append(T n) {
    List<T> base;
    base.t = t;

    List<T, T> res;
    res.t = n;
    res.next = base;

    return res;
  }

  T t;
  const std::nullptr_t next = nullptr;
};

template<typename T, typename... Ts>
class List<T, Ts...>
{
public:
  using head_type = T;

  List(T head, Ts... tail) {

  }


  T t;
  List<Ts...> *next;


};



int main()
{

  List<int> l{11};

  List<int, int> ll{11, 5};


  return 0;
}
