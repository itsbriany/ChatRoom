#include "Logger.hpp"

#include <boost/assign/list_of.hpp>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>


// Set up log mapping
std::map<Logger::LogLevel, std::string> Logger::st_mapStrToLevel = boost::assign::map_list_of
	(Logger::eTrace, "trace")
	(Logger::eDebug, "debug")
	(Logger::eInfo, "info")
	(Logger::eWarning, "warning")
	(Logger::eError, "error")
	(Logger::eFatal, "fatal");

std::map<std::string, Logger::LogLevel> Logger::st_mapLevelToStr = boost::assign::map_list_of
	("trace", Logger::eTrace)
	("debug", Logger::eDebug)
	("info", Logger::eInfo)
	("warning", Logger::eWarning)
	("error", Logger::eError)
	("fatal", Logger::eFatal);

//--------------------------------------------------------------------------------------------------
// Constructor
Logger::Logger() : m_logLevel("debug") { }


//--------------------------------------------------------------------------------------------------
// Interface

// Set the filters
void
Logger::setLogLevel(const Logger::LogLevel& lvl) {
	
	// See more specific logging information
	boost::log::add_common_attributes();
	
	// Set the filter level here
	
	switch (lvl) {
		case eTrace:
			boost::log::core::get()->set_filter
			(
				boost::log::trivial::severity >= boost::log::trivial::trace	
			);
			break;

		default:
			m_logLevel = "debug";
      lvl = ::eDebug;
			break;
	}
		m_logLevel = ::st_mapLevelToStr[lvl];
		

}

int main()
{
	Logger logger;
	logger.setLogLevel("warning");

	BOOST_LOG_TRIVIAL(error) << "Blah!";
	BOOST_LOG_TRIVIAL(trace) << "Blah!";
	return 0;
}
