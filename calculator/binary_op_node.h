#pragma once
#include "op_node.h"
#include <memory>

class binary_op_node :
	public op_node
{
public:
	binary_op_node();
	~binary_op_node();
	void set_left_child(std::unique_ptr<node_base> lfc) override
	{
		left = std::move(lfc);
	}
	void set_right_child(std::unique_ptr<node_base> rfc) override
	{
		right = std::move(rfc);
	}
	virtual void set_child(std::unique_ptr<node_base> ch) override {};
	char get_type() const override
	{
		return 'b';
	}
protected:
	std::unique_ptr<node_base> left;
	std::unique_ptr<node_base> right;
};

