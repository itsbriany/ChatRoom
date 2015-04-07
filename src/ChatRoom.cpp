#include "ChatRoom.hpp"

#include <boost/bind.hpp>

//-------------------------------------------------------------------------------
// Constructor
ChatRoom::ChatRoom() : m_greetingMessage("A new participant has joined the room!") {
  BOOST_LOG_TRIVIAL(debug) << *this << "Created"; 
}

//Destructor
ChatRoom::~ChatRoom() {
  BOOST_LOG_TRIVIAL(debug) << *this << "Destroyed"; 
}


//-------------------------------------------------------------------------------
// Interface

// Get ChatRoom as a string
std::string
ChatRoom::getAsString() {
  std::ostringstream oss;
  oss << "[ChatRoom]: ";
  return oss.str();
}

// Let a new participant join
void
ChatRoom::join(const Participant& newSession) {
  // Broadcast a message to all chat sessions
  /*
  for (auto &session : m_sessionSet) {
    //deliver(session, m_greetingMessage); 
  }
  */
}

//-------------------------------------------------------------------------------
// Private Interface

void
ChatRoom::prv_handleDeliver(const boost::system::error_code &error) {

  if (error) {
    BOOST_LOG_TRIVIAL(error) << *this << error.message();
    return;
  }

  
    BOOST_LOG_TRIVIAL(debug) << *this << "Broadcast message successfully delivered";

}
