#pragma once
#include"Point.h"
#include "String.h"
#include<fstream>

class Shape {
private:
	Point point;
	String colour;
public:
	enum Type {
		RECT,
		CIRCLE,
		LINE
	};
protected:
	Type type;
public:
	Shape();
	Shape(double, double, String);
	virtual void print();
	virtual ~Shape() {};
	virtual double Area() = 0;
	virtual double Per() = 0;
	virtual Shape* clone() const = 0;
	virtual bool PointIn(const Point&) const = 0;
	virtual void Translate(double, double);
	virtual bool Within(double, double, double) const = 0;
	virtual bool Within(double, double, double, double) const = 0;
	const Type& GetType() const;
	const String& GetColour() const;
	virtual void WriteInFile(std::ofstream&) const = 0;

	const Point& GetPoint() const;
};