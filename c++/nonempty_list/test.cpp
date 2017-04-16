#include <deque>
#include <iostream>
#include <functional>
#include <list>
#include <string>
#include <sstream>
#include <vector>
#include <experimental/optional>

struct null_t {};

template <typename T, typename U>
struct tl
{
    using head = T;
    using tail = U;
};

using my_list = tl<int, tl<int, tl<int, null_t> > >;


template <typename TList>
struct list_content;

template <typename Head, typename Tail>
struct list_content<tl<Head, Tail>> {
    using head = Head;
    using tail = Tail;
};

template <>
struct list_content<null_t> {
};

template <typename TList>
using head_t = typename list_content<TList>::head;

template <typename TList>
using tail_t = typename list_content<TList>::tail;



using my_list = tl<int, tl<int, tl<int, null_t> > >;

int main() {

  list_content<tl<int, null_t>> l;

  auto res = l.remove();

  return 0;
}
