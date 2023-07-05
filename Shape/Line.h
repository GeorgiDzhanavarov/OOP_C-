#pragma once
#include "Shape.h"

class Line : public Shape {
private:
	Point secondPoint;
public:
	Line();
	Line(double, double, String, double, double);
	virtual void print() override;
	virtual double Area() override;
	virtual double Per() override;
	const Point& GetSecondPoint() const;
	virtual Shape* clone() const override;
	virtual bool PointIn(const Point&) const override;
	virtual void Translate(double, double) override;
	virtual void WriteInFile(std::ofstream&) const override;

	virtual bool Within(double, double, double) const override;
	virtual bool Within(double, double, double, double) const override;
};