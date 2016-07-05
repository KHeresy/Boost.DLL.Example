#include "../API/MyAPI.h"

// STD Headers
#include <iostream>

// Boost Headers
#include <boost/dll.hpp>

int main(int argc, char** argv)
{
	// generate data
	std::vector<double> vData = { 1,2,3,4,5,6,7,8,9,0 };

	//
	boost::filesystem::path pathDir = "./";
	for (auto itFile = boost::filesystem::directory_iterator(pathDir); itFile != boost::filesystem::directory_iterator(); ++itFile)
	{
		if (boost::filesystem::is_regular_file(*itFile))
		{
			boost::filesystem::path pathFile = *itFile;
			if (pathFile.extension() == ".dll" || pathFile.extension() == ".so")
			{
				std::cout << "\nTry to load " << pathFile << std::endl;

				std::function<API_Create> funcExt = boost::dll::import_alias<API_Create>(pathFile, "create_plugin");
				boost::shared_ptr<CMyAPI> pModule = funcExt();
				std::cout << "Module [" << pModule->getName() << "], result: " << pModule->compute(vData) << std::endl;
			}
		}
	}

	return 0;
}
