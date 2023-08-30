#include <iostream>
#include "chapter12.h"
#include "add.h"

int funfun()
{
	return 5;
}

int notfunfun()
{
	return 7;
}

// This creates an alias which makes using the function pointer syntax slightly less headache inducing
using ComparisonFunction = bool (*)(int, int);

// Here we can use function pointers to pass in a function to the function, allowing us to
// modify the behavior of the sort. We can sort by descending or by some weird sort, just by
// changing the comparison algorithm which is passed in through the function pointer
void SelectionSort(int* array, int size, ComparisonFunction compare = ascending )
{
	for (int startIndex{ 0 }; startIndex < (size - 1); ++startIndex) {
		int bestIndex{ startIndex };
		
		for (int currentIndex{ startIndex + 1 }; currentIndex < size; ++currentIndex)
		{
			if (compare (array[bestIndex], array[currentIndex]))
			{
				bestIndex = currentIndex;
			}
		}
	}
}

bool ascending(int first_num, int second_num) {
	return first_num > second_num;
}

void basic_calculator() {
	int num1{};
	int num2{};
	char op{};

	std::cout << " Please input one integer";
	std::cin >> num1;
	std::cout << '\n';
	std::cout << "Please input the other integer";
	std::cin >> num2;
	std::cout << '\n';
	std::cout << " Please input the operation";
	std::cin >> op;
	
	do
	{
		std::cout << "Enter an operation ('+', '-', '*', '/'): ";
		std::cin >> op;
	} while (op != '+' && op != '-' && op != '*' && op != '/');

	ArithmeticFunction correct_operation = getArithmeticFunction(op);
	if (correct_operation != nullptr)
		correct_operation(num1, num2);

}

ArithmeticFunction getArithmeticFunction(char op) {
	switch (op)
	{
	case '+':
		return &add;
	case '-':
		return &subtract;
	case '*':
		return &multiply;
	case '/':
		return &divide;
	default:
		return nullptr;
	}
}

int subtract(int a, int b) {
	return a - b;
}

int multiply(int a, int b) {
	return a * b;
}

int divide(int a, int b) {
	return a / b;
}