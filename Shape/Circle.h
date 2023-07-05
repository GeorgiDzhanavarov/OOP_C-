#pragma once
#include "Shape.h"

class Circle : public Shape {
private:
	double radius;
public:
	Circle();
	Circle(double, double, String, double);
	virtual void print() override;
	virtual double Area() override;
	virtual double Per() override;
	virtual Shape* clone() const override;
	virtual bool PointIn(const Point&) const override;
	double GetRadius() const;
	virtual void WriteInFile(std::ofstream&) const override;

	virtual bool Within(double, double, double) const override;
	virtual bool Within(double, double, double, double) const override;
};