#include <algorithm>
#include <iostream>
#include <vector>

#include <stdio.h>

template <class T>
void print(const std::vector<T> &vec) {

  for (const T &element : vec)
    std::cout << element << " ";

  std::cout << "\n";

  return;
}







int main() {

  int x = (int) getchar();

  std::cout << x << "\n";


  return 0;
}
