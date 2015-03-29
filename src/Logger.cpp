#include "Logger.hpp"

// Static initialization
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

Logger::LogLevel Logger::st_logLevel = Logger::eDebug;  

//--------------------------------------------------------------------------------------------------
// Interface

// Set the filters
void
Logger::setLogLevel(const Logger::LogLevel& lvl) {
	
	// See more specific logging information
	boost::log::add_common_attributes();
	
	// Set the filter level here
  st_logLevel = lvl;

	switch (lvl) {
		case eTrace:
			boost::log::core::get()->set_filter
			(
				boost::log::trivial::severity >= boost::log::trivial::trace	
			);
			break;

		case eInfo:
			boost::log::core::get()->set_filter
			(
				boost::log::trivial::severity >= boost::log::trivial::info	
			);
			break;

		case eWarning:
			boost::log::core::get()->set_filter
			(
				boost::log::trivial::severity >= boost::log::trivial::warning	
			);
			break;

		case eError:
			boost::log::core::get()->set_filter
			(
				boost::log::trivial::severity >= boost::log::trivial::error	
			);
			break;

		case eFatal:
			boost::log::core::get()->set_filter
			(
				boost::log::trivial::severity >= boost::log::trivial::fatal	
			);
			break;

		default:
			boost::log::core::get()->set_filter
			(
				boost::log::trivial::severity >= boost::log::trivial::debug	
			);
      st_logLevel = Logger::eDebug;
			break;
	}

}
