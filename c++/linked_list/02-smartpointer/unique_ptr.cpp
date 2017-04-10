#include <iostream>
#include <memory>

class Node {
public:
  int id;
  std::unique_ptr<Node> next;

  Node(int n) : id{n} {
    std::cout << "Node() id: " << id << "\n";
  }

  ~Node() {
    std::cout << "~Node() id: " << id << "\n";
  }
};

void printList(const Node *head) {

  if (!head)
    std::cout << "printList(): head nullptr\n\n";

  while (head != nullptr) {
    std::cout << head->id << " ";
    head = (head->next).get();
  }

  std::cout << "\n";

  return;
}

bool hasLoop(const Node *head) {

  if (!head)
    std::cout << "printList(): head nullptr\n\n";

  const Node *slow = head;
  const Node *fast = head;

  while ((fast != nullptr) && (fast->next != nullptr)) {
    slow = (slow->next).get();
    fast = ((fast->next)->next).get();

    if (slow == fast)
      return true;
  }

  return false;
}

void test(std::shared_ptr<const Node> head) {

  const Node *iter = head.get();

  while (iter != nullptr) {
    std::cout << iter->id << " ";
    iter = (iter->next).get();
  }

  std::cout << "\n";

  return;
}

int main() {

  std::unique_ptr<Node> n1 = std::make_unique<Node>(1);

  n1->next = std::make_unique<Node>(2);
  (n1->next)->next = std::make_unique<Node>(3);

  std::cout << "\n";
  //printList(n1.get());
  //std::cout << (hasLoop(n1.get()) ? "loop" : "sequence") << "\n";

  std::shared_ptr<Node> s1 = std::move(n1);

  if (!n1)
    std::cout << "unique zugang null\n";

  std::shared_ptr<Node> s2 = s1;
  std::cout << "head ref: " << s1.use_count() << "\n\n";

  printList(s1.get());

  s1 = nullptr;
  std::cout << "head ref: " << s2.use_count() << "\n\n";

  test(s2);



  return 0;
}
