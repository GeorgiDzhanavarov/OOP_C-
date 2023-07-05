#pragma once
#include <iostream>
#include "Container.h"
#include "Circle.h"
#include "Line.h"
#include "Rectangle.h"
#pragma warning(disabled:4996)

void DisplayMenu()
{
	std::cout << '\n';
	std::cout << "1 Print\n";
	std::cout << "2 Create\n";
	std::cout << "3 Erase\n";
	std::cout << "4 Translate\n";
	std::cout << "5 Within\n";
	std::cout << "6 PointIn\n";
	std::cout << "7 Areas\n";
	std::cout << "8 Pers\n";
	std::cout << "9 Quit\n";
	std::cout << '\n';
}

void ExecuteCommand(size_t input,Container& container) {

	char temp;
	double input1, input2, input3, input4;
	String input5;
	size_t input6;

	switch (input)
	{
	case 1:
		container.print();
		break;
	case 2:
		std::cout << "a - Line\n";
		std::cout << "b - Circle\n";
		std::cout << "c - Rectangle\n";
		std::cin >> temp;

		switch (temp)
		{
		case 'a':
			std::cout << "Enter first point:\n";
			std::cout << "x1 = ";
			std::cin >> input1;
			std::cout << "y1 = ";
			std::cin >> input2;
			std::cout << "Enter second point:\n";
			std::cout << "x2 = ";
			std::cin >> input3;
			std::cout << "y2 = ";
			std::cin >> input4;
			std::cout << "Enter fill:\n";
			std::cin >> input5;
			std::cout << '\n';

			container.addItem(Line(input1, input2, input5, input3, input4));

			break;
		case 'b':
			std::cout << "Enter central point:\n";
			std::cout << "x1 = ";
			std::cin >> input1;
			std::cout << "y1 = ";
			std::cin >> input2;
			std::cout << "Enter radius:\n";
			std::cout << "radius = ";
			std::cin >> input3;
			std::cout << "Enter fill:\n";
			std::cin >> input5;
			std::cout << '\n';

			container.addItem(Circle(input1, input2, input5, input3));
			break;
		case 'c':
			std::cout << "Enter point:\n";
			std::cout << "x1 = ";
			std::cin >> input1;
			std::cout << "y1 = ";
			std::cin >> input2;
			std::cout << "Enter width and height:\n";
			std::cout << "width = ";
			std::cin >> input3;
			std::cout << "height = ";
			std::cin >> input4;
			std::cout << "Enter fill:\n";
			std::cin >> input5;
			std::cout << '\n';

			container.addItem(Rectangle(input1, input2, input5, input3, input4));
			break;
		default:
			std::cout << "Unknown character inserted\n";
			break;
		}
		break;
	case 3:
		std::cout << "Enter element index:\n";
		std::cin >> input6;
		std::cout << '\n';
		if (container.deleteItem(input6) == 0)
			std::cout << "Out of Range";
		break;
	case 4:
		std::cout << "a - Translate All Shapes\n";
		std::cout << "b - Translate Specific Shape\n";
		std::cin >> temp;
		std::cout << '\n';

		switch (temp)
		{
		case 'a':
			std::cout << "Enter vertical: ";
			std::cin >> input1;
			std::cout << "Enter horizontal: ";
			std::cin >> input2;
			std::cout << '\n';

			container.TranslateAll(input2, input1);
			break;
		case 'b':
			std::cout << "Enter vertical: ";
			std::cin >> input1;
			std::cout << "Enter horizontal: ";
			std::cin >> input2;
			std::cout << "Enter index: ";
			std::cin >> input6;
			std::cout << '\n';

			container.Translate(input6, input2, input1);
			break;
		default:
			std::cout << "Unknown character inserted\n";
			break;
		}

		break;
	case 5:
		std::cout << "Choose Area Shape\n";
		std::cout << "a - Circle\n";
		std::cout << "b - Rectangle\n";
		std::cin >> temp;

		switch (temp)
		{
		case 'a':
			std::cout << "Enter central point:\n";
			std::cout << "x1 = ";
			std::cin >> input1;
			std::cout << "y1 = ";
			std::cin >> input2;
			std::cout << "Enter radius:\n";
			std::cout << "radius = ";
			std::cin >> input3;
			std::cout << std::endl;

			container.printWithin(input1,input2,input3);
			break;
		case 'b':
			std::cout << "Enter point:\n";
			std::cout << "x1 = ";
			std::cin >> input1;
			std::cout << "y1 = ";
			std::cin >> input2;
			std::cout << "Enter width and height:\n";
			std::cout << "width = ";
			std::cin >> input3;
			std::cout << "height = ";
			std::cin >> input4;
			std::cout << std::endl;

			container.printWithin(input1, input2, input3, input4);
			break;
		default:
			std::cout << "Unknown character inserted\n";
			break;
		}
		break;
	case 6:
		std::cout << "Enter point:\n";
		std::cout << "x = ";
		std::cin >> input1;
		std::cout << "y = ";
		std::cin >> input2;
		std::cout << '\n';

		container.printPointIn(Point(input1, input2));
		break;
	case 7:
		container.Areas();
		break;
	case 8:
		container.Pers();
		break;
	case 9:
		break;
	default:
		std::cout << "Unknown character inserted\n";
		break;
	}

}