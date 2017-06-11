#pragma once
#include <cmath>

namespace op
{

	struct plus
	{
		static const int priority = 1;
		double operator()(const double& lhs,const double& rhs) const
		{
			return lhs + rhs;
		}
	};

	struct minus
	{
		static const int priority = 1;
		double operator()(const double& lhs,const double& rhs) const
		{
			return lhs - rhs;
		}
	};

	struct multiply
	{
		static const int priority = 2;
		double operator()(const double& lhs,const double& rhs) const
		{
			return lhs * rhs;
		}
	};

	struct divide
	{
		static const int priority = 2;
		double operator()(const double& lhs,const double& rhs) const
		{
			return lhs / rhs;
		}
	};

	struct pow
	{
		static const int priority = 3;
		double operator()(const double& lhs,const double& rhs) const
		{
			return std::pow(lhs, rhs);
		}
	};

}



