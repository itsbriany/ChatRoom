#include "Server.hpp"
#include "Logger.hpp"
#include <boost/bind.hpp>
#include <boost/asio.hpp>

//-----------------------------------------------------------------------------
// Constructor

Server::Server(boost::asio::io_service& io_service, unsigned short port) :
  m_port(port),
  m_acceptor(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
{ 
  startAccept();
}

//-----------------------------------------------------------------------------
// Interface

void
Server::startAccept() {
  // Create a new connection 
  /*
  TcpConnection::pointer newConnection = TcpConnection::create(m_acceptor.get_io_service()); 

  // Perform an asynchronous accept operation to wait for a new connection
  m_acceptor.async_accept(newConnection->getSocket(),
                          boost::bind(&Server::prv_handleAccept, this,
                                      newConnection,
                                      boost::asio::placeholders::error));
                                      */
}

//-----------------------------------------------------------------------------
// Protected Interface
void
Server::pro_handleConnect(const boost::system::error_code &error) {

  if (error) {
    BOOST_LOG_TRIVIAL(error) << *this << error;  
    return;
  }
  
  BOOST_LOG_TRIVIAL(debug) << *this << "The Server has made a connection!";
}

void
Server::pro_handleRead(std::ostringstream& buffer, const boost::system::error_code &error) {

  if (error) {
    BOOST_LOG_TRIVIAL(error) << *this << error;  
    return;
  }
  
  BOOST_LOG_TRIVIAL(debug) << *this << "Read data: " << buffer;
}

//-----------------------------------------------------------------------------
// Private Interface
void
Server::prv_handleAccept(TcpConnection::pointer newConnection,
                         const boost::system::error_code& error)
{
  if (error) {
    BOOST_LOG_TRIVIAL(error) << *this << error;
    return;
  }  

  // Start the new TcpConnection
  newConnection->startConnection();

  // Try an async_connect with the socket
  /*
  boost::asio::ip::tcp::resolver::iterator it;

  boost::asio::async_connect(newConnection->getSocket(), it, 
                             boost::bind(&Server::pro_handleConnect, this,
                                         boost::asio::placeholders::error));
                                         */


  // Listen for more incoming connections
  startAccept();
}
