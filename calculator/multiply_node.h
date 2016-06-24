#pragma once
#include "binary_op_node.h"
class multiply_node :
	public binary_op_node
{
public:
	multiply_node();
	~multiply_node();
	size_t get_priority() const override
	{
		return 2;
	};
	double calculate()override
	{
		return right->calculate() * left->calculate();
	}
};

