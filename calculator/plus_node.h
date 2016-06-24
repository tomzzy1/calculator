#pragma once
#include "binary_op_node.h"
class plus_node :
	public binary_op_node
{
public:
	plus_node();
	~plus_node();
	size_t get_priority() const override
	{
		return 1;
	};
	double calculate()override
	{
		return right->calculate() + left->calculate();
	}
};

