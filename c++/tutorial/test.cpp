#include <iostream>
#include <future>
#include <mutex>
#include <string>
#include <sstream>

#define NUM_COUNT 100000

class Counter {
private:
  int x;
  std::mutex _m;

public:
  explicit Counter() : x{0} {}

  Counter(Counter& other) {
    x = other.get();
  }

  Counter(Counter&& other) {
    Counter tmp{other};
    std::swap(x, tmp.x);
  }

  Counter& operator=(Counter& other) {
    x = other.get();
    return *this;
  }

  Counter& operator=(Counter&& other) {
    x = other.get();
    return *this;
  }

  int get() {
    std::lock_guard<std::mutex> lg{_m};
    return x;
  }

  Counter operator++(int) {
    std::lock_guard<std::mutex> lg{_m};
    x++;
  }

  std::string toString() {
    std::lock_guard<std::mutex> lg{_m};

    std::stringstream res;
    res << x;

    return res.str();
  }
};


int main() {

  Counter x;

  std::future<void> r1{std::async([&x]() {
    for (int i = 0; i < NUM_COUNT; i++)
      x++;
  })};


  std::future<void> r2{std::async([&x]() {
    for (int i = 0; i < NUM_COUNT; i++)
      x++;
  })};


  r1.get();
  r2.get();


  Counter y{x};

  std::cout << "y: " << y.toString() << "\n";


  return 0;
}
