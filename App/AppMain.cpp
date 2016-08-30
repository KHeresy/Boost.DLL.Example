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
	std::cout << "List sections\n";
	std::vector<std::string> vSections = infDLL.sections();
	for (const std::string& sSection : vSections)
	{
		if (sSection[0] == '.')
			continue;

		std::cout << " Section: " << sSection << "\n";

		// get all symbol name
		std::vector<std::string> vSymbols = infDLL.symbols(sSection);
		for (const std::string& sSymbol : vSymbols)
		{
			std::cout << "  - " << sSymbol << "\n";
		}
	}

	std::cout << "\nList all symbols\n";
	std::vector<std::string> vSymbols = infDLL.symbols();
	for (const std::string& sSymbol : vSymbols)
	{
		std::cout << " " << sSymbol << "\n";
	}

	return 0;
}
