#include "vector.h"

void Vector::copy(const Vector& temp)
{
	this->size = size;
	this->coordinates = new int[size];
	for (int i = 0; i < size; i++)
	{
		this->coordinates[i] = temp.coordinates[i];
	}
}

void Vector::free()
{
	delete[] coordinates;
}

Vector::Vector()
{
	size = 0;
	coordinates = new int[1];
}
Vector::Vector(int arg)
{
	size = arg;
	coordinates = new int[size];
}
Vector::Vector(const Vector& arg)
{
	copy(arg);
}
Vector& Vector::operator=(const Vector& arg)
{
	if (this != &arg)
	{
		free();
		copy(arg);
	}

	return *this;
}
Vector::~Vector()
{
	free();
}
int Vector::getSize() const
{
	return size;
}
Vector& Vector::operator+=(const Vector& arg)
{
	if (this->size != arg.size)
		throw "Error";
	else
	{
		for (int i = 0; i < this->size; i++)
		{
			this->coordinates[i] = this->coordinates[i] + arg.coordinates[i];
		}
	}
	return *this;
}
Vector& Vector::operator-=(const Vector& arg)
{
	if (this->size != arg.size)
		throw "Error";
	else
	{
		for (int i = 0; i < this->size; i++)
		{
			this->coordinates[i] = this->coordinates[i] - arg.coordinates[i];
		}
	}
	return *this;
}

Vector operator+(const Vector& arg1,const Vector& arg2)
{
	Vector temp(arg1);
	temp += arg2;
	return temp;
}

Vector operator-(const Vector& arg1, const Vector& arg2)
{
	Vector temp(arg1);
	temp -= arg2;
	return temp;
}

std::ostream& operator<<(std::ostream& out, const Vector& arg)
{
	for (int i = 0; i < arg.getSize(); i++)
	{
		out << arg.coordinates;
	}
	return out;
}
std::istream& operator>>(std::istream& in, Vector& arg)
{
	for (int i = 0; i < arg.size; i++)
	{
		in >> arg.coordinates[i];
	}

	return in;
}

Vector operator*(int number,const Vector& arg)
{
	Vector temp(arg);
	for (int i = 0; i < arg.getSize(); i++)
	{
		temp.coordinates[i] = number*arg.coordinates[i];
	}

	return temp;
}

bool Vector::isParallel(const Vector& arg) const
{
	double temp = double(arg.coordinates[0] / this->coordinates[0]);
	for(int i=1;i<arg.size)

}
