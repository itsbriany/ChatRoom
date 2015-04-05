#include "TcpConnection.hpp"
#include "Logger.hpp"
#include <boost/bind.hpp>
#include <boost/locale/date_time.hpp>

//-----------------------------------------------------------------------------
// Constructor
TcpConnection::TcpConnection(boost::asio::io_service& io_service) :
  m_socket(io_service) 
{
}

//-----------------------------------------------------------------------------
// Interface
