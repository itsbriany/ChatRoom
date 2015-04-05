#include "Logger.hpp"

#include <iostream>
#include <string>
#include <boost/asio.hpp>


class TcpConnection : public std::enable_shared_from_this<TcpConnection> {

	public:
    typedef std::shared_ptr<TcpConnection> pointer;

    //::---------------------------------------------------
		//::	Constructor/Destructor
		//::---------------------------------------------------
  
		TcpConnection(boost::asio::io_service& io_service);

    virtual ~TcpConnection(); 

		//::---------------------------------------------------
    //::	Interface
		//::---------------------------------------------------

    // Start the TcpConnection
    void startConnection();

    // Get a handle on this TcpConnection's socket
    boost::asio::ip::tcp::socket& getSocket() {
      return m_socket; 
    }

    // Create a pointer to the TcpConnection
    /*
    static pointer create(boost::asio::io_service& io_service) {
      return pointer(new TcpConnection(io_service)); 
    }
    */

    // Get the connection ID
    unsigned short getConnectionId() {
      return m_connectionId; 
    }

    // Get this object as a string
    std::string getAsString() {
      std::ostringstream oss;
      oss << "[TcpConnection|" << getConnectionId() << "]: ";
			return oss.str();		
		}

		//::---------------------------------------------------
		//::	Logger
		//::---------------------------------------------------

		friend std::ostream& operator<<(std::ostream& os, TcpConnection& connection) {
			return os << connection.getAsString();	
		}

  protected:
    //::---------------------------------------------------
		//::	Pure Virtual Interface
		//::---------------------------------------------------
  
  /*
    // Handle writing data to the socket
    virtual void pro_handleWrite(const boost::system::error_code& error,
                                 std::size_t bufferSize);

    
    // Handle reading data from the socket
    virtual void pro_handleRead(const boost::system::error_code& error);
    */


    // Handle when the connection is established
    virtual void pro_connectionEstablished(const boost::system::error_code& error){}


  private:
    //::---------------------------------------------------
		//::	Private Interface
		//::---------------------------------------------------

    void prv_handleResolve(const boost::system::error_code& error,
                           boost::asio::ip::tcp::resolver::iterator it);
    
    //::---------------------------------------------------
		//::	Member Variables
		//::---------------------------------------------------
  
    // Is this a server?
    bool isServer;

    unsigned short m_connectionId;

    boost::asio::io_service &m_ioService;

    boost::asio::ip::tcp::socket m_socket;

    // The iterator to keep track of the established connections?
    boost::asio::ip::tcp::resolver::iterator m_resolverIterator;

    std::string m_message;

    // The given response from the client
    boost::asio::streambuf m_response;

};
