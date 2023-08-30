#include <algorithm>
#include <array>
#include <iostream> 
#include <array>
#include <iostream>
#include <vector>

// ALWAYS pass std::array's by reference
// Far too expensive to copy otherwise
// You can templatize the function so it will work with any length of array
template <typename T, std::size_t size>
void array_reference_test(std::array<T, size>& arr) {
	std::cout << "The length of your array is: " << arr.size() << '\n';
	
	// This is one way of iterating through elements in an std::array
	// We greatly prefer this way because it is much cleaner
	for (T element : arr)
		std::cout << element << '\n';
	
	// This is another, NOTE THAT the iterator HAS TO be of the size_t type
	// The iterator HAS TO be of the size_t type because there is a signed/unsigned mismatch
	// arr.size returns a size_t type
	// size_t is unsigned while int is unsigned
	// Therefore comparing size_t and int will break things
	for (std::size_t i{ 0 }; i < arr.size(); ++i) {
		std::cout << arr[i] << '\n';
	}

}

template <typename T>
std::vector<T> vector_test(std::vector<T> arr) {
	for (T element : arr) {
		std::cout << element << '\n';
	}

	// Returning a vector by value is ok b ecause C++ can do trickery to make it efficient
	return arr;
}

bool is_prime(int input) {
	for (int i{ 2 }; i < input/2; i++)
		if (input % i == 0)
			return false;
	
	return true;

}