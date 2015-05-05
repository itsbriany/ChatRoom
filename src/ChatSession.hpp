#pragma once

#include "Server.hpp"
#include "Participant.hpp"

#include <boost/asio.hpp>

class ChatSession : public Participant,
                    public std::enable_shared_from_this<ChatSession> {

private:
  //::---------------------------------------------------
  //::	Type Definitions
  //::---------------------------------------------------

  typedef Participant BaseClass;

public:
  typedef std::shared_ptr<ChatSession> ChatSessionPtr;

  //::---------------------------------------------------
  //::	Constructor/Destructor
  //::---------------------------------------------------

  ChatSession(std::string client_name, boost::asio::ip::tcp::socket socket, ChatRoom &chatRoom);

  ~ChatSession();

  //::---------------------------------------------------
  //:: Participant Override Interface
  //::---------------------------------------------------

  // Send a message
  void deliver(const std::string &message);

  // Get a message
  void listen(std::string &message);

  // Join a chat room
  virtual void join(ChatRoom &chatRoom);


public:
  //::---------------------------------------------------
  //:: Interface
  //::---------------------------------------------------


// Start the session
  void start();

  boost::asio::ip::tcp::socket &getSocket() {
    return m_socket;
  }

  // Output as string
  std::string getAsString() {
    std::ostringstream oss;
    oss << "[ChatSession]: ";
    return oss.str();
  }

private:
  //::---------------------------------------------------
  //:: Logging
  //::---------------------------------------------------

  friend std::ostream &operator<<(std::ostream &lhs, ChatSession &chatSession) {
    return lhs << chatSession.getAsString();
  }

private:
  //::---------------------------------------------------
  //:: Private Interface
  //::---------------------------------------------------

  // Reads the messages
  void prv_readMessages();

  // Handle the message reading
  void prv_handleReadMessages(const boost::system::error_code &error);


  //::---------------------------------------------------
  //:: Member Variables
  //::---------------------------------------------------

  // The socket that this sessions uses to send/receive
  boost::asio::ip::tcp::socket m_socket;

  // TODO Still questionable; Should probably abstract this into a message obj
  boost::asio::streambuf m_buf;

};
