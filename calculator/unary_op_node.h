#pragma once
#include "op_node.h"
#include <memory>

template<typename Fn> 
class unary_op_node :
	public Op_node
{
public:
	unary_op_node() = default;
	~unary_op_node() = default;
	void set_child(std::unique_ptr<Node_base> lhs, std::unique_ptr<Node_base> rhs = nullptr) override
	{
		child = std::move(lhs);
	}
	Node_type get_type() const override
	{
		return Node_type::unary;
	}
	size_t get_priority() const override
	{
		return Fn::priority;
	}
	double calculate() const override
	{
		return fn(child->calculate());
	}
private:
	std::unique_ptr<Node_base> child;
	Fn fn;
};

