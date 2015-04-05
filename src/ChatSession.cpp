#include "ChatSession.hpp"
#include <boost/bind.hpp>

//-----------------------------------------------------------------------------------
// Constructor
ChatSession::ChatSession(boost::asio::ip::tcp::socket socket) : m_socket(std::move(socket)) {
  BOOST_LOG_TRIVIAL(debug) << *this << "Created";
}

// Destructor
ChatSession::~ChatSession() {
  BOOST_LOG_TRIVIAL(debug) << *this << "Destroyed";
}

//-----------------------------------------------------------------------------------
// Interface
void
ChatSession::start() {
  prv_readMessages();
}

//-----------------------------------------------------------------------------------
// Private Interface
void
ChatSession::prv_readMessages() {
  boost::asio::async_read_until(m_socket, m_buf, "\n",
                                boost::bind(&ChatSession::prv_handleReadMessages,
                                            shared_from_this(),
                                            boost::asio::placeholders::error));
}


void
ChatSession::prv_handleReadMessages(const boost::system::error_code& error) {
   
  if (error) {
    BOOST_LOG_TRIVIAL(error) << *this << error.message();
    return;
  }

    std::istream is(&m_buf);
    std::string message;
    std::getline(is, message);

    BOOST_LOG_TRIVIAL(debug) << *this << message;

    // Read some more
    prv_readMessages();
  
}

