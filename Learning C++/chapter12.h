#pragma once
#ifndef CHAPTER_12_H
#define CHAPTER_12_H

using ArithmeticFunction = int (*)(int, int);

auto funfun();
auto notfunfun();
auto ascending(int first_num, int second_num);
auto SelectionSort(int* array, int size, bool (*comparisonFcn)(int, int));
auto basic_calculator();
auto subtract(int a, int b);
auto multiply(int a, int b);
auto divide(int a, int b);
ArithmeticFunction getArithmeticFunction(char op);

#endif // !CHAPTER_12_H
