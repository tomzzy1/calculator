#pragma once
#include "op_node.h"

class Parentheses_node :
	public Op_node
{
public:
	Parentheses_node() = default;
	~Parentheses_node() = default;
	Node_type get_type() const override
	{
		return Node_type::parentheses;
	}
	size_t get_priority() const override { return 0; };

	double calculate() const override { return 0; };

	void set_child(std::unique_ptr<Node_base> lhs, std::unique_ptr<Node_base> rhs = nullptr) {}
};

