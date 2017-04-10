#include <iostream>

class Node {
public:
  int id;
  Node *next;

  Node(int n) : id{n}, next{nullptr} {}
};

void printList(Node *head) {

  Node *iter = head;

  std::cout << "[ ";

  while (iter != nullptr) {
    std::cout << iter->id << " ";
    iter = iter->next;
  }

  std::cout << "]\n";

  return;
}



bool hasLoop(Node *head) {

  Node *slow = head;
  Node *fast = head;

  while ((fast != nullptr) && (fast->next != nullptr)) {

    slow = slow->next;
    fast = (fast->next)->next;

    if (slow == fast)
      return true;
  }

  return false;
}


int main() {

  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);

  n1->next = n2;
  n2->next = n3;
  n3->next = n1;


  std::cout << (hasLoop(n3) ? "loop" : "sequence") << "\n";



  delete n1;
  delete n2;
  delete n3;

  return 0;
}
