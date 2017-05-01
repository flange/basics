#include <iostream>
#include <vector>

int main() {

  std::vector<int> v{0, 1, 2, 3, 4};

  std::cout << v.size() << "\n";

  std::cout << *(v.begin() + (v.size() - 1)) << "\n";

}
