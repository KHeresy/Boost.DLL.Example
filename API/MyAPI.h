#pragma once

// STD Header
#include <string>
#include <vector>

// Boost Header
#include <boost/shared_ptr.hpp>

// Define compute class
class CMyAPI
{
public:
	virtual std::string getName() const = 0;
	virtual double compute(const std::vector<double>& rData) const = 0;
};

// define create function
typedef CMyAPI*(API_Create)();
