#include "Logger.hpp"

#include <iostream>
#include <string>
#include <boost/asio.hpp>


class TcpConnection : public std::enable_shared_from_this<TcpConnection> {

	public:
    typedef std::shared_ptr<TcpConnection> pointer;
		//::---------------------------------------------------
    //::	Interface
		//::---------------------------------------------------

		TcpConnection(boost::asio::io_service& io_service);

    static pointer create(boost::asio::io_service& io_service) {
      return pointer(new TcpConnection(io_service)); 
    }
  
    // Start the TcpConnection
    void startConnection();

    // Get a handle on this TcpConnection's socket
    boost::asio::ip::tcp::socket& getSocket() {
      return m_socket; 
    }


  private:
    //::---------------------------------------------------
		//::	Constructor/Destructor
		//::---------------------------------------------------
  

    //::---------------------------------------------------
		//::	Member Variables
		//::---------------------------------------------------
  
    boost::asio::ip::tcp::socket m_socket;

};
