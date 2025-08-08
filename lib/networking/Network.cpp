#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::tcp;

void connect() {
  // 1. Create an io_context
  boost::asio::io_context io_context;

  // 2. Create a resolver
  tcp::resolver resolver(io_context);

  // 3. Resolve the hostname and service
  tcp::resolver::results_type endpoints =
      resolver.resolve("www.google.com", "http");

  // 4. Create a socket
  tcp::socket socket(io_context);

  // 5. Connect the socket to one of the resolved endpoints
  boost::asio::connect(socket, endpoints);

  std::cout << "Successfully connected to www.google.com!\n";
}