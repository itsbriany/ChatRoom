#pragma once

#include "ChatRoom.hpp"

#include <vector>
#include <iostream>
#include <string>
#include <boost/asio.hpp>

class ChatRoom;

// Every time a new Server is created, can only be a shared pointer
class Server {

public:
    //::---------------------------------------------------
    //::	Constructor/Destructor
    //::---------------------------------------------------

    Server(boost::asio::io_service &io_service, unsigned short port);

    virtual ~Server();


public:
    //::---------------------------------------------------
    //::	Interface
    //::---------------------------------------------------

    // Get this object as a string
    std::string getAsString() {
        return std::string("[Server]: ");
    }

    // Get the port number that the server is listening on
    unsigned short getPort() {
        return m_port;
    }

    //Create a socket an initiate an asynchronous accept operation to wait for a new connection
    void startAccept();


private:
    //::---------------------------------------------------
    //::	Logger
    //::---------------------------------------------------

    friend std::ostream &operator<<(std::ostream &os, Server &server) {
        return os << server.getAsString();
    }


private:
    //::---------------------------------------------------
    //::  Private Interface
    //::---------------------------------------------------

    void prv_handleAccept(const boost::system::error_code& error);


private:
    //::---------------------------------------------------
    //::	Member Variables
    //::---------------------------------------------------
  
    // The server's io_service
    boost::asio::io_service &m_ioService;

    // The port number to listen on
    unsigned short m_port;

    // Accept incoming TCP connections
    boost::asio::ip::tcp::acceptor m_acceptor;

    // A stream buffer for read input
    boost::asio::streambuf m_buf;

    // The socket that will be moved around to different clients
    boost::asio::ip::tcp::socket m_socket;

    // The of chatroom
    ChatRoom m_chatRoom;

};
