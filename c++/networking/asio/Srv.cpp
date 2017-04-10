#include <iostream>
#include <asio.hpp>

using asio::ip::tcp;

int main() try {

  asio::io_service io_service;

  tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 9000));

  tcp::socket client_socket(io_service);
  acceptor.accept(client_socket);

  std::string message = "Hi";

  asio::error_code ignored_error;
  asio::write(client_socket, asio::buffer(message), ignored_error);

  return 0;
}
catch (std::exception& e)
{
  std::cerr << e.what() << std::endl;
}
