#include "TcpConnection.hpp"
#include "Logger.hpp"
#include <boost/bind.hpp>

//-----------------------------------------------------------------------------
// Constructor
TcpConnection::TcpConnection(boost::asio::io_service& io_service) :
  m_connectionId(0U),
  m_ioService(io_service),
  m_socket(io_service), 
  m_message("Hello TcpConnection\n") {}


//-----------------------------------------------------------------------------
// Interface

void
TcpConnection::start() {

  // Asynchronously write to the socket
  boost::asio::async_write(m_socket, boost::asio::buffer(m_message, m_message.size()),
                           boost::bind(&TcpConnection::pro_handleWrite, shared_from_this(),
                                       boost::asio::placeholders::error,
                                       boost::asio::placeholders::bytes_transferred)); 

  // Asynchronously read from the socket
  

}


//-----------------------------------------------------------------------------
// Protected Interface

void
TcpConnection::pro_handleWrite(const boost::system::error_code &error,
                               std::size_t bufferSize)
{
  // Try async_read here 

  BOOST_LOG_TRIVIAL(debug) << *this << "Wrote: " << m_message << " to client!";
}
