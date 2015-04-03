#include "AppMain.hpp"
#include "Logger.hpp"
#include "Server.hpp"

#include <exception>
#include <boost/bind.hpp>

//-----------------------------------------------------------------------------
// Constructor

AppMain::AppMain() : m_ioService(new boost::asio::io_service) { } 

//-----------------------------------------------------------------------------
// Interface
void
AppMain::run() {
  try {
    // The server will listen for incoming TcpConnections on port 6060
    Server server(*m_ioService, 6060U);

    BOOST_LOG_TRIVIAL(info) << *this << "Listening on port " << server.getPort();

    // Register signals for process termination
    boost::asio::signal_set signals(*m_ioService, SIGINT, SIGTERM);

    // Start an asynchronous wait for this to happen
    signals.async_wait(boost::bind(&AppMain::prv_handleShutDown,
                                   this,
                                   boost::asio::placeholders::error,
                                   SIGINT));

    BOOST_LOG_TRIVIAL(debug) << *this << "--------------------";	
    BOOST_LOG_TRIVIAL(debug) << *this << "Entering run loop";
    m_ioService->run();	
  } catch (std::exception& e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl; 
  }
}


//-----------------------------------------------------------------------------
// Private Interface

void
AppMain::prv_handleShutDown(const boost::system::error_code& error,
                            int signalNumber) {

  if (error) {
    BOOST_LOG_TRIVIAL(error) << *this << error; 
  }

  BOOST_LOG_TRIVIAL(info) << *this << "Signal caught: " << signalNumber;
  BOOST_LOG_TRIVIAL(info) << *this << "Stopping Server...";
  m_ioService->stop();

}

//-----------------------------------------------------------------------------
// Main
int main()
{
	// Nothing less than eDebug will be logged
	Logger::setLogLevel(Logger::eDebug);
	AppMain app;
  BOOST_LOG_TRIVIAL(info) << app << "Starting Server...";	
	app.run();
  BOOST_LOG_TRIVIAL(debug) << app << "Run Loop Finished";	
  BOOST_LOG_TRIVIAL(debug) << app << "--------------------";	
  BOOST_LOG_TRIVIAL(info) << app << "Application terminated";	
	return 0;
}
