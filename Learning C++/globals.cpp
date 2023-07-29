#include "globals.h"
namespace constants 
{
	// By putting all our globals in a seperate cpp file you have a single variable
	// shared across all files, which avoids long recompilation times and saves memory
	extern int x{ 1 };
	// Putting the extern keyword allows this variable to be used in multiple files
	// In order to use it we also need a forward decleration for the variable
	extern int y{ 5 };
}