#pragma once
#include "unary_op_node.h"
class unary_minus :
	public unary_op_node
{
public:
	unary_minus();
	~unary_minus();
	double calculate()override
	{
		return -child->calculate();
	}
	size_t get_priority()const override
	{
		return 3;
	}
};

