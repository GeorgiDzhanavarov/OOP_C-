#pragma once
#include"Shape.h"
#include "Circle.h"
#include "Rectangle.h"

class Container
{
private:
	Shape** list;
	size_t capacity, size;
public:
	Container();
	Container(const Container&);
	Container& operator=(const Container&);
	~Container();

	void addItem(const Shape&);
	bool deleteItem(size_t);
	bool Translate(size_t, double, double);
	void TranslateAll(double, double);
	void Areas() const;
	void Pers() const;
	void printPointIn(const Point&) const;
	void printWithin(double,double,double) const;
	void printWithin(double, double, double, double) const;
	size_t GetSize() const;
	void WriteFile(std::ofstream&) const;

	void print() const;
private:
	void copy(const Container&);
	void free();
	void resize();
};