#include "number_node.h"


number_node::number_node(): num(0)
{
}

number_node::number_node(std::string& s) :num(0)
{
	auto point = s.begin();
	for (; point != s.end(); ++point)
	{
		if (*point == '.')
			break;
	}
	if (point != s.end())
	{
		for (auto word = s.begin(); word != point; ++word)
		{
			num += (*word - '0')*pow(10, point - word - 1);
		}
		int power = -1;
		for (auto word = point + 1; word != s.end(); ++word)
		{
			num += (*word - '0')*pow(10, power--);
		}
	}
	else
	{
		int power = s.size() - 1;
		for (auto word = s.begin(); word != s.end(); ++word)
		{
			num += (*word - '0')*pow(10, power--);
		}
	}
}

number_node::~number_node()
{
}
