#pragma once
#ifndef CHAPTER_11_H
#include <algorithm>
#include <array>
#include <iostream> 
#include <array>
#include <iostream>
#include <vector>

template <typename T, std::size_t size>
void array_reference_test(std::array<T, size>& arr);
template <typename T>
std::vector<T> vector_test(std::vector<T> arr);
bool is_prime(int input);

#endif // !CHAPTER_11_H