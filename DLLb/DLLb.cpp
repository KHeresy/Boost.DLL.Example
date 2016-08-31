#include "../API/MyAPI.h"

#include <iostream>

#include <boost/shared_ptr.hpp>
#include <boost/dll/alias.hpp>

class CAvg : public CMyAPI
{
public:
	CAvg()
	{
		std::cout << "CAvg constructor" << std::endl;
	}

	~CAvg()
	{
		std::cout << "CAvg deconstructor" << std::endl;
	}

	std::string getName() const override
	{
		return "CAvg";
	}

	double compute(const std::vector<double>& rData) const override
	{
		if (rData.size() == 0)
			return 0.0;

		double dSum = 0;
		for (const double& dVal : rData)
			dSum += dVal;

		return dSum / rData.size();
	}

public:
	static CMyAPI* create() {
		return new CAvg();
	}
};

BOOST_DLL_ALIAS(CAvg::create, create_plugin )
