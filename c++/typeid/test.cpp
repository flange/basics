#include <iostream>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>

std::unordered_map<std::type_index, std::string> tm;


class Bar {
public:
  virtual void foo() {
    std::cout << "bar\n";
  }
};

template <typename T>
class Foo : public Bar {
public:
  Foo() {
    //std::cout << "Foo ctor: " << typeid(*this).name() << "   " << typeid(T).name() << "\n";
    tm[std::type_index(typeid(*this))] = "Foo<" + tm[std::type_index(typeid(T))] + ">";
  }

  virtual void foo() {
    std::cout << "foo!\n";
  }

};

template <typename T>
void test(const Foo<T>& f) {

  if (tm[std::type_index(typeid(f))] == "Foo<int>") {
    std::cout << "Foo<int>\n";
    return;
  }

  if (tm[std::type_index(typeid(f))] == "Foo<string>") {
    std::cout << "Foo<string>\n";
    return;
  }

/*
  Match(tm[std::type_index(typeid(f))])

    | "Foo<int>", [&f]() {
      // do stuff with f : Foo<int>
    }

    | "Foo<string>" , [&f]() {
      // do stuff with f : Foo<string>
    }
  ;


*/

}


int main() {

  tm[std::type_index(typeid(int))] = "int";
  tm[std::type_index(typeid(std::string))] = "string";

  std::string input;
  std::getline(std::cin, input);

  Bar *b;

  if (input == "0")
    b = new Foo<int>();
  else
    b = new Foo<std::string>();

  std::cout << tm[std::type_index(typeid(*b))] << "\n";

  int x;

  std::cout << typeof(x) << "\n";

  delete b;

  return 0;
}
