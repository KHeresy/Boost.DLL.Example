#include "../API/MyAPI.h"

// STD Headers
#include <iostream>

// Boost Headers
#include <boost/dll.hpp>

int main(int argc, char** argv)
{
	#ifdef _WIN32
	boost::filesystem::path pathDLL = "DLLa.dll";
	#else
	boost::filesystem::path pathDLL = "libDLLa.so";
	#endif

	// generate data
	std::vector<double> vData = {1,2,3,4,5,6,7,8,9,0};

	std::function<API_Create> funcExt = boost::dll::import_alias<API_Create>(pathDLL, "create_plugin");
	boost::shared_ptr<CMyAPI> pModule = funcExt();
	std::cout << "Module [" << pModule->getName() << "], result: " << pModule->compute(vData) << std::endl;

	return 0;
}
