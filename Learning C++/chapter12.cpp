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
void SelectionSort(int* array, int size, ComparisonFunction = ascending )
{
	for (int startIndex{ 0 }; startIndex < (size - 1); ++startIndex) {
		int bestIndex{ startIndex };
		
		for (int currentIndex{ startIndex + 1 }; currentIndex < size; ++currentIndex)
		{
			if (comparisonFcn(array[bestIndex], array[currentIndex]))
			{
				bestIndex = currentIndex;
			}
		}
	}
}

bool ascending(int first_num, int second_num) {
	return first_num > second_num;
}