#include "chapter14.h"
#include <iostream>

// We can also write the overloaded operator as a non friend function, instead using getters and setters to access the 
// information in the function
// Prefer overloading through non friend as its safer
Cents operator+(const Cents& c1, const Cents& c2)
{
	return Cents{ c1.getCents() + c2.getCents() };
}

// Basic example of an overloaded operator. Note how this is not a member function but rather a friend function
// Friend allows us to access the private vars
Cents operator+(const Cents& c1, int value)
{
	return Cents{ c1.m_cents + value };
}

// We can also different permutations of the overloaded operator to catch other use cases, like using it to add with
// an int in this case
Cents operator+(int value, const Cents& c1)
{
	return Cents{ c1.m_cents + value };
}

// We can overload the subtraction operator in almost the exact same way except by using the base subtraction operator
Cents operator-(const Cents& c1, const Cents& c2)
{
	return Cents{ c1.m_cents - c2.m_cents };
}

// Here we are overloading a function using a member function rather than a friend Function
// Notice that we replace any references to seperate Cents object to implicit this pointer
Cents Cents::operator-(int value)
{
	return Cents{ m_cents - value };
}

Cents Cents::operator-() const
{
	return Cents{ -m_cents };
}

// This is how we overload the << operator in order to do standard print out statements for our class
std::ostream& operator<< (std::ostream& out, const Point& point)
{
	out << "Point(" << point.getX() << ", " << point.getY() << ", " << point.getZ() << ')';

	// Note that we have to return out here in order to allow this function to be chained with another cout
	// Anytime we want to chain our overloaded operators in this fashion we must return the left hand parameter by reference
	return out;
}

//  We can do the same thing to overload the input operator, being careful to use istream instead of ostream
std::istream& operator>> (std::istream& in, Point& point)
{
	in >> point.m_x;
	in >> point.m_y;
	in >> point.m_z;

	return in;
}

bool Point::operator!() const
{
	return (m_x == 0.0 && m_y == 0.0 && m_z == 0.0);
}

Point Point::operator+() const
{
	return *this;
}

void Fraction::reduce()
{
	int gcd{ std::_Gcd(m_numerator, m_denominator) };
	if (gcd)
	{
		m_numerator /= gcd;
		m_denominator /= gcd;
	}
}

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
	return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator);
}

Fraction operator*(const Fraction& f1, int value)
{
	return Fraction(f1.m_numerator * value, f1.m_denominator);
}

Fraction operator*(int value, const Fraction& f2)
{
	return Fraction(value * f2.m_numerator, f2.m_denominator);

}

// When using friend functions MAKE SURE to match the constructor and MAKE SURE to PASS BY REFERENCE
std::ostream& operator<< (std::ostream& out, const Fraction& input)
{
	out << input.m_numerator << "/" << input.m_denominator;
	return out;
}

std::istream& operator>> (std::istream& in, const Fraction& input)
{
	char ignore{};

	in >> input.m_numerator >> ignore >> input.m_denominator;

}

int& IntList::operator[] (int index)
{
	return m_list[index];
}

int IntList::operator[] (int index) const
{
	return m_list[index];
}

