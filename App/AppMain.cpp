// STD Headers
#include <iostream>

// Boost Headers
#include <boost/dll/shared_library.hpp>

int main(int argc, char** argv)
{
	#ifdef _WIN32
	boost::filesystem::path pathDLL = "DLLa.dll";
	#else
	boost::filesystem::path pathDLL = "libDLLa.so";
	#endif

	boost::dll::shared_library libDLL(pathDLL);
	if (libDLL.has("NAME"))
	{
		std::string sVar = libDLL.get_alias<std::string>("NAME");
		std::cout << "Variable: " << sVar << std::endl;
	}

	if (libDLL.has("GET_NAME"))
	{
		std::function<std::string()> funcExt = libDLL.get_alias<std::string()>("GET_NAME");
		std::cout << "Function: " << funcExt() << std::endl;
	}
	libDLL.unload();

	return 0;
}
