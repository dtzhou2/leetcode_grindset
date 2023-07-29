#include "height.h"
#include <iostream>

namespace height{
	// This creates a new namespace to avoid / manage namespace collisions you could see
	// in instances where you want to duplicate function names
	double inputHeight()
	{
		std::cout << "Enter the height of the tower in meters: ";
		double height{};
		std::cin >> height;
		return height;
	}

	void printHeight(int time, double height, double gravity_constant)
	{
		double fallen_dist{ (gravity_constant * static_cast<double>(time) * static_cast<double>(time)) / 2 };
		double cur_height{ height - fallen_dist };
		if (cur_height > 0) {
			std::cout << "At " << time << " seconds, the ball is at height: " << cur_height << " meters \n";
		}
		else
			std::cout << "At " << time << " seconds, the ball is on the ground \n";
	}
}
