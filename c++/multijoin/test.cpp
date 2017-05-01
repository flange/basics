#include <iostream>
#include <thread>
#include <unistd.h>

void join(std::thread& t) {
  t.join();
}

template <typename T, typename... Ts>
void join(T& t, Ts&... ts) {
  t.join();
  join(ts...);
}

void thread(int id) {
  std::cout << "[" << id << "] start\n";
  sleep(3);
  std::cout << "[" << id << "] end\n";
}

int main() {

  std::thread t1{thread, 1}, t2{thread, 2}, t3{thread, 3}, t4{thread, 4};

  join(t1, t2, t3, t4);

  return 0;
}
