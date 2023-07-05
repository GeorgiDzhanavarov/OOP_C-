#include"Rectangle.h"
#include<iostream>

Rectangle::Rectangle() : Shape() {
	width = 0;
	height = 0;
	type = Type::RECT;
}
Rectangle::Rectangle(double x, double y, String col, double width, double height)
: Shape(x,y,col) {
	this->width = width;
	this->height = height;
	type = Type::RECT;
}
void Rectangle::print(){
	std::cout << "Rectangle:\n";
	Shape::print();
	std::cout << "width = " << width << std::endl;
	std::cout << "height = " << height << std::endl;
}
double Rectangle::Area(){
	return width * height;
}
double Rectangle::Per(){
	return 2 * width + 2 * height;
}
Shape* Rectangle::clone() const {
	return new Rectangle(*this);
}

bool Rectangle::PointIn(const Point& temp) const {
	if (temp.x >= GetPoint().x && temp.y >= GetPoint().y && GetPoint().x + width >= temp.x && GetPoint().y + height >= temp.y)
		return true;
	else
		return false;
}

bool Rectangle::Within(double x, double y, double rad) const {
	Point other(GetPoint().x + width, GetPoint().y + height);
	Point other2(GetPoint().x , GetPoint().y + height);
	Point other3(GetPoint().x + width, GetPoint().y);
	Point temp(x, y);

	double result = temp.getDistance(GetPoint());
	double result2 = temp.getDistance(other);
	double result3 = temp.getDistance(other2);
	double result4 = temp.getDistance(other3);

	if (result <= rad && result2 <= rad && result3 <= rad && result4 <= rad)
		return true;
	else
		return false;

}
bool Rectangle::Within(double x, double y, double width, double height) const {
	Point other(GetPoint().x + this->width, GetPoint().y + this->height);

	if (GetPoint().x >= x && GetPoint().y >= y && GetPoint().x <= x + width && GetPoint().y <= y + height)
		if (other.x >= x && other.y >= y && other.x <= x + width && other.y <= y + height)
			return true;

	return false;
}

void Rectangle::WriteInFile(std::ofstream& out) const {
	out << "<rect x=\"" << GetPoint().x << "\" y=\"" << GetPoint().y << "\" width=\"" << width << "\" height=\"" << height << "\" fill=\"" << GetColour().c_str() << "\" />";
}