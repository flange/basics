#include <iostream>
#include <utility>
#include <string>
#include <experimental/optional>


class SocketError {
public:
  std::string msg;

  SocketError(const std::string& msg) : msg{msg} {}

  std::string what() {
    return msg;
  }

  friend std::ostream& operator<<(std::ostream& os, const SocketError& e) {
    return os << e.msg;
  }
};


template <typename Value, typename Error>
class Result {
public:

  using OptValue = std::experimental::optional<Value>;
  using OptError = std::experimental::optional<Error>;

  std::pair<OptValue, OptError> pair;

  void setValue(const Value& v) {
    pair.first = v;
  }

  void setError(const Error& e) {
    pair.second = e;
  }

  OptValue& value() {
    return pair.first;
  }

  OptError error() {
    return pair.second;
  }

  operator bool() const {
    return pair.first ? true : false;
  }

  Value operator*() {
    return *(pair.first);
  }

  Error operator~() {
    return *(pair.second);
  }
};

using OptFD = std::experimental::optional<int>;
using OptSE = std::experimental::optional<SocketError>;

Result<int, SocketError> openSocket(bool success) {

  Result<int, SocketError> res;

  if (success) {
    int fd = 3;
    res.setValue(fd);
  } else {
    SocketError err{"open failed"};
    res.setError(err);
  }

  return res;
}


using FileDescriptor = int;

int main() {

  Result<FileDescriptor, SocketError> res = openSocket(false);

  if (res) {
    std::cout << "[success] fd: " << *res << "\n";
  }

  if (!res) {
    std::cout << "[error] msg: " << ~res << "\n";
  }



  return 0;
}
