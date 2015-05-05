#include "Participant.hpp"

//-------------------------------------------------------------------------------
// Constructor
ChatRoom::ChatRoom(std::string name) :
    m_greetingMessage("A new participant has joined the room!"),
    m_participantCount(0u),
    m_name(name) {
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


//-------------------------------------------------------------------------------
// Add a participant to the room
void ChatRoom::addParticipant(const std::string &name) {
  m_participantVector.push_back(name);
}
