#include <iostream>
#include <map>
#include <string>

class Foo {
public:
  std::string id;

  Foo(const std::string& s) : id{s} {}
};

int main() {

  Foo f1{"foo1"};
  Foo f2{"foo2"};
  Foo f3{"foo3"};

  std::map<int, Foo> m;

  m.insert(f1);







  return 0;
}
