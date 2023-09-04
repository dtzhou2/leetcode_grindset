#pragma once
#ifndef CHAPTER_14_H
#define CHAPTER_14_H
#include <iostream>
class Cents
{
private:
	int m_cents{};

public:
	Cents(int cents) : m_cents{ cents } { }
	int getCents() const { return m_cents; }
	friend Cents operator+(const Cents& C1, const Cents& c2);
	friend Cents operator+(int value, const Cents& C1);
	friend Cents operator+(const Cents& C1, int value);
	friend Cents operator-(const Cents& c1, const Cents& c2);
	// Here we are overloading an operator using a member function rather than a friend function
	Cents operator-(int value);
	// Here we overload the -value operator which is a simple unary(only has one operand) operator
	Cents operator-() const;
};

class Point
{
private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Point(double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x{ x }
		, m_y{ y }
		, m_z{ z }
	{}

	double getX() const { return m_x; }
	double getY() const { return m_y; }
	double getZ() const { return m_z; }
	friend std::istream& operator>> (std::istream& in, Point& point);
	bool operator!() const;
	Point operator+() const;
};

class Fraction
{
private:
	int m_numerator{};
	int m_denominator{};
	
public:
	Fraction(int numerator = 0, int denominator = 1)
		: m_numerator{ numerator }
		, m_denominator{ denominator }
	{
		reduce();
	}

	void reduce();

	friend Fraction operator*(const Fraction& f1, const Fraction& f2);
	friend Fraction operator*(const Fraction& f1, int value);
	friend Fraction operator*(int value, const Fraction& f1);
	friend std::ostream& operator<<(std::ostream& out, const Fraction& input);
	friend std::istream& operator>>(std::istream& in, const Fraction& input);

};

class IntList
{
private:
	int m_list[10]{};

public:
		// This can be used to both get the value and to access a value
		int& operator[]  (int index);
		// Note that since this does not return a reference it can only be used for access
		int operator[](int index) const;
};

#endif // !CHAPTER_14_H
