#include <iostream>
#include <map>

void print(const std::map<int, char>& m) {
  for (const std::pair<int, char>& p : m)
    std::cout << p.first << " - " << p.second << "\n";
}

void print(const std::map<int, char>::iterator& it) {
  std::cout << it->first << " - " << it->second << "\n";
}

int main() {

  std::map<int, char> m;

  m[1] = 'a';
  m[3] = 'b';
  m[5] = 'c';

  int x = 4;
  char c = 'd';

  m.emplace(x, c);

  print(m);


  // lower bound: stelle wo key sein müsste
  // upper bound: 1. stelle nach dem key

  return 0;
}
