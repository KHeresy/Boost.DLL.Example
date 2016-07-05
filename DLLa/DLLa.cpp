#include "../API/MyAPI.h"

#include <iostream>

#include <boost/shared_ptr.hpp>
#include <boost/dll/alias.hpp>

class CSum : public CMyAPI
{
public:
	CSum()
	{
		std::cout << "CSum constructor" << std::endl;
	}

	~CSum()
	{
		std::cout << "CSum deconstructor" << std::endl;
	}

	std::string getName() const override
	{
		return "CSum";
	}

	double compute(const std::vector<double>& rData) const override
	{
		double dSum = 0;
		for (const double& dVal : rData)
			dSum += dVal;

		return dSum;
	}

public:
	static boost::shared_ptr<CMyAPI> create() {
		return boost::shared_ptr<CMyAPI>( new CSum() );
	}
};

BOOST_DLL_ALIAS( CSum::create, create_plugin )
