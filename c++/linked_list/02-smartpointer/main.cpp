#include <iostream>
#include <memory>

class Node {
public:
  int id;
  std::weak_ptr<Node> next;

  Node(int n) : id{n} {}
};




int main() {

  std::weak_ptr<Node> n1 = std::make_shared<Node>(1);
  std::weak_ptr<Node> n2 = std::make_shared<Node>(2);

  {
    auto n1s = n1.lock();
    n1s->next = n2;

    auto n2s = n2.lock();
    n2s->next = n1;
  }



  return 0;
}
