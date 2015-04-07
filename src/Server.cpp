#include "Server.hpp"
#include "Logger.hpp"
#include "ChatSession.hpp"
#include <boost/bind.hpp>
#include <boost/asio.hpp>

//-----------------------------------------------------------------------------
// Constructor

Server::Server(boost::asio::io_service& io_service, unsigned short port) :
  m_ioService(io_service),
  m_port(port),
  m_acceptor(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)),
  m_socket(io_service)
{ 
  BOOST_LOG_TRIVIAL(debug) << *this << "Constructed";
}

// Destructor
Server::~Server() {
  BOOST_LOG_TRIVIAL(debug) << *this << "Destroyed";
}

//-----------------------------------------------------------------------------
// Interface

void
Server::startAccept() {

  m_acceptor.async_accept(m_socket, boost::bind(&Server::prv_handleAccept,
                                      this,
                                      boost::asio::placeholders::error));
}

//-----------------------------------------------------------------------------
// Private Interface

void
Server::prv_handleAccept(const boost::system::error_code &error) {
  
  if (error) {
    BOOST_LOG_TRIVIAL(error) << *this << "Handle Accept: " << error.message();  
    return;
  }

  BOOST_LOG_TRIVIAL(debug) << *this << "Connection Accepted";  

  /*
    Create a new chat session
    The session should take a socket
  */
  // Use move because we get a reference to a delete function if not
  //std::shared_ptr<ChatSession> session(new ChatSession(std::move(m_socket)));
  //session->start();

  startAccept();

}

