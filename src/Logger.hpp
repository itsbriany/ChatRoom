#pragma once

#define BOOST_ALL_DYN_LINK 1 //Boost is a .so or .dll

#include <string>
#include <map>

#include <boost/assign/list_of.hpp>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>


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
			//::	Interface
			//::---------------------------------------------------
			
      // Set the global log level
			static void setLogLevel(const LogLevel& lvl);

			// Get the log level
			static LogLevel getLogLevel() {
				return st_logLevel;		
			}
		

    private:

			//::---------------------------------------------------
			//::	Member Variables
			//::---------------------------------------------------

			static LogLevel st_logLevel;


    public:

			static std::map<LogLevel, std::string> st_mapStrToLevel; 
			static std::map<std::string, LogLevel> st_mapLevelToStr; 
};
