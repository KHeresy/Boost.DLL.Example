// STD Headers
#include <string>

// Boost Headers
#include <boost/config.hpp>
#define API extern "C" BOOST_SYMBOL_EXPORT

API std::string sModuleName = "Module A";

API std::string getName()
{
	return sModuleName;
}
