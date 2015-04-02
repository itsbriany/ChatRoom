#include <iostream>
#include <string>
#include <boost/asio.hpp>

#include "TcpConnection.hpp"

class Server {

	public:
		//::---------------------------------------------------
		//::	Constructor
		//::---------------------------------------------------
  
		Server(boost::asio::io_service& io_service, unsigned short port);

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
    

		//::---------------------------------------------------
		//::	Logger
		//::---------------------------------------------------

		friend std::ostream& operator<<(std::ostream& os, Server& server) {
			return os << server.getAsString();	
		}

  protected:
		//::---------------------------------------------------
		//::  Protected Interface	
		//::---------------------------------------------------
    
    // Handle an asynchronous connection initiated from the server side
    virtual void pro_handleConnect(const boost::system::error_code& error);

    // Handle on reading data asynchronously
    virtual void pro_handleRead(std::ostringstream& buffer,
                                const boost::system::error_code& error);


  private:
		//::---------------------------------------------------
		//::  Private Interface	
		//::---------------------------------------------------

    // Event handle when an incoming connection is accepted
    void prv_handleAccept(TcpConnection::pointer pConnection,
                          const boost::system::error_code& /* error */);

		//::---------------------------------------------------
		//::	Member Variables
		//::---------------------------------------------------
  
    // The port number to listen on
    unsigned short m_port;

    // Accept incoming TCP connections
    boost::asio::ip::tcp::acceptor m_acceptor;

};
