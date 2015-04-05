#pragma once

#include "Server.hpp"

class ChatSession : public std::enable_shared_from_this<ChatSession> {
  
  public:
		//::---------------------------------------------------
		//::	Constructor/Destructor
		//::---------------------------------------------------

    ChatSession(boost::asio::ip::tcp::socket socket);

    ~ChatSession();
    
		//::---------------------------------------------------
		//:: Interface
		//::---------------------------------------------------

    // Start the session
    void start();


    // Output as string
    std::string getAsString() {
      std::ostringstream oss;
      oss << "[ChatSession]: ";
      return oss.str();
    }

		//::---------------------------------------------------
		//:: Logging
		//::---------------------------------------------------

    friend std::ostream& operator<<(std::ostream& lhs, ChatSession& chatSession) {
      return lhs << chatSession.getAsString(); 
    }

  private:
		//::---------------------------------------------------
		//:: Private Interface
		//::---------------------------------------------------

    // Reads the messages 
    void prv_readMessages();

    // Handle the message reading
    void prv_handleReadMessages(const boost::system::error_code& error);


		//::---------------------------------------------------
		//:: Member Variables	
		//::---------------------------------------------------

    boost::asio::ip::tcp::socket m_socket;

    boost::asio::streambuf m_buf;

};
