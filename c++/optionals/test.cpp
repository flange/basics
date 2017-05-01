#include <iostream>
#include <experimental/optional>
#include <string>
#include <type_traits>

using namespace std::experimental;

template <typename T>
class Optional {
public:

  optional<T> op;

  Optional() : op{} {}
  Optional(const T& t) : op{t} {}

  template <typename L1, typename L2>
  void match(L1&& some, L2&& none) {

    if (op)
      some(*op);
    else
      none();

  }


};


int main() {

  Optional<std::string> o1{"hallo"};
  Optional<std::string> o2;

  int len;

  o2.match(
    [&len](const auto& s) { len = s.size(); },
    [&len]() { len = 0; }
  );

  std::cout << len << "\n";

  o1.match(
    [](const auto& s) { std::cout << s << "\n"; },
    []() {}
  );


  return 0;
}
