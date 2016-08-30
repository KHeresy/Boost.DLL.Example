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

	// Load library information
	boost::dll::library_info infDLL(pathDLL);

	// get all section name
	std::vector<std::string> vSections = infDLL.sections();
	for (const std::string& sSection : vSections)
	{
		std::cout << "Section: " << sSection << "\n";

		if (sSection[0] == '.')
			continue;

		// get all symbol name
		std::vector<std::string> vSymbol = infDLL.symbols(sSection);
		for (const std::string& sSymbol : vSymbol)
		{
			std::cout << " - " << sSymbol << "\n";
		}
	}

	return 0;
}
