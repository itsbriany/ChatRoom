#pragma once

#include <boost/asio.hpp>
#include <vector>
#include <stdint.h>

class ChatRoom {

public:
  //::---------------------------------------------------
  //::	Type Definitions
  //::---------------------------------------------------

  typedef std::vector<std::string> ParticipantVector;


public:
  //::---------------------------------------------------
  //::	Constructor/Destructor
  //::---------------------------------------------------

  ChatRoom(std::string name);

  ~ChatRoom();

  //::---------------------------------------------------
  //::	Interface
  //::---------------------------------------------------

  // Output ChatRoom as a string
  std::string getAsString();

  // Add a participant to the room
  void addParticipant(const std::string &name);

  // Get the total number of participants in this room
  uint32_t getParticipantCount() const {
    return m_participantCount;
  }

  // Increment the participant count
  void incrementParticipantCount() {
    ChatRoom::m_participantCount++;
  }

  // Decrement the participant count
  void decrementParticipantCount() {
    ChatRoom::m_participantCount--;
  }

  // Get the name of this room
  const std::string &getName() const {
    return m_name;
  }

  // Get the vector of participants for this room
  const ParticipantVector &getParticipantVector() const {
    return m_participantVector;
  }


  //::---------------------------------------------------
  //::	Logging
  //::---------------------------------------------------

  friend std::ostream &operator<<(std::ostream &lhs, ChatRoom &chatRoom) {
    return lhs << chatRoom.getAsString();
  }


private:
  //::---------------------------------------------------
  //::	Private Interface
  //::---------------------------------------------------


private:
  //::---------------------------------------------------
  //::	Members
  //::---------------------------------------------------

  // The greeting message that will be broadcasted
  std::string m_greetingMessage;

  // Keep track of how many participants are in the room
  uint32_t m_participantCount;

  // The name of this chat room
  std::string m_name;

  // The vector of participants that belong to this room
  ParticipantVector m_participantVector;

};
