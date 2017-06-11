#pragma once
#include <memory>
#include "node_type.h"

class Node_base
{
public:
	Node_base() = default;
	virtual ~Node_base() = default;
	virtual Node_type get_type() const = 0;
	virtual void set_child(std::unique_ptr<Node_base> lhs, std::unique_ptr<Node_base> rhs = nullptr) = 0;
	virtual double calculate() const = 0;
};

