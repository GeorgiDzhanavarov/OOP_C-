#include"Point.h"

Point::Point() {
	x = 0;
	y = 0;
}

Point::Point(double x, double y) {
	this->x = x;
	this->y = y;
}
void Point::printPoint() {
	std::cout << "x = " << x << std::endl << "y = " << y << std::endl;
}

double Point::getDistance(const Point& other) const
{
	double dx = x - other.x;
	double dy = y - other.y;
	return sqrt(dx * dx + dy * dy);
}