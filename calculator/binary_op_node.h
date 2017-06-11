#pragma once
#include "op_node.h"
#include <memory>

template<typename Fn>
class binary_op_node :
	public Op_node
{
public:
	binary_op_node() = default;
	~binary_op_node() = default;
	void set_child(std::unique_ptr<Node_base> lhs, std::unique_ptr<Node_base> rhs = nullptr) override
	{
		left = std::move(lhs);
		right = std::move(rhs);
	}
	Node_type get_type() const override
	{
		return Node_type::binary;
	}
	double calculate() const override
	{
		return fn(left->calculate(), right->calculate());
	}
	size_t get_priority() const override
	{
		return Fn::priority;
	}
private:
	std::unique_ptr<Node_base> left;
	std::unique_ptr<Node_base> right;
	Fn fn;
};

