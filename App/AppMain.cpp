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

	boost::shared_ptr<std::string> pVar = boost::dll::import<std::string>( pathDLL, "sModuleName" );
	std::cout << "Variable: " << *pVar << std::endl;

	std::function<std::string()> funcExt = boost::dll::import<std::string()>(pathDLL, "getName");
	std::cout << "Function: " << funcExt() << std::endl;

	return 0;
}
