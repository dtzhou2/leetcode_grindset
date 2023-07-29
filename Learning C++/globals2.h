#pragma once
#ifndef GLOBALS2_H
#define GLOBALS2_H

// This method puts all the global variables in the header file
// The downside to this method is it will make compile times longer
// In order to change one of these constants every file using the constants 
// must be recompiled
// Furthermore, if the variables arent constant they will eat a ton of memory

namespace constants2
{
	const int x{ 5 };
	const int y{ 3 };
}

#endif
