#include"Line.h"
#include<cmath>

Line::Line() :Shape(), secondPoint() {
	type = Type::LINE;
}
Line::Line(double x, double y, String col, double x2, double y2) : Shape(x,y,col), secondPoint(x2,y2) {

	type = Type::LINE;
}

const Point& Line::GetSecondPoint() const {
	return secondPoint;
}

void Line::print() {
	std::cout << "Line:\n";
	Shape::print();
	std::cout << "x2 = " << secondPoint.x << std::endl;
	std::cout << "y2 = " << secondPoint.y << std::endl;
}
double Line::Area() {
	return 0;
}
double Line::Per() {
	return secondPoint.getDistance(GetPoint());
}
 Shape* Line::clone() const {
	 return new Line(*this);
}
 bool Line::PointIn(const Point& temp) const {
	 double result = GetPoint().x * (temp.y - secondPoint.y) + secondPoint.x * (GetPoint().y - temp.y) + temp.x * (secondPoint.y - GetPoint().y);
	 if (result <= pow(10, -6) && result >= 0)
		return true;
	 else
		return false;
 }

 bool Line::Within(double x,double y,double rad) const {
	 Point temp(x, y);
	 double result = temp.getDistance(GetPoint());
	 double result2 = temp.getDistance(secondPoint);

	 if (result <= rad && result2 <= rad)
		 return true;
	 else
		 return false;
 }
 bool Line::Within(double x,double y,double width, double height) const {
	 
	 if (GetPoint().x >= x && GetPoint().y >= y && GetPoint().x <= x + width && GetPoint().y <= y + height)
		 if (secondPoint.x >= x && secondPoint.y >= y && secondPoint.x <= x + width && secondPoint.y <= y + height)
			 return true;

	 return false;
 }

void Line::Translate(double x, double y) {
	Shape::Translate(x, y);
	secondPoint.x += x;
	secondPoint.y += y;
 }

void Line::WriteInFile(std::ofstream& out) const {
	out << "<line x1=\"" << GetPoint().x << "\" y1=\"" << GetPoint().y << "\" x2=\"" << secondPoint.x << "\" y2=\"" << secondPoint.y << "\" stroke=\"" << GetColour().c_str() << "\" /> ";
}