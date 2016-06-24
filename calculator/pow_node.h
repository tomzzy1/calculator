#pragma once
#include "binary_op_node.h"
class pow_node :
	public binary_op_node
{
public:
	pow_node();
	~pow_node();
	size_t get_priority() const override
	{
		return 4;
	};
	double calculate()override
	{
		return pow(right->calculate() , left->calculate());
	}
};

