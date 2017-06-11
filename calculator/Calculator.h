#pragma once
#include <string>
#include <vector>
#include <stack>
#include <memory>
#include "binary_op_node.h"
#include "binary_op.h"
#include "unary_op.h"
#include "unary_op_node.h"

using std::unique_ptr;
using std::string;
using std::make_unique;

class Calculator
{
public:
	Calculator() = default;
	~Calculator() = default;
	double calculate(const std::string& text);
private:
	unique_ptr<Op_node> set_operators(const string& c) //tool function
	{
		if (c.size() == 1)
		{
			switch (c.front())
			{
			case'+':
				return make_unique<binary_op_node<op::plus>>();
			case'-':
				return make_unique<binary_op_node<op::minus>>();
			case'*':
				return make_unique<binary_op_node<op::multiply>>();
			case'/':
				return make_unique<binary_op_node<op::divide>>();
			case'^':
				return make_unique<binary_op_node<op::pow>>();
			default:
				break;
			}
		}

	}

	unique_ptr<Op_node> set_unary_operators(const string& c) //tool function
	{
		if (c.size() == 1)
		{
			switch (c.front())
			{
			case'-':
				return make_unique<unary_op_node<op::negative>>();
			default:
				break;
			}
		}
		else if (c == "sin")
		{
			return make_unique<unary_op_node<op::sin>>();
		}
		else if (c == "sqrt")
		{
			return make_unique<unary_op_node<op::sqrt>>();
		}
	}

	void push_top_and_pop(std::vector<unique_ptr<Node_base>>& v, std::stack<unique_ptr<Op_node>>& s) //tool function
	{
		v.push_back(std::move(s.top()));
		s.pop();
	}

	string get_operator(const string& text, string::const_iterator& pos) //tool function
	{
		auto first = pos;
		auto last = first;
		if (!(*pos >= 'a'&& *pos <= 'z'))
			while (!(*last >= '0' && *last <= '9' || *last == '.' || *last == '(')
				&& !(*last >= 'a'&& *last <= 'z'))
				++last;
		else
			while (*last >= 'a'&& *last <= 'z')
				++last;
		pos += (last - first - 1);
		return text.substr(first - text.begin(), last - first);
	}
};

