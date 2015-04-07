#include "ChatSession.hpp"
#include "Participant.hpp"

#include <vector>

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
    void join(const Participant& newParticipant);

    // Output ChatRoom as a string
    std::string getAsString();

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

    void prv_handleDeliver(const boost::system::error_code& error);

		//::---------------------------------------------------
		//::	Members
		//::---------------------------------------------------

    // The chat sessions in this chat room
    std::vector<ChatSession> m_sessionVector;

    // The greeting message that will be broadcasted
    std::string m_greetingMessage;


};
