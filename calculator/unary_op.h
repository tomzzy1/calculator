#pragma once
#include <cmath>

namespace op
{ 
	struct negative
	{
		static constexpr int priority = 3;
		double operator()(double val) const
		{
			return -val;
		}
	};

	struct sin
	{
		static constexpr int priority = 3;
		double operator()(double val) const 
		{
			return std::sin(val);
		}
	};

	struct sqrt
	{
		static constexpr int priority = 3;
		double operator()(double val) const 
		{
			return std::sqrt(val);
		}
	};
}