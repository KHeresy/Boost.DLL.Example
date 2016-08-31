#include "../API/MyAPI.h"

// STD Headers
#include <iostream>

// Boost Headers
#include <boost/dll.hpp>

struct library_holding_deleter
{
	library_holding_deleter(const boost::filesystem::path& pathDLL)
	{
		mLib = boost::make_shared<boost::dll::shared_library>(pathDLL);
	}

	boost::shared_ptr<boost::dll::shared_library> mLib;

	void operator()(CMyAPI* p) const {
		delete p;
	}
};

boost::shared_ptr<CMyAPI> GetModule( const boost::filesystem::path& pathDLL )
{
	std::function<API_Create> funcExt = boost::dll::import_alias<API_Create>(pathDLL, "create_plugin");
	CMyAPI* pModule = funcExt();
	return boost::shared_ptr<CMyAPI>(pModule,library_holding_deleter(pathDLL));
}

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

				boost::shared_ptr<CMyAPI> pModule = GetModule(pathFile);
				std::cout << "Module [" << pModule->getName() << "], result: " << pModule->compute(vData) << std::endl;
			}
		}
	}

	return 0;
}
