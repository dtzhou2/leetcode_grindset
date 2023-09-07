#include "chapter16.h"

std::ostream& operator<<(std::ostream& out, const Point2D& point)
{
	out << '(' << point.m_x << "," << point.m_y << ')';
	return out;
}

void Point2D::setPoint(int x, int y)
{
	m_x = x;
	m_y = y;
}

std::ostream& operator<<(std::ostream& out, const Creature& creature)
{
	out << creature.m_name << " is at " << creature.m_location;
	return out;
}