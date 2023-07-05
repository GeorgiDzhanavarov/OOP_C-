#pragma once
#include "String.h"
#include "Container.h"
#include <fstream>

void Write(String fileName, Container container) {
	
	String buffer;
	std::ofstream Out(fileName.c_str(), std::ios::out);

	if (!Out.is_open()) //if file was not found/did not open
	{
		std::cout << "Error!" << std::endl;
	}

	buffer = String("< ? xml version = \"1.0\" standalone = \"no\" ? >");
	Out << buffer.c_str();
	Out << std::endl;

	buffer = String("<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\" > ");
	Out << buffer.c_str();
	Out << std::endl;

	buffer = String("<svg>");
	Out << buffer.c_str();
	Out << std::endl;

	container.WriteFile(Out);

	buffer = String("</svg>");
	Out << buffer.c_str();

	Out.close();
}