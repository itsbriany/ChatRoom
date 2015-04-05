#include "TcpConnection.hpp"
#include "Logger.hpp"
#include <boost/bind.hpp>
#include <boost/locale/date_time.hpp>

//-----------------------------------------------------------------------------
// Constructor
TcpConnection::TcpConnection(boost::asio::io_service& io_service) :
  m_connectionId(0U),
  m_ioService(io_service),
  m_socket(io_service), 
  m_message("Hello TcpConnection\n") {}


// Destructor
TcpConnection::~TcpConnection() {
  BOOST_LOG_TRIVIAL(debug) << *this << "Destoryed"; 
}

//-----------------------------------------------------------------------------
// Interface

void
TcpConnection::startConnection() {


  // Make some overrides here
  
  if (isServer) {
    
    boost::asio::ip::tcp::resolver resolver(m_ioService);
    boost::asio::ip::tcp::resolver::query query("host", "service");
    // A new socket may need to go here

    resolver.async_resolve(query, boost::bind(&TcpConnection::prv_handleResolve,
                                              shared_from_this(),
                                              boost::asio::placeholders::error,
                                              m_resolverIterator));
    return;
  }


  // Asynchronously write to the socket
  /*
  boost::asio::async_write(m_socket, boost::asio::buffer(m_message, m_message.size()),
                           boost::bind(&TcpConnection::pro_handleWrite, shared_from_this(),
                                       boost::asio::placeholders::error,
                                       boost::asio::placeholders::bytes_transferred)); 

  // Asynchronously read from the socket
  //boost::asio::basic_streambuf<std::allocator<char>> streamBuf;
  boost::asio::async_read_until(m_socket, m_response, "\n",
                                boost::bind(&TcpConnection::pro_handleRead,
                                            shared_from_this(),
                                            boost::asio::placeholders::error));
                                            */

}


//-----------------------------------------------------------------------------
// Private Interface

void
TcpConnection::prv_handleResolve(const boost::system::error_code& error,
                                 boost::asio::ip::tcp::resolver::iterator it) {
  
  if (error) {
    BOOST_LOG_TRIVIAL(error) << *this << "Resolving query: " << error.message();
    return;
  }


  boost::asio::async_connect(m_socket, it, boost::bind(&TcpConnection::pro_connectionEstablished,
                                                       shared_from_this(),
                                                       boost::asio::placeholders::error));

}


//-----------------------------------------------------------------------------
// Protected Interface

/*
void
TcpConnection::pro_handleWrite(const boost::system::error_code &error,
                               std::size_t bufferSize)
{
  // Try async_read here 

  if (error) {
    BOOST_LOG_TRIVIAL(error) << *this << error.message();
    return;
  }

  boost::locale::date_time now;
  BOOST_LOG_TRIVIAL(debug) << *this << '[' << now << "] ";
}


void
TcpConnection::pro_handleRead(const boost::system::error_code &error) {

  if (error) {
    BOOST_LOG_TRIVIAL(error) << *this << error.message();
    return;
  }


    BOOST_LOG_TRIVIAL(info) << *this << &m_response;
} 
*/
