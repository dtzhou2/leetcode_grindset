#include "chapter_13.h"
#include <iostream>
#include <cassert>
#include <cstddef>
#include <numeric>
#include <chrono>
#include <cmath>

// To reference classes defined in a seperate header file you call the fucntions as you would in a seperate namesapce
Date::Date(int year, int month, int day)
{
	setDate(year, month, day);
}

void Date::setDate(int year, int month, int day)
{
	m_year = year;
	m_month = month;
	m_day = day;
}

Point3d::Point3d(int x, int y, int z)
{
	setValues(x, y, z);
}

// This is an example of a constructor that can function both as a default constructor and a value constructor
// Lets you assign values or uses 0 and 1 to set the default values of the fraction
Fraction::Fraction(int numerator = 0 , int denominator = 1)
	: m_numerator{ numerator } // This is useful because it lets you intialize const variables
	, m_denominator{ denominator } // In addition it is slightly more efficient
{
}

// Member functions like these have a 'hidden' parameter called this that refers to the object 
// that the member function is called on
void Point3d::setValues(int x, int y, int z)
{
	// You can explicitly distinguish between the object's variables and external variables by using the this pointer
	// Most programmers tend to avoid this because it adds more confusion for little benefit
	// If you seperate the member variables with the m_ postfix it is just as clear with less typing
	this->m_x = x;
	this->m_y = y;
	this->m_z = z;
}

Ball::Ball(std::string color, double radius)
	: m_color{ color } // This is called a member intializer list
	, m_radius{ radius } // Instead of performing copy intialization

{}

RGBA::RGBA(std::uint8_t red, std::uint8_t blue, std::uint8_t green, std::uint8_t alpha)
	: m_red{ red }
	, m_blue{ blue }
	, m_green{ green }
	, m_alpha{ alpha }
{}

Employee::Employee(int id, std::string_view name, int wage)
	: m_id{ id }
	, m_name{ name }
	, m_wage{ wage }
	, m_dob {2003}
{
	std::cout << "Employee" << m_name << "created. \n";
}

Employee::Employee(std::string_view name)
	: Employee{ 0, name } // You can call other constructors in the member intializer list, also known as delegating constructors
	// This allows you to reduce duplicate code by calling another constructor to intialize common defaults shared between all constructors
{
	// An alternative if the common tasks do not involve intializing variables is to have a common setup function
	// That performs non variable init tasks and then the variable init tasks can be handled by member list init
	setup();
}

void Employee::print()
{
	std::cout << "The employee id is " << m_id << " The dob is " << m_dob << " The wage is " << m_wage;
}

void Employee::setup() {
	std::cout << "Congrats on creating a new employee, performing setup tasks now " << '\n';
}

IntArray::IntArray(int length)
{
	assert(length > 0);

	m_array = new int[static_cast<std::size_t>(length)] {};
	m_length = length;

}

// This is a destructor. It helps clean up the class after you finish it. If not defined C++ will generate a default one
// for you automatically
IntArray::~IntArray()
{
	delete[] m_array;
}

int subtract(int x, int y)
{
	// When we do this, we create an anonymous variable that has a expression level lifetime
	// It will be destroyed as soon as the variable is over
	return x - y;
}

void print(const Cents& cents)
{
	std::cout << cents.getCents() << "cents \n";
}

void Timer::reset()
{
	m_beg = Clock::now();
}

double Timer::elapsed() const 
{
	// This returns the difference between when you first intialized/reset the timer and the current time
	// Extremely useful for timing the performance of function calls
	return std::chrono::duration_cast<Second>(Clock::now() - m_beg).count();
}

Point2d::Point2d(double x, double y)
	: m_x{ x }
	, m_y{ y }
{}

void Point2d::print()
{
	std::cout << "Your x coord is: " << m_x << " and your y coordinate is: " << m_y << '\n';
}

double distanceFrom(const Point2d& point1, const Point2d& point2)
{
	return std::sqrt((point1.m_x - point2.m_x) * (point1.m_x - point2.m_x) 
		+ (point1.m_y - point2.m_y) * (point1.m_y - point2.m_y));
}

HelloWorld::HelloWorld()
{
	m_data = new char[14];
	const char* init{ "Hello, World!" };
	for (int i = 0; i < 14; ++i)
		m_data[i] = init[i];
}

HelloWorld::~HelloWorld()
{
	delete[] m_data;
}

Monster::Monster(Type type, std::string_view name, std::string_view roar, int hp) 
	: m_type{type}
	, m_name{name}
	, m_roar{roar}
	, m_hp{hp}
{}

std::string_view Monster::getTypeString(Type type) 
{
	switch (type)
	{
		case Type::dragon:
			return "dragon";
		case Type::goblin:
			return "goblin";
		case Type::ogre:
			return "ogre";
		case Type::orc:
			return "orc";
		case Type::skeleton:
			return "skeleton";
		case Type::troll:
			return "troll";
		case Type::vampire:
			return "vampire";
		case Type::zombie:
			return "zombie";
		default:
			return "Invalid Monster Type";
	}

}
 
void Monster::print()
{
	std::cout << m_name << " the " << getTypeString(m_type) << " has " << m_hp << " hit points and says " << m_roar << '\n';
}

Monster MonsterGenerator::generate()
{
	return Monster{ Monster::skeleton, "Bones", "*rattle*", 4 };	
}



