#pragma once
#include "node_base.h"
#include <string>

class Number_node :
	public Node_base
{
public:
	Number_node() = default;
	Number_node(std::string& s) :num(std::stod(s)) {}
	~Number_node() = default;
	Node_type get_type() const override
	{
		return Node_type::number;
	}
	double calculate() const override
	{
		return num;
	}
	void set_child(std::unique_ptr<Node_base> lhs, std::unique_ptr<Node_base> rhs = nullptr) {}
private:
	double num;
};

