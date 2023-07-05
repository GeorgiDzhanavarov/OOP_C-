#pragma once
#include "String.h"
#include "Container.h"
#include <fstream>
#include "Vector.hpp"
#include <cstring>
#include "Shape.h"

bool strContain(const char* str, const char* arg)
{
	int size = strlen(arg);
	int sizeStr = strlen(str);
	bool flag = 1;

	for (int i = 0; i < sizeStr; i++)
	{
		flag = 1;
		if (str[i] == arg[0])
		{
			for (int j = 1; j < size; j++)
			{
				if (str[i + j] != arg[j])
					flag = 0;
			}

			if (flag == 1)
				return true;
		}
	}

	return false;
}

Vector<String> GetBetween(const char* str) {
	Vector<String> result;
	char buffer[50];

	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '"')
		{
			int j = i + 1;
			int k = 0;

			while (str[j] != '"')
			{
				buffer[k] = str[j];
				j++;
				k++;
			}
			buffer[k] = '\0';
			i = j;
			result.pushBack(String(buffer));
		}
	}

	return result;
}

double StrToDouble(const char* str)
{
	long int whole = 0;
	long int decimal = 0;
	int i = 0;
	int countDecimal = 0;

		while (str[i] != '.' && str[i] != ',' && i < strlen(str))
		{
			whole = whole * 10 + int(str[i] - '0');
			i++;
		}
		i++;

		while (i < strlen(str))
		{
			decimal = decimal * 10 + double(str[i] - '0');
			i++;
			countDecimal++;
		}
		
		return double(whole) + double(decimal) / double(pow(10, countDecimal));
	
	
}

void Read(String fileName, Container& container) {

	std::ifstream In(fileName.c_str(), std::ios::in);

	char buffer[1024];
	Vector<String> list;

	while (!In.eof()) {
		do {
			In.getline(buffer, 1023);
		} while (strcmp(buffer,"<svg>"));

		do {
			In.getline(buffer, 1023);
			list.pushBack(String(buffer));
		} while (strcmp(buffer, "</svg>"));
	}

	In.close();

	list.popBack();
	Vector<String> temp;
	double input1, input2, input3, input4;
	String colour;

	for (int i = 0; i < list.getSize(); i++)
	{
		Vector<String> temp = GetBetween(list[i].c_str());

		if (strContain(list[i].c_str(), "rect") == true)
		{
			input1 = StrToDouble(temp[0].c_str());
			input2 = StrToDouble(temp[1].c_str());
			input3 = StrToDouble(temp[2].c_str());
			input4 = StrToDouble(temp[3].c_str());
			colour = temp[4];

			container.addItem(Rectangle(input1, input2, colour, input3, input4));
		}

		if (strContain(list[i].c_str(), "line") == true && strContain(list[i].c_str(), "polyline") == false)
		{
			input1 = StrToDouble(temp[0].c_str());
			input2 = StrToDouble(temp[1].c_str());
			input3 = StrToDouble(temp[2].c_str());
			input4 = StrToDouble(temp[3].c_str());
			colour = temp[4];

			container.addItem(Line(input1, input2, colour, input3, input4));
		}

		if (strContain(list[i].c_str(), "circle") == true)
		{
			input1 = StrToDouble(temp[0].c_str());
			input2 = StrToDouble(temp[1].c_str());
			input3 = StrToDouble(temp[2].c_str());
			colour = temp[3];

			container.addItem(Circle(input1, input2, colour, input3));
		}
	}

	
}

