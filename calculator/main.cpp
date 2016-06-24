#include <iostream>
#include <stack>
#include <vector>
#include <memory>
#include <string>
#include <ctime>
#include "utility_node.h"

int main()
{	
	string text;
	cin >> text;
	double result;
	auto start = clock();
	for (int i = 0; i < 1000000; ++i)
	{
		stack<unique_ptr<op_node>> operators;
		vector<unique_ptr<node_base>> tree_base;
		auto pos = 0;
		auto length = 0;
		if ((text.front() >= '0' && text.front() <= '9'))
			++length;
		else if (text.front() == '(')
			operators.push(make_unique<parentheses_node>());
		else
			operators.push(set_unary_operators(text.front()));
		for (auto word = text.begin() + 1; word != text.end(); ++word)
		{
				if ((*word >= '0' && *word <= '9') || *word == '.') //deal with numbers
				{
					if (length == 0)
						pos = word - text.begin();
					++length;
				}
				else if (*word == '(')
				{
					operators.push(make_unique<parentheses_node>());
				}
				else if (*word != '(' && *word != ')') //binary operators
				{
					if (*(word - 1) >= '0'&& *(word - 1) <= '9' || *(word - 1) == ')')
					{
						if (*(word - 1) != ')')
						{
							tree_base.push_back(make_unique<number_node>(text.substr(pos, length)));
							length = 0;
						}
						while (!operators.empty()
							&& get_priority(*word) <= operators.top()->get_priority())
						{
							tree_base.push_back(std::move(operators.top()));
							operators.pop();
						}
						operators.push(set_operators(*word));
					}
					else //unary operators
					{
						while (!operators.empty()
							&& get_unary_priority(*word) <= operators.top()->get_priority())
						{
							tree_base.push_back(std::move(operators.top()));
							operators.pop();
						}
						operators.push(set_unary_operators(*word));
					}
				}
				else if (*word == ')')
				{
					if (*(word - 1) != ')')
					{
						tree_base.push_back(make_unique<number_node>(text.substr(pos, length)));
						length = 0;
					}
					while (operators.top()->get_type() != '(')
					{
						tree_base.push_back(std::move(operators.top()));
						operators.pop();
					}
					operators.pop();
				}
			}
		if (text.back() != ')')
			tree_base.push_back(make_unique<number_node>(text.substr(pos, length)));
		while (!operators.empty())
		{
			tree_base.push_back(std::move(operators.top()));
			operators.pop();
		}
		stack<unique_ptr<node_base>> tree_stack;
		for (auto &node : tree_base)
		{
			if (node->get_type() == 'n')
			{
				tree_stack.push(std::move(node));
			}
			else if (node->get_type() == 'b')
			{
				node->set_left_child(std::move(tree_stack.top()));
				tree_stack.pop();
				node->set_right_child(std::move(tree_stack.top()));
				tree_stack.pop();
				tree_stack.push(std::move(node));
			}
			else if (node->get_type() == 'u')
			{
				node->set_child(std::move(tree_stack.top()));
				tree_stack.pop();
				tree_stack.push(std::move(node));
			}
		}
		result = tree_stack.top()->calculate();
	}
	auto end = clock();
	cout << "Running time is: " << static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
	cout << result;
	cin.get();
	cin.get();
	return 0;
}
