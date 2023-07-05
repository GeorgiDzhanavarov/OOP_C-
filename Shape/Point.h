#pragma once
#include<iostream>

struct Point
{
	double x, y;
	Point();
	Point(double, double);
	void printPoint();
	double getDistance(const Point& other) const;
};