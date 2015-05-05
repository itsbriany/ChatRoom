#include "Participant.hpp"


//---------------------------------------------------------------------------
// Constructor
Participant::Participant(std::string name, ChatRoom &chatRoom) :
  m_name(name),
  m_chatRoom(chatRoom)
{
  // Add this name to the chatroom
  BOOST_LOG_TRIVIAL(debug) << *this << "Joined chat room [" << m_chatRoom.getName() << ']' << std::endl;
  m_chatRoom.addParticipant(name);
  m_chatRoom.incrementParticipantCount();
}


//---------------------------------------------------------------------------
// Destructor
Participant::~Participant() {
  BOOST_LOG_TRIVIAL(info) << *this << "Left chat room [" << m_chatRoom.getName() << ']' << std::endl;
  m_chatRoom.decrementParticipantCount();
}


//---------------------------------------------------------------------------
// Check if the participant is still associated with the chat room
