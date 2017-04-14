#include <iostream>
#include <memory>
#include <experimental/optional>

#include "tree.h"


template <typename T>
class Wrapper {
public:

  T t;

  Wrapper(const T& o) : t{o} {}

  T& operator!() {
    std::cout << "Wrapper !\n";
    return t;
  }

  const T& operator&() {
    std::cout << "Wrapper &\n";
    return t;
  }



};


class Foo {
public:

  int x;

  Foo(int n) : x{n} {}


  Foo* operator!() {
    std::cout << "op!\n";
    return this;
  }


  const Foo* operator&() {
    std::cout << "op&\n";
    return this;
  }

};




/*
void foo(Foo f) {
  std::cout << "foo: copy\n";
  f.x = 13;
}


void foo(ptr<Foo> f) {
  std::cout << "foo: mut ref\n";

  f->x = 11;
}


void foo(const ptr<Foo> f) {
  std::cout << "foo: const ref\n";

  //f->x = 17; compile error
}
*/

template <typename T>
class ptr {
public:

  T _t;

  ptr(const int& n) : _t{n} {}

  T* operator!() {
    std::cout << "op!\n";
    return &_t;
  }


  const T* operator&() {
    std::cout << "op&\n";
    return &_t;
  }


};


template <typename T>
void foo(T t) {
  std::cout << "foo1\n";
}


template <typename T>
void foo(T&& t) {
  std::cout << "foo2\n";
}


int main() {

  std::shared_ptr<tree<int>::tree_node> n1 = std::make_shared<tree<int>::tree_node>(1);
  std::shared_ptr<tree<int>::tree_node> n2 = std::make_shared<tree<int>::tree_node>(2);
  std::shared_ptr<tree<int>::tree_node> n3 = std::make_shared<tree<int>::tree_node>(3);

  n2->left = n1;
  n2->right = n3;

  tree<int> t;
  t.root = n2;



  Foo f{3};

/*
  foo(f);
  std::cout << f.x << "\n\n";

  foo(&f);
  std::cout << f.x << "\n\n";

  foo(!f);
  std::cout << f.x << "\n";
*/




  return 0;
}
