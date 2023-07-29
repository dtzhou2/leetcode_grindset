#include "double.h"
#include <iostream>

double enterDouble()
{
	double input{};
	std::cout << "Enter a double ";
	std::cin >> input;
	return input;
}

char getOperator()
{
	char oper{};
	std::cout << "Enter one of the following: +, -, *, or /: ";
	std::cin >> oper;
	return oper;
}

void printResult(double first_num, double second_num, char operation)
{
	if (operation == '+')
		std::cout << first_num << " " << operation << " " << second_num << " = " << first_num + second_num << "\n";
	else if (operation == '-')
		std::cout << first_num << " " << operation << " " << second_num << " = " << first_num - second_num << "\n";
	else if (operation == '*')
		std::cout << first_num << " " << operation << " " << second_num << " = " << first_num * second_num << "\n";
	else if (operation == '/')
		std::cout << first_num << " " << operation << " " << second_num << " = " << first_num / second_num << "\n";
}
