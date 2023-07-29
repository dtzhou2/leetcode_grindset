#include <iostream>
#include <io.h>

void writeAnswer(int input) 
{
	std::cout << "Here is your answer " << input << "\n";
}

int readAnswer()
{
	int input{};
	std::cout << "What number would you like to input ";
	std::cin >> input;
	return input;
}