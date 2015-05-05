#pragma once

#include "Logger.hpp"
#include "ChatRoom.hpp"

#include <string>
#include <iostream>
#include <sstream>


class Participant : boost::noncopyable {

public:
  //::---------------------------------------------------
  //::	Constructor/Destructor
  //::---------------------------------------------------

  Participant(std::string name, ChatRoom &chatRoom);

  virtual ~Participant();


public:
  //::---------------------------------------------------
  //:: Pure Virtual Interface
  //::---------------------------------------------------

  // Deliver a message to those in the given chat room
  virtual void deliver(const std::string &msg) = 0;

  // Listen for a message from other participants
  virtual void listen(std::string &msg) = 0;

  // Join a chat room
  virtual void join(ChatRoom &chatRoom) = 0;


public:
  //::---------------------------------------------------
  //:: Interface
  //::---------------------------------------------------

  std::string getName() const {
    return m_name;
  }

  ChatRoom &getChatRoom() const {
    return m_chatRoom;
  }

  void setChatRoom(ChatRoom &m_chatRoom) {
    Participant::m_chatRoom = m_chatRoom;
  }

  void setName(const std::string &m_name) {
    Participant::m_name = m_name;
  }

  // Output as string
  std::string getAsString() {
    std::ostringstream oss;
    oss << '[' << m_name << "]: ";
    return oss.str();
  }


//::---------------------------------------------------
  //::  Protected Interface
  //::---------------------------------------------------

  // Check if this member is still associated with the chat room


private:
  //::---------------------------------------------------
  //:: Logging
  //::---------------------------------------------------

  friend std::ostream &operator<<(std::ostream &lhs, Participant &participant) {
    return lhs << participant.getAsString();
  }


private:
  //::---------------------------------------------------
  //:: Member Variables
  //::---------------------------------------------------

  // The participant's name
  std::string m_name;

  // The chat room that this praticipant currently belongs to
  ChatRoom &m_chatRoom;
};
