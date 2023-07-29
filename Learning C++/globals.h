#pragma once
#ifndef GLOBALS_H
#define GLOBALS_H

// This method has the variables as externally linked globals
// The downside is that means that all constants will be changed from
// compile time constants to run-time constants which is much less performant
// Since the compiler cannot see the variable values on compilation it cannot
// optimize them away

namespace constants4
{
	// Since your global variables are in a seperate namespace, your forward 
	// declerations also have to be in a seperate namespace
	extern int x;
	// In order to access the global variable from other files we need to include
	// Forward declerations, done by using the extern keyword and no intialization
	extern int y;
}

#endif
