#pragma once
#include <memory>

class node_base
{
public:
	node_base();
	virtual ~node_base();
	virtual char get_type() const = 0;
	virtual void set_left_child(std::unique_ptr<node_base> lfc) = 0;
	virtual void set_right_child(std::unique_ptr<node_base> rfc) = 0;
	virtual void set_child(std::unique_ptr<node_base> ch) = 0;
	virtual double calculate() = 0;
};

