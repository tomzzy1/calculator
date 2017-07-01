#include "Calculator.h"
#include "parentheses_node.h"
#include "number_node.h"
#include "node_type.h"
#include <cctype>
#include <algorithm>
#include <iostream>

double Calculator::calculate(const std::string& text)
{
	std::stack<unique_ptr<Op_node>> operators;
	std::vector<unique_ptr<Node_base>> tree_base;
	auto pos = 0;
	auto length = 0;
	auto word = text.begin();
	if (std::isdigit(text.front()))
	{
		++length;
	}
	else if (text.front() == '(')
	{
		operators.push(make_unique<Parentheses_node>());
	}
	else
	{
		operators.push(make_unary_operators(get_operator(text, word)));
	}
	++word;
	while (word != text.end())
	{
		if (std::isdigit(*word) || *word == '.') //deal with numbers
		{
			if (length == 0)
				pos = word - text.begin();
			++length;
		}
		else if (*word == '(')
		{
			operators.push(make_unique<Parentheses_node>());
		}
		else if (*word != '(' && *word != ')')
		{
			auto op_text = get_operator(text, word);
 			if (std::isdigit(*(word - 1)) || *(word - 1) == ')')//binary operators
			{
				auto op = make_binary_operators(op_text);
				if (*(word - 1) != ')')
				{
					tree_base.push_back(make_unique<Number_node>(text.substr(pos, length)));
					length = 0;
				}
				while (!operators.empty()
					&& op->get_priority() <= operators.top()->get_priority())
				{
					push_top_and_pop(tree_base, operators);
				}
				operators.push(std::move(op));
			}
			else //unary operators
			{
				auto op = make_unary_operators(op_text);
				while (!operators.empty()
					&& op->get_priority() <= operators.top()->get_priority())
				{
					push_top_and_pop(tree_base, operators);
				}
				operators.push(std::move(op));
			}
		}
		else if (*word == ')')
		{
			if (*(word - 1) != ')')
			{
				tree_base.push_back(make_unique<Number_node>(text.substr(pos, length)));
				length = 0;
			}
			while (operators.top()->get_type() != Node_type::parentheses)
			{
				push_top_and_pop(tree_base, operators);
			}
			operators.pop();
		}
		++word;
	}
	if (text.back() != ')')
		tree_base.push_back(make_unique<Number_node>(text.substr(pos, length)));
	while (!operators.empty())
	{
		push_top_and_pop(tree_base, operators);
	}
	
	std::stack<unique_ptr<Node_base>> tree_stack;
	for (auto& node : tree_base)
	{
		if (node->get_type() == Node_type::number)
		{
			tree_stack.push(std::move(node));
		}
		else if (node->get_type() == Node_type::binary)
		{
			auto top = std::move(tree_stack.top());
			tree_stack.pop();
			node->set_child(std::move(tree_stack.top()), std::move(top));
			tree_stack.pop();
			tree_stack.push(std::move(node));
		}
		else if (node->get_type() == Node_type::unary)
		{
			node->set_child(std::move(tree_stack.top()));
			tree_stack.pop();
			tree_stack.push(std::move(node));
		}
	}
	return tree_stack.top()->calculate();
}

unique_ptr<Op_node> Calculator::make_binary_operators(const string& c)
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

unique_ptr<Op_node> Calculator::make_unary_operators(const string& c)
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

string Calculator::get_operator(const string& text, string::const_iterator& pos)
{
	auto first = pos;
	auto last = first;
	if (std::isalpha(*pos))
	{	
		last = std::find_if_not(pos, text.end(), [](const auto& c)
		{
			return std::isalpha(c);
		});
	}
	else
	{
		last = std::find_if(pos, text.end(), [](const auto& c)
		{
			return std::isalnum(c) || c == '.' || c == '(';
		});
	}
	pos += (last - first - 1);
	return text.substr(first - text.begin(), last - first);
}
