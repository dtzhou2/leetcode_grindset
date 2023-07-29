#pragma once
// Alternative form of header guard relying on the compiler to see this and automatically guard header
#ifndef ADD_H
#define ADD_H
// Header guard makes sure that the header file cannot be double included
// If this is the first time the header is being included, set a flag // define it
// If this is the second time the header is being included, the ifndef statement prevents it from compiling

int add(int x, int y);
// All this file does is contain all the function prototypes / declerations we want to show up
// in add.cpp

#endif