#pragma once
#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace constants3
{
	// Inline constants allow the compiler to fold all similar variables into
	// one variable, saving memory.
	// Still has the same compile time issues though not as big of a problem
	inline constexpr int x{ 3 };
	// Constexpr forces the compiler to treat it as a compile time constant
	inline constexpr int y{ 9 };

}

namespace constants {
	inline const int max_class_size{ 35 };
}

#endif // !CONSTANTS_H
