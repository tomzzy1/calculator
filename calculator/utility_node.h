#pragma once
#include "binary_op_node.h"
#include "node_base.h"
#include "number_node.h"
#include "plus_node.h"
#include "minus_node.h"
#include "multiply_node.h"
#include "divide_node.h"
#include "pow_node.h"
#include "parentheses_node.h"
#include "unary_minus.h"

using namespace std;

inline size_t get_priority(char c)
{
	switch (c)
	{
	case'+':
	case'-':
		return 1;
	case'*':
	case'/':
		return 2;
	case'^':
		return 3;
	}
}

size_t get_unary_priority(char c)
{
	switch (c)
	{
	case'-':
		return 3;
	default:
		break;
	}
}

unique_ptr<op_node> set_operators(char c)
{
	switch (c)
	{
	case'+':
		return make_unique<plus_node>();
	case'-':
		return make_unique<minus_node>();
	case'*':
		return make_unique<multiply_node>();
	case'/':
		return make_unique<divide_node>();
	case'^':
		return make_unique<pow_node>();
	default:
		break;
	}
}

unique_ptr<op_node> set_unary_operators(char c)
{
	switch (c)
	{
	case'-':
		return make_unique<unary_minus>();
	default:
		break;
	}
}