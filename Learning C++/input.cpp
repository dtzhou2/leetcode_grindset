#include <iostream>

// Helper function that reads user input and returns it
int getInteger()
{
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;
	return x;
}