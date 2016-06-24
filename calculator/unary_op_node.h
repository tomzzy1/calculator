#pragma once
#include "op_node.h"
#include <memory>

class unary_op_node :
	public op_node
{
public:
	unary_op_node();
	~unary_op_node();
	void set_child(std::unique_ptr<node_base> ch)
	{
		child = std::move(ch);
	}
	char get_type() const override
	{
		return 'u';
	}
	void set_left_child(std::unique_ptr<node_base> lfc) override {};

	void set_right_child(std::unique_ptr<node_base> rfc) override {};
protected:
	std::unique_ptr<node_base> child;
};

