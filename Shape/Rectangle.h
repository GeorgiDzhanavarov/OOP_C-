#pragma once
#include "Shape.h"

class Rectangle : public Shape {
private:
	double width;
	double height;
public:
	Rectangle();
	Rectangle(double, double, String, double, double);
	virtual void print() override;
	virtual double Area() override;
	virtual double Per() override;
	virtual Shape* clone() const override;
	virtual bool PointIn(const Point&) const override;
	virtual void WriteInFile(std::ofstream&) const override;

	virtual bool Within(double, double, double) const override;
	virtual bool Within(double, double, double, double) const override;
};