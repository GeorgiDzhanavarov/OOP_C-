#pragma once
#include <iostream>

class Vector
{
private:
	int size;
	int* coordinates;
public:
	Vector();
	Vector(int);
	Vector(const Vector&);
	Vector& operator=(const Vector&);
	Vector& operator+=(const Vector&);
	Vector& operator-=(const Vector&);
	~Vector();
	friend Vector operator+(const Vector&, const Vector&);
	friend std::ostream& operator<<(std::ostream&, const Vector&);
	friend std::istream& operator>>(std::istream&, Vector&);
	friend Vector operator*(int, const Vector&);
	int getSize() const;
	bool isParallel(const Vector&) const;
private:
	void copy(const Vector&);
	void free();
};