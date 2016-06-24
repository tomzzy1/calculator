#pragma once
#include "binary_op_node.h"
class minus_node :
	public binary_op_node
{
public:
	minus_node();
	~minus_node();
	size_t get_priority() const override
	{
		return 1;
	};
	double calculate()override
	{
		return right->calculate() - left->calculate();
	}
};

