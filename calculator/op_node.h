#pragma once
#include "node_base.h"
class Op_node :
	public Node_base
{
public:
	Op_node() = default;
	virtual~Op_node() = default;
	virtual size_t get_priority() const = 0;
	//virtual void set_child(std::unique_ptr<node_base> lhs, std::unique_ptr<node_base> rhs) = 0;
};

