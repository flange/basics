#include <iostream>
#include <memory>

class Node {
public:
  int id;
  std::shared_ptr<Node> next;

  Node(int n) : id{n} {
    std::cout << "Node() id: " << id << "\n";
  }

  ~Node() {
    std::cout << "~Node() id: " << id << "\n";
  }
};

void printList(std::shared_ptr<Node> head) {

  while (head != nullptr) {
    std::cout << head->id << " ";
    head = head->next;
  }

  std::cout << "\n";
}

bool hasLoop(std::shared_ptr<Node> &head) {

  std::shared_ptr<Node> slow = head;
  std::shared_ptr<Node> fast = head;

  while ((fast != nullptr) && (fast->next != nullptr)) {
    slow = slow->next;
    fast = (fast->next)->next;

    if (slow == fast)
      return true;
  }

  return false;
}

bool hasLoop2(std::shared_ptr<Node> &head) {

  std::shared_ptr<Node> slow = head;
  std::shared_ptr<Node> fast = head;

  std::shared_ptr<Node> last = nullptr;

  while ((fast != nullptr) && (fast->next != nullptr)) {
    slow = slow->next;
    fast = (fast->next)->next;

    if (slow->next == head)
      last = slow;

    if (slow == fast) {

      if (last)
        last->next = nullptr;

      return true;
    }
  }

  return false;
}

int main() {

  std::shared_ptr<Node> n1 = std::make_shared<Node>(1);

  {
    std::shared_ptr<Node> n2 = std::make_shared<Node>(2);
    std::shared_ptr<Node> n3 = std::make_shared<Node>(3);
    std::shared_ptr<Node> n4 = std::make_shared<Node>(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n1;
  }
/*
  std::cout << "n1 ref: " << n1.use_count() << "\n";
  std::cout << "n2 ref: " << (n1->next).use_count() << "\n";
  std::cout << "n3 ref: " << ((n1->next)->next).use_count() << "\n";
*/
  //printList(n1);

  std::cout << (hasLoop2(n1) ? "loop" : "sequence") << "\n";

  printList(n1);




  return 0;
}
