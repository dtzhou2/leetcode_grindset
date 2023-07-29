#pragma once
#ifndef PASSFAIL_H
#define PASSFAIL_H

bool passOrFail() {
	static int counter{ 0 };
	if (counter > 2)
	{
		return false;
	}
	counter++;
	return true;
}

#endif