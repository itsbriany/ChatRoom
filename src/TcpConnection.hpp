#include <iostream>
#include <string>
#include <boost/asio.hpp>

class TcpConnection : public std::enable_shared_from_this<TcpConnection> {

	public:
    typedef std::shared_ptr<TcpConnection> pointer;

		//::---------------------------------------------------
    //::	Interface
		//::---------------------------------------------------

    // Start the TcpConnection
    void start();

    // Get a handle on this TcpConnection's socket
    boost::asio::ip::tcp::socket& getSocket() {
      return m_socket; 
    }

    // Create a pointer to the TcpConnection
    static pointer create(boost::asio::io_service& io_service) {
      return pointer(new TcpConnection(io_service)); 
    }

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
		//::	Protected Interface
		//::---------------------------------------------------
  
    // Handle writing data to the socket
    virtual void pro_handleWrite(const boost::system::error_code& error,
                                 std::size_t bufferSize);


  private:
    //::---------------------------------------------------
		//::	Constructor
		//::---------------------------------------------------
  
		TcpConnection(boost::asio::io_service& io_service);


		//::---------------------------------------------------
		//::	Member Variables
		//::---------------------------------------------------
  
    unsigned short m_connectionId;

    boost::asio::io_service &m_ioService;

    boost::asio::ip::tcp::socket m_socket;

    std::string m_message;

    boost::asio::mutable_buffer m_buffer;

};
