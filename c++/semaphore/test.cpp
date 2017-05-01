#include <condition_variable>
#include <iostream>
#include <mutex>

class Semaphore {
public:
  long count;
  std::mutex mutex;
  std::condition_variable cond;

  Semaphore(const long& init) : count{init} {}

  void get() {
    std::unique_lock<decltype(mutex)> lock{mutex};

    while(!count)
      cond.wait(lock);

    count--;
  }

  void put() {
    std::lock_guard<std::mutex> lg{mutex};
    count++;
    cond.notify_one();
  }
};

int main() {
  return 0;
}
