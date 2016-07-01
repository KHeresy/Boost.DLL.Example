// STD Headers
#include <string>

// Boost Headers
#include <boost/dll/alias.hpp>

std::string sModuleName = "Module A";

std::string getName()
{
	return sModuleName;
}

BOOST_DLL_ALIAS(sModuleName, NAME)
BOOST_DLL_ALIAS_SECTIONED(getName, GET_NAME, XD)
