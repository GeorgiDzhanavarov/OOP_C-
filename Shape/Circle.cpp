#include "Circle.h"

const double PI = 3.14159265359;

Circle::Circle() : Shape() {
	radius = 0;
	type = Type::CIRCLE;
}
Circle::Circle(double x, double y, String col, double r) : Shape(x,y,col) {
	radius = r;
	type = Type::CIRCLE;
}
void Circle::print() {
	std::cout << "Circle:\n";
	Shape::print();
	std::cout << "radius = " << radius << std::endl;
}
double Circle::Area() {
	return radius * radius * PI;
}
double Circle::Per() {
	return 2 * radius * PI;
}
Shape* Circle::clone() const {
	return new Circle(*this);
}
bool Circle::PointIn(const Point& temp) const {
	double result = temp.getDistance(GetPoint());

	if (result <= radius)
		return true;
	else
		return false;
}

double Circle::GetRadius() const {
	return radius;
}

bool Circle::Within(double x, double y, double rad) const {
	Point temp(x, y);

	double result = GetPoint().getDistance(temp) + radius;

	if (result <= rad)
		return true;
	else
		return false;
}
bool Circle::Within(double x, double y, double width, double height) const {
	Point other(GetPoint().x - radius, GetPoint().y - radius);
	Point other2(GetPoint().x + radius, GetPoint().y + radius);

	if (other2.x >= x && other2.y >= y && other2.x <= x + width && other2.y <= y + height)
		if (other.x >= x && other.y >= y && other.x <= x + width && other.y <= y + height)
			return true;

	return false;
}

void Circle::WriteInFile(std::ofstream& out) const {
	out << "<circle cx=\"" << GetPoint().x << "\" cy=\"" << GetPoint().y << "\" r=\"" << radius << "\" fill=\"" << GetColour().c_str() << "\" /> ";
}