#include <chrono>
#include <iostream>
#include <ctime>
#include <vector>

#define NUM_ITEMS 50000

int main() {

  std::vector<int> vec;
  std::vector<int>::iterator iter;

  std::srand(std::time(0));

  std::chrono::duration<double> duration;
  std::chrono::time_point<std::chrono::steady_clock> start;
  std::chrono::time_point<std::chrono::steady_clock> stop;




  start = std::chrono::steady_clock::now();

  for (int i = 0; i < NUM_ITEMS; i++) {
    int n = std::rand() % NUM_ITEMS;

    for (iter = vec.begin(); iter != vec.end(); ++iter) {
      if (*iter > n)
        break;
    }

    vec.insert(iter, n);
  }

  stop = std::chrono::steady_clock::now();

  duration = stop - start;
  std::cout << duration.count() << "\t";



  start = std::chrono::steady_clock::now();

  for (int i = 0; i < NUM_ITEMS; i++) {
    int n = std::rand() % vec.size();

    vec.erase(vec.begin() + n);
  }

  stop = std::chrono::steady_clock::now();

  duration = stop - start;
  std::cout << duration.count() << "\n";


  return 0;
}

/*
  auto start = std::chrono::system_clock::now();


auto end = std::chrono::system_clock::now();
auto elapsed = end - start;
std::cout << elapsed.count() << '\n';
*/
