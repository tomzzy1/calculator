#pragma once
#include "binary_op_node.h"
class divide_node :
	public binary_op_node
{
public:
	divide_node();
	~divide_node();
	size_t get_priority() const override
	{
		return 2;
	};
	double calculate()override
	{
		return right->calculate() / left->calculate();
	}
};

