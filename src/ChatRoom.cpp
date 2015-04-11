#include "ChatRoom.hpp"

#include <boost/bind.hpp>

//-------------------------------------------------------------------------------
// Static Initialization

uint32_t ChatRoom::st_participantCount = 0;

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
ChatRoom::join(Participant& newParticipant) {
  st_participantCount++;
}


// Broadcast a message to each participant in the room
void 
ChatRoom::broadcast(const std::string& msg) {
  for (auto &participant : m_participantVector) {
    participant.deliver(m_greetingMessage); 
  }
}


//-------------------------------------------------------------------------------
// Private Interface

void
ChatRoom::prv_handleDeliver(const Participant& target, const boost::system::error_code &error) {

  if (error) {
    BOOST_LOG_TRIVIAL(error) << *this << error.message();
    return;
  }

  
    BOOST_LOG_TRIVIAL(debug) << *this << "Broadcast message successfully delivered";

}
