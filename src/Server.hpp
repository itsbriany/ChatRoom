#pragma once

#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

class Server {

	public:
		//::---------------------------------------------------
		//::	Constructor
		//::---------------------------------------------------

		Server();
		

		//::---------------------------------------------------
		//::	Interface
		//::---------------------------------------------------

		// Start the io_service
		void run();
		

	private:
		//::---------------------------------------------------
		//::	Private Interface
		//::---------------------------------------------------


		//::---------------------------------------------------
		//::	Member Variables
		//::---------------------------------------------------

		// The io_service
		boost::asio::io_service m_ioService;

};
