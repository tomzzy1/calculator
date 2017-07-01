#pragma once
#include <string>
#include <vector>
#include <stack>
#include <memory>
#include <cctype>
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
	static double calculate(const std::string& text);

private:

	static inline unique_ptr<Op_node> make_binary_operators(const string& c); //factory function

	static inline unique_ptr<Op_node> make_unary_operators(const string& c); //factory function

	static void push_top_and_pop(std::vector<unique_ptr<Node_base>>& v, std::stack<unique_ptr<Op_node>>& s) //tool function
	{
		v.push_back(std::move(s.top()));
		s.pop();
	}

	static string get_operator(const string& text, string::const_iterator& pos); //tool function

};

