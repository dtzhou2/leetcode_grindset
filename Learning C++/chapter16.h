#pragma once
#ifndef CHAPTER16_H
#define CHAPTER16_H
#include <iostream>
#include <functional>
#include <string>
#include <vector>

class Point2D
{
private:
	int m_x;
	int m_y;
	
public:
	Point2d()
		: m_x{ 0 }
		, m_y{ 0 }
	{}
	Point2d(int x, int y)
		: m_x{ x }
		, m_y{ y }
	{}

	friend std::ostream& operator<<(std::ostream& out, const Point2d& point);

	void setPoint(int x, int y);

};

class Creature
{
private:
	std::string m_name;
	Point2D m_location;
	
public:
	Creature(std::string_view name, const Point2D& location)
		: m_name{ name }
		, m_location{ location }
	{}

	friend std::ostream& operator<<(std::ostream& out, const Creature& creature);


	void moveTo(int x, int y)
	{
		m_location.setPoint(x, y);
	}

};

class Teacher
{
private:
	std::string m_name{};

public:
	Teacher(std::string_view name)
		: m_name{ name }
	{
	}

	const std::string& getName() const { return m_name; }
};

class Department
{
private:
	std::vector<std::reference_wrapper<const Teacher>> m_teachers{}; 

public:
	void add(const Teacher& teacher)
	{
		m_teachers.push_back(teacher);
	}
};

int main()
{
	// Create a teacher outside the scope of the Department
	Teacher bob{ "Bob" }; // create a teacher

	{
		// Create a department and use the constructor parameter to pass
		// the teacher to it.
		Department department{ bob };

	} // department goes out of scope here and is destroyed

	// bob still exists here, but the department doesn't

	std::cout << bob.getName() << " still exists!\n";

	return 0;
}

#endif