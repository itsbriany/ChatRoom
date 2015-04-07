#include "Participant.hpp"


//---------------------------------------------------------------------------
// Static Initialization
unsigned short Participant::st_totalId = 0;

//---------------------------------------------------------------------------
// Constructor
Participant::Participant(std::string name) :
  m_name(name),
  m_id(Participant::st_totalId) 
{
  st_totalId++;  
}

// Destructor
Participant::~Participant() {
  BOOST_LOG_TRIVIAL(info) << *this << "Left the chat room";
  st_totalId--;
}

