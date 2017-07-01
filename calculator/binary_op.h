#pragma once
#include <cmath>

namespace op
{

	struct plus
	{
		static constexpr int priority = 1;
		double operator()(double lhs, double rhs) const
		{
			return lhs + rhs;
		}
	};

	struct minus
	{
		static constexpr int priority = 1;
		double operator()(double lhs, double rhs) const
		{
			return lhs - rhs;
		}
	};

	struct multiply
	{
		static constexpr int priority = 2;
		double operator()(double lhs, double rhs) const
		{
			return lhs * rhs;
		}
	};

	struct divide
	{
		static constexpr int priority = 2;
		double operator()(double lhs, double rhs) const
		{
			return lhs / rhs;
		}
	};

	struct pow
	{
		static constexpr int priority = 3;
		double operator()(double lhs, double rhs) const
		{
			return std::pow(lhs, rhs);
		}
	};

}



