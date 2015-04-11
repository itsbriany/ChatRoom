#pragma once

#include "Participant.hpp"

#include <boost/asio.hpp>
#include <vector>
#include <stdint.h>

class ChatRoom {
  
  public:
		//::---------------------------------------------------
		//::	Constructor/Destructor
		//::---------------------------------------------------

    ChatRoom();

    ~ChatRoom();

		//::---------------------------------------------------
		//::	Interface
		//::---------------------------------------------------

    // Add a new session to this room
    void join(Participant& newParticipant);

    // Output ChatRoom as a string
    std::string getAsString();

    // Get the total number of participants in this room
    uint32_t getParticipants() const {
      return st_participantCount; 
    }

    // Broadcast a message to each participant in the room
    void broadcast(const std::string& msg);


		//::---------------------------------------------------
		//::	Logging
		//::---------------------------------------------------

    friend std::ostream& operator<<(std::ostream& lhs, ChatRoom& chatRoom) {
      return lhs << chatRoom.getAsString(); 
    }



  private:
		//::---------------------------------------------------
		//::	Private Interface
		//::---------------------------------------------------

    void prv_handleDeliver(const Participant& target, const boost::system::error_code& error);


		//::---------------------------------------------------
		//::	Members
		//::---------------------------------------------------

    // The chat sessions in this chat room
    std::vector<Participant> m_participantVector;

    // The greeting message that will be broadcasted
    std::string m_greetingMessage;

    // Keep track of how many participants are in the room
    static uint32_t st_participantCount;

};
