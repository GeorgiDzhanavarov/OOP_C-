#include "Container.h"
#include "Menu.h"
#include<iostream>
#include "Write.h"
#include "Read.h"


int main() {

	size_t input = 1;
	Container store;
	String fileName;

	std::cout << "Enter file name:\n";
	std::cin >> fileName;

	Read(fileName, store);

	

	while (input != 9)
	{
		DisplayMenu();
		std::cin >> input;
		ExecuteCommand(input, store);
	}

	Write(fileName, store);

	return 0;
}