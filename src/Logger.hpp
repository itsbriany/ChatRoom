#pragma once

#define BOOST_ALL_DYN_LINK 1 //Boost is a .so or .dll

#include <string>
#include <map>
#include <boost/log/trivial.hpp>

class Logger {

		public:

			enum LogLevel {
				eTrace,
				eDebug,
				eInfo,
				eWarning,
				eError,
				eFatal
			};


			//::---------------------------------------------------
			//::	Constructor
			//::---------------------------------------------------

			Logger();


			//::---------------------------------------------------
			//::	Interface
			//::---------------------------------------------------
			
			static void setLogLevel(const LogLevel& lvl);
		

    private:

			//::---------------------------------------------------
			//::	Private Interface
			//::---------------------------------------------------
      

			//::---------------------------------------------------
			//::	Member Variables
			//::---------------------------------------------------

			std::string m_logLevel;


    public:

			static std::map<LogLevel, std::string> st_mapStrToLevel; 
			static std::map<std::string, LogLevel> st_mapLevelToStr; 
};
