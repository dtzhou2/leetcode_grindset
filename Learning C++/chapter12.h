#pragma once
#ifndef CHAPTER_12_H
#define CHAPTER_12_H

using ArithmeticFunction = int (*)(int, int);

int funfun();
int notfunfun();
bool ascending(int first_num, int second_num);
void SelectionSort(int* array, int size, bool (*comparisonFcn)(int, int));
void basic_calculator();
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
ArithmeticFunction getArithmeticFunction(char op);

#endif // !CHAPTER_12_H
