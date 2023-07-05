#include "Shape.h"
#include<iostream>

Shape::Shape() {

}
Shape::Shape(double x, double y, String col)
	: point(x, y), colour(col)
{

}
 void Shape::print() {
	 point.printPoint();
	std::cout << "colour: " << colour.c_str() << std::endl;
}
void Shape::Translate(double x, double y) {
	point.x += x;
	point.y += y;
}

const Point& Shape::GetPoint() const {
	return point;
}

const Shape::Type& Shape::GetType() const {
	return type;
}

const String& Shape::GetColour() const {
	return colour;
}