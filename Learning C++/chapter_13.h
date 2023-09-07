#pragma once
#ifndef CHP_13_H
#define CHP_13_h
#include "chapter_13.h"
#include <string>
#include <cstdint>
#include <chrono>
#include <iostream>

// This is how you fit classes in header files
// Fit small getters and setters in the header file but put the bigger code functions in their own file
// This does not violate the ODR rule as long as you have proper header guards

class Date
{
private:
	int m_month{};
	int m_day{};
	int m_year{};

public:
	// This tells the compiler to create a default constructor, even if others are avaliable
	Date() = default;

	Date(int year, int month, int day);

	void setDate(int year, int month, int day);

	auto setYear(int year) { m_year = year; }
	auto setMonth(int month) { m_month = month; }
	auto setDay(int day) { m_day = day; }

	auto getYear() { return m_year; }
	auto getMonth() { return m_month; }
	auto getDay() { return m_day; }

};

class Point3d
{
private:
	int m_x;
	int m_y;
	int m_z;
	
public:
	Point3d(int x, int y, int z);

	void setValues(int x, int y, int z);

	auto setX(int x) { m_x = x; }
	auto setY(int y) { m_y = y; }
	auto setZ(int z) { m_z = z; }

	auto getX() { return m_x; }
	auto getY() { return m_y; }
	auto getZ() { return m_z; }

};

class Fraction
{
private:
	int m_numerator{};
	int m_denominator{};
   
public:
	Fraction() = default;

	Fraction(int numerator, int denominator);

	auto getNumerator() { return m_numerator; }
	auto getDenominator() { return m_denominator; }

	auto setNumerator(int numerator) { m_numerator = numerator; }
	auto setDenominator(int denominator) { m_denominator = denominator; }

};

class Ball
{
private:
	std::string m_color{};
	double m_radius{};

public:
	Ball() = default;
	Ball(std::string color = "Black", double radius = 10.0);

};

class RGBA
{
private:
	std::uint8_t m_red;
	std::uint8_t m_blue;
	std::uint8_t m_green;
	std::uint8_t m_alpha; 

public:
	RGBA(std::uint8_t red = 0, std::uint8_t blue = 0, std::uint8_t green = 0, std::uint8_t alpha = 255);

};

class Employee
{
private:
	int m_id;
	std::string m_name;
	int m_dob;
	int m_wage;

// DONT PUT MEMBER VARIABLES IN PUBLIC :D
public:
	Employee(int id = 0, std::string_view name = "", int wage = 13.25);

	Employee(std::string_view name);

	void print();
	void setup();

};

class IntArray
{
private:
	int* m_array{};
	int m_length{};

public:
	IntArray(int length);
		
	// This is a destructor. Has to be formatted this way (just like a constructor but with no args and a tilde in the name)
	// Instructs C++ on how to clean up the class after it is finished being used
	~IntArray();

	void setValue(int index, int value) { m_array[index] = value; }
	const int getValue(int index) { return m_array[index]; }
	const int getLength() { return m_length; }

};

class Calc
{
private:
	int m_value{ 0 };
public:
	// Returning the this pointer will actually let us chain the operations together instead of having to separately call them
	auto add(int value) { m_value += value; return *this; }
	auto sub(int value) { m_value -= value; return *this; };
	auto mult(int value) { m_value *= value; return *this; }

	const auto getValue() { return m_value; }

};

class Cents
{
private:
	int m_cents{};

public:
	Cents(int cents)
		: m_cents{ cents }
	{}

	auto getCents() const { return m_cents; }
};

class Fruit
{
public:
	// Here you can see that we nest an enum innside the class to make it easier to use
	// Note that we also put the enum in the public section of the class
	// That means that the class essentially acts as a namespace for the enum and any other program can use the enum
	// they just have to call it from the classes namespace
	enum FruitType
	{
		apple,
		banana,
		cherry
	};
private:
	FruitType m_type{};
	int m_precentageEaten{ 0 };

public:
	Fruit(FruitType type) :
		m_type{ type }
	{}

	FruitType getType() const { return m_type; }
	int getPercentageEaten() const { return m_precentageEaten; }

};

int subtract(int x, int y);
void print(const Cents& cents);

// VERY USEFUL
class Timer
{
private:
	using Clock = std::chrono::steady_clock;
	using Second = std::chrono::duration<double, std::ratio<1>>;
	
	std::chrono::time_point<Clock> m_beg{ Clock::now() };
	
public:

	void reset();
	double elapsed() const;

};

class Point2d
{
private:
	double m_x{};
	double m_y{};

public:
	Point2d(double x = 0.0, double y = 0.0);

	void print();
	friend double distanceFrom(const Point2d& point1, const Point2d& point2);
};

class HelloWorld
{
private:
	char* m_data{};

public:
	HelloWorld();
	~HelloWorld();
	void print() const
	{
		std::cout << m_data << '\n';
	}
};

class Monster
{
public:
	enum Type {
		dragon,
		goblin,
		ogre,
		orc,
		skeleton,
		troll,
		vampire,
		zombie,
		max_monster_types
	};

private:
	Type m_type;
	std::string m_name;
	std::string m_roar;
	int m_hp;

public:

	Monster(Type type, std::string_view name, std::string_view roar, int hp);
	std::string_view getTypeString(Type type);
	void print();

};


namespace MonsterGenerator {
	Monster generate();
};

#endif