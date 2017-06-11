#include "Calculator.h"
#include "parentheses_node.h"
#include "number_node.h"
#include "node_type.h"

double Calculator::calculate(const std::string& text)
{
	std::stack<unique_ptr<Op_node>> operators;
	std::vector<unique_ptr<Node_base>> tree_base;
	auto pos = 0;
	auto length = 0;
	auto word = text.begin();
	if (text.front() >= '0' && text.front() <= '9')
	{
		++length;
	}
	else if (text.front() == '(')
	{
		operators.push(make_unique<Parentheses_node>());
	}
	else
	{
		operators.push(set_unary_operators(get_operator(text, word)));
	}
	++word;
	while (word != text.end())
	{
		if ((*word >= '0' && *word <= '9') || *word == '.') //deal with numbers
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
			if (*(word - 1) >= '0'&& *(word - 1) <= '9' || *(word - 1) == ')')//binary operators
			{
				auto op = set_operators(op_text);
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
				auto op = set_unary_operators(op_text);
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
			auto& tmp = tree_stack.top();
			tree_stack.pop();
			node->set_child(std::move(tree_stack.top()), std::move(tmp));
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
