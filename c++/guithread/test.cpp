#include <atomic>
#include <condition_variable>
#include <experimental/optional>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>

template <typename T>
using Optional = std::experimental::optional<T>;

class Track;
class Semaphore;

using Signal = std::vector<double>;
using Position = Signal::const_iterator;
using Lock = std::mutex;
using LockGuard = std::lock_guard<std::mutex>;
using TrackPtr = std::shared_ptr<Track>;
using SemPtr = std::shared_ptr<Semaphore>;


std::atomic_bool running;


class Semaphore {
public:
  long count;
  std::mutex mutex;
  std::condition_variable cond;

  Semaphore(const long& init) : count{init} {}

  void get() {
    std::unique_lock<decltype(mutex)> lock{mutex};

    while(count == 0)
      cond.wait(lock);

    count--;
  }

  void put() {
    std::lock_guard<std::mutex> lg{mutex};
    count++;
    cond.notify_one();
  }
};

class Track {
public:
  Signal signal;
  Position index;
  Lock lock;

  Track(const Signal& s) : signal{s}, index{s.begin()}
  {}

  Optional<double> next() {
    LockGuard lg{lock};

    if (index == (signal.end()))
      return Optional<double>{};

    double res = *index;
    ++index;

    return res;
  }

  void setPosition(std::size_t offset) {
    LockGuard lg{lock};

    if (offset >= signal.size())
      return;

    index = signal.begin() + offset;
  }

};

void play(TrackPtr track) {

  Optional<double> val = track->next();

  if (val)
    std::cout << "        " << *val << "\n";

  return;
}

void audioThread(TrackPtr track, SemPtr sem) {

  using namespace std::chrono_literals;

  while (running) {
    sem->get();

    play(track);
    sem->put();

    std::this_thread::sleep_for(1s);
  }
}

enum class GuiState {PLAY, PAUSE, STOP};

void guiThread(TrackPtr track, SemPtr sem) {

  int offset;
  std::string input;

  GuiState curr_state = GuiState::STOP;

  while (running) {
    std::getline(std::cin, input);

    if (input == "play") {

      if (curr_state != GuiState::PLAY)
        sem->put();

      curr_state = GuiState::PLAY;
      continue;
    }

    if (input == "pause") {

      if (curr_state == GuiState::PLAY)
        sem->get();

      curr_state = GuiState::PAUSE;
      continue;
    }

    if (input == "stop") {

      if (curr_state == GuiState::PLAY)
        sem->get();

      curr_state = GuiState::STOP;
      track->setPosition(0);
      continue;
    }

    if (input == "quit") {
      running = false;
      continue;
    }

    offset = std::stoi(input);

    track->setPosition(offset);
  }
}

int main() {

  TrackPtr track = std::make_shared<Track>(Signal(1000));
  SemPtr sem = std::make_shared<Semaphore>(0);

  for (int i = 0; i < 1000; ++i)
    track->signal[i] = i;

  track->index = track->signal.begin();


  running = true;

  std::thread audio_thread{audioThread, track, sem};
  std::thread gui_thread{guiThread, track, sem};

  audio_thread.join();
  gui_thread.join();

  return 0;
}
