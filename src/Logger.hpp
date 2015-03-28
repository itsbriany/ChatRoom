#pragma once

#define BOOST_ALL_DYN_LINK 1 //Boost is a .so or .dll

#include <string>
#include <unordered_map>
#include <boost/log/trivial.hpp>

class Logger {

		public:

			static enum {
				eTrace,
				eDebug,
				eInfo,
				eWarning,
				eError,
				eFatal
			} LogLevel;


			//::---------------------------------------------------
			//::	Constructor
			//::---------------------------------------------------

			Logger();


			//::---------------------------------------------------
			//::	Interface
			//::---------------------------------------------------
			
			static void setLogLevel(const std::string& lvl);
		

			//::---------------------------------------------------
			//::	Private Interface
			//::---------------------------------------------------

			//::---------------------------------------------------
			//::	Member Variables
			//::---------------------------------------------------

			std::string m_logLevel;

			static std::unordered_map<LogLevel, std::string> st_mapStrToLevel; 
			static std::unordered_map<std::string, Logger> st_mapLevelToStr; 
};
