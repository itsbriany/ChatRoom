#include "Logger.hpp"
#include "Server.hpp" 

int main()
{
	// Nothing less than eDebug will be logged
	Logger::setLogLevel(Logger::eDebug);
  BOOST_LOG_TRIVIAL(info) << "AppMain Started!";	
	return 0;
}
