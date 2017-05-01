#include <future>
#include <iostream>
#include <memory>
#include <string>
#include <thread>

using Promise = std::promise<void>;
using PromisePtr = std::shared_ptr<Promise>;
using Future = std::future<void>;


void thr1(PromisePtr pptr) {

  using namespace std::chrono_literals;

  Future f = pptr->get_future();

  std::cout << "[t1] f.wait()\n";
  f.wait();

  std::cout << "[t1] wait() done\n\n";

  std::cout << "[t1] f.wait()\n";
  f.wait();

  std::cout << "[t1] wait() done\n";


}


int main() {


  PromisePtr pptr = std::make_shared<Promise>();

  std::thread t1{thr1, pptr};


  std::string input;

  std::getline(std::cin, input);
  pptr->set_value();


  std::getline(std::cin, input);
  pptr->set_value();



  t1.join();


/*

  while (true) {
    std::getline(std::cin, input);

    if (input == "go")
      std::cout << ">>> go\n";

    if (input == "stop")
      std::cout << "<<< stop\n";

  }
*/

  return 0;
}
