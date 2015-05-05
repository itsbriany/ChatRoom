#pragma once

#include <iostream>
#include <string>
#include <boost/asio.hpp>

class AppMain {

public:
	//::---------------------------------------------------
	//::	Constructor/Destructor
	//::---------------------------------------------------

	AppMain();

	//::---------------------------------------------------
	//::	Interface
	//::---------------------------------------------------


	// Start the io_service
	void run();

	// Get the io_service
	std::shared_ptr<boost::asio::io_service> getIoService() {
		return std::shared_ptr<boost::asio::io_service>(m_ioService);
	}

	// Translate this into a string
	std::string getAsString() {
		return std::string("[AppMain]: ");
	}

	//::---------------------------------------------------
	//::	Logging
	//::---------------------------------------------------

	friend std::ostream &operator<<(std::ostream &lhs, AppMain &app) {
		return lhs << app.getAsString();
	}

private:
	//::---------------------------------------------------
	//::	Private Interface
	//::---------------------------------------------------

// Handle application shutdown
	void prv_handleShutDown(const boost::system::error_code &error, int signalNumber);


	//::---------------------------------------------------
	//::	Member Variables
	//::---------------------------------------------------

	// The io_service
	std::shared_ptr<boost::asio::io_service> m_ioService;

};
