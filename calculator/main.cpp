#include <iostream>
#include <iomanip>
#include <string>
#include "Calculator.h"

int main()
{
	std::string text;
	std::cin >> text;
	Calculator calc;
	std::cout << std::setprecision(20) << calc.calculate(text);
	std::cin.get();
	std::cin.get();
	return 0;
}
