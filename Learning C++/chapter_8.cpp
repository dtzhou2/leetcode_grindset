#include "height.h"
#include <iostream>

void print(int x, int y = 10) {
	// Sets 10 as the default argument for y 
	std::cout << "x: " << x << '\n';
	std::cout << "x: " << x << '\n';
}

// This is a basic function
// In order to utilise different types with this function new copies must be created referencing the different types
int max(int x, int y = -10000) {
	return (x < y) ? y : x;
}

// This is the same basic function but using templates rather than explicit typing
// Templates allow us to put any type that we would like in this function, enhancing flexibility and futureproofability
template <typename T>
// The above statement is required to define a template parameter. They should always be named a capital letter, starting with T
// There is no difference between the typename and class keywords here. Typename is more modern and descriptive but no functional difference
// One problem is that x and y HAVE to be the same type (TYPE CONVERSIONS NOT ALLOWED)
T min(T x, T y ) {
	return (y < x) ? x : y;
}

// Now if we instead define two template types, T and U: T and U can be different types and the program will still compile properly
// This is also a good candidate for an autoreturn type, as it will allow the compiuler to decide what to return so you dont have to guess
template <typename T, typename U>
auto avg(T x, U y) {
	return (x + y) / 2;
}

// Another way to write this function is to use auto instead of the template typename definitions (C++ 20 ONLY)
// Auto will automatically give x and y their own unique automatic types
auto rms(auto x, auto y) {
	return (x*x+y*y)/2
}