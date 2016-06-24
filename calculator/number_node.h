#pragma once
#include "node_base.h"
#include <array>

class number_node :
	public node_base
{
public:
	number_node();
	number_node(std::string& s);
	~number_node();
	char get_type() const override
	{ return 'n'; }
	double calculate() override
	{
		return num;
	}
	void set_left_child(std::unique_ptr<node_base> lfc) override {};

	void set_right_child(std::unique_ptr<node_base> rfc)override {};

	virtual void set_child(std::unique_ptr<node_base> ch) override {};
private:
	double num;
};

