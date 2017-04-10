#include <array>
#include <asio.hpp>
#include <iostream>
#include <string>

using asio::ip::tcp;

int main() try {

  asio::io_service io_service;

  tcp::resolver resolver(io_service);
  tcp::resolver::query query(tcp::v4(), "localhost", "9000");
  tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);

  tcp::socket socket(io_service);
  asio::connect(socket, endpoint_iterator);

  std::array<char, 4> buf{};
  asio::error_code error;

  asio::read(socket, asio::buffer(buf), error);
  std::string msg(buf.begin(), buf.end());

  std::cout << msg << std::endl;


  return 0;
}
catch (std::exception& e)
{
  std::cerr << e.what() << std::endl;
}
