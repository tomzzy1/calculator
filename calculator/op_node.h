#pragma once
#include "node_base.h"
class op_node :
	public node_base
{
public:
	op_node();
	~op_node();
	virtual size_t get_priority() const = 0;
};

