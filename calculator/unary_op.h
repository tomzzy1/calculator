#pragma once
#include <cmath>

namespace op
{ 
	struct negative
	{
		static const int priority = 3;
		double operator()(const double& val) const
		{
			return -val;
		}
	};

	struct sin
	{
		static const int priority = 3;
		double operator()(const double& val) const 
		{
			return std::sin(val);
		}
	};

	struct sqrt
	{
		static const int priority = 3;
		double operator()(const double& val) const 
		{
			return std::sqrt(val);
		}
	};
}