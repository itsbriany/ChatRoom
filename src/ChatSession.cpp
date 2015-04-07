#include "ChatSession.hpp"
#include <boost/bind.hpp>

//-----------------------------------------------------------------------------------
// Constructor
ChatSession::ChatSession(std::string clientName, boost::asio::ip::tcp::socket socket) : 
  BaseClass(clientName),
  m_socket(std::move(socket))
{
  BOOST_LOG_TRIVIAL(debug) << *this << "Created";
}

// Destructor
ChatSession::~ChatSession() {
  BOOST_LOG_TRIVIAL(debug) << *this << "Destroyed";
}

//-----------------------------------------------------------------------------------
// Participant override Interface

// Write a message to the socket
void
ChatSession::deliver(std::string &message) {
  m_socket.async_write_some(boost::asio::buffer(message, message.size()),
      [this](const boost::system::error_code& error, std::size_t bytesTransferred){
        
        if (error) {
          // Might want to specify the error here to that an expected error
          // Can be handled
          BOOST_LOG_TRIVIAL(error) << *this << error.message();
          //Leave the room that this session belongs to
        } 
        
        // TODO Add this message to the chat room so that it can be broadcasted

      });
}

// Receives incoming messages
void
ChatSession::listen(std::string &message) {

}


//-----------------------------------------------------------------------------------
// Interface
void
ChatSession::start() {
  // Listen for messages in the room
  std::string greeting(getName() + " has joined in");
  listen(greeting);
  deliver(greeting);
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

