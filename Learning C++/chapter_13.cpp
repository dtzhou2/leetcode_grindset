#include "chapter_13.h"
#include <iostream>

class DateClass
{
	// In classes all members not placed under public are private by default
	// Private members can only be accessed by other members
	// Private members are applied PER CLASS NOT PER OBJECT
	// Any function in a class can access ANY private members of ANY
	// OF THAT CLASS'S OBJECTS
	int m_month{}; 
	int m_day{};
	int m_year{};

public:
	// Everything under public statement is public
	// Public members can be accessed by everyone
	// Make member variables private annd member fuctions public

	void setDate(int month, int day, int year)
	{
		m_month = month;
		m_day = day;
		m_year = year;
	}

};

class Point3d
{
private:
	int m_x;
	int m_y;
	int m_z;
public:
	void setValues(int x, int y, int z) {
		m_x = x;
		m_y = y;
		m_z = z;
	}
	
	void print() {
		std::cout << "<" << m_x << ", " << m_y << ", " << m_z << '\n';
	}

	bool isEqual(Point3d compare_point)
	{
		return compare_point.m_x == m_x && compare_point.m_y == m_y && compare_point.m_z == m_z;
	}

};