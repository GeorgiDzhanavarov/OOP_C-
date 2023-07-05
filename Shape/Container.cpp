#include"Container.h"
#include "Circle.h"
#include "Line.h"
#include "Rectangle.h"


Container::Container()
{
	capacity = 2;
	size = 0;

	list = new Shape * [capacity];
}
Container::Container(const Container& other)
{
	copy(other);
}
Container& Container::operator=(const Container& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}
Container::~Container()
{
	free();
}

void Container::addItem(const Shape& item)
{
	if (size >= capacity)
		resize();

	list[size++] = item.clone();
}

bool Container::deleteItem(size_t index)
{
	if (index-1 >= size)
		return false;

	delete list[index-1];
	for (int i = index-1; i < size-1; i++)
	{
		list[index-1] = list[index];
	}

	list[size - 1] = nullptr;
	size--;

	return true;
}

void Container::print() const
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << i + 1 << ".";
		list[i]->print();
		std::cout << std::endl;
	}
		
}

bool Container::Translate(size_t index, double x, double y) {
	if (index -1 >= size)
		return false;

	list[index - 1]->Translate(x, y);
	return true;
}

void Container::TranslateAll(double x, double y) {
	for (int i = 0; i < size; i++)
	{
		list[i]->Translate(x, y);
	}
}

void Container::Areas() const {
	for (int i = 0; i < size; i++) {
		std::cout << i + 1 << ". " << list[i]->Area() << std::endl;
	}
}

void Container::Pers() const {
	for (int i = 0; i < size; i++) {
		std::cout << i + 1 << ". " << list[i]->Per() << std::endl;
	}
}

void Container::printPointIn(const Point& temp) const {
	for (int i = 0; i < size; i++)
	{
		if (list[i]->PointIn(temp) == true)
		{
			std::cout << i + 1 << ".";
			list[i]->print();
			std::cout << std::endl;
		}
	}
}

void Container::copy(const Container& other)
{
	capacity = other.capacity;
	size = other.size;

	list = new Shape * [capacity];

	for (size_t i = 0; i < size; i++)
	{
		list[i] = other.list[i]->clone();
	}
}
void Container::free()
{
	for (size_t i = 0; i < size; i++)
		delete list[i];

	delete[] list;
}
void Container::resize()
{
	Shape** temp = new Shape * [capacity *= 2];

	for (size_t i = 0; i < size; i++)
	{
		temp[i] = list[i];
	}

	delete[] list;
	list = temp;
	temp = nullptr;
}

void Container::printWithin(double x,double y,double rad) const {
	for (int i = 0; i < size; i++)
	{
		if (list[i]->Within(x, y, rad) == true)
		{
			std::cout << i << ". ";
			list[i]->print();
			std::cout << std::endl;
		}
			
	}
}
void Container::printWithin(double x,double y,double width,double height) const {
	for (int i = 0; i < size; i++)
	{
		if (list[i]->Within(x, y, width, height) == true)
		{
			std::cout << i << ". ";
			list[i]->print();
			std::cout << std::endl;
		}
	}
}

size_t Container::GetSize() const {
	return size;
}

void Container::WriteFile(std::ofstream& out) const {
	for (int i = 0; i < size; i++)
	{
		list[i]->WriteInFile(out);
		out << std::endl;
	}
}

