#include <iostream>
#include <memory>

class Node {
public:
  int id;
  std::weak_ptr<Node> next;

  Node(int n) : id{n} {}
};


