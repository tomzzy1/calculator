#pragma once
#include "op_node.h"

class parentheses_node :
	public op_node
{
public:
	parentheses_node();
	~parentheses_node();
	char get_type() const override
	{
		return '(';
	}
	void set_left_child(std::unique_ptr<node_base> lfc) override {};

	void set_right_child(std::unique_ptr<node_base> rfc) override {};

	virtual void set_child(std::unique_ptr<node_base> ch) override {};

	virtual size_t get_priority() const override { return 0; };

	double calculate() override { return 0; };
};

