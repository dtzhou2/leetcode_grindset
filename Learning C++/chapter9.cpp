#include "chapter9.h"
#include <iostream>

void addOne(int& x) {
	x += 1; 
	std::cout << x << "\n";
}

void addTwo(int x) {
	x += 2;
	std::cout << x << "\n";
}