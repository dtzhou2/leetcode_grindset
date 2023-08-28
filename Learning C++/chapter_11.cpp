#include <algorithm>
#include <array>
#include <iostream> 
#include <array>
#include <iostream>

// ALWAYS pass std::array's by reference
// Far too expensive to copy otherwise
// You can templatize the function so it will work with any length of array
template <typename T, std::size_t size>
void array_reference_test(std::array<T, size>& arr) {
	std::cout << "The length of your array is: " << arr.size() << '\n';
	
	// This is one way of iterating through elements in an std::array
	// We greatly prefer this way because it is much cleaner
	for (int element : arr)
		std::cout << element << '\n';
	
	// This is another, NOTE THAT the iterator HAS TO be of the size_t type
	// The iterator HAS TO be of the size_t type because there is a signed/unsigned mismatch
	// arr.size returns a size_t type
	// size_t is unsigned while int is unsigned
	// Therefore comparing size_t and int will break things
	for (std::size_t i{ 0 }; i < arr.size(); ++i) {
		std::cout << element << '\n';
	}

}