#include "chapter9.h"
#include <iostream>

// When you pass a function by reference, it will pass an alias of the function, letting you change the variable
void addOne(int& x) {
	x += 1; 
	std::cout << x << "\n";
}

// When you dont pass a function by reference, it will make a copy of the variable
void addTwo(int x) {
	x += 2;
	std::cout << x << "\n";
}

// You can also pass a pointer by reference allowing you to change the value of the pointer
void nullify(char*& ptr) {
	ptr = nullptr;
}