#include "Logger.hpp"

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>


// Set up log mapping
std::map<Logger::LogLevel, std::string> Logger::st_mapStrToLevel({eTrace, "trace"});


Logger::Logger() : m_logLevel("debug") { }


// Set the filters
void
Logger::setLogLevel(const std::string& lvl) {
	
	// See more specific logging information
	boost::log::add_common_attributes();
	
	// Set the filter level here
	switch (lvl) {
		case "trace":
			boost::log::core::get()->set_filter
			(
				boost::log::trivial::severity >= boost::log::trivial::trace	
			);
			break;

		default:
			m_logLevel = "debug";
			break;
	}
		m_logLevel = lvl;

}

int main()
{
	Logger logger;
	logger.setLogLevel("warning");

	BOOST_LOG_TRIVIAL(error) << "Blah!";
	BOOST_LOG_TRIVIAL(trace) << "Blah!";
	return 0;
}
