#include "ccolor.h"
#include <iostream>
#include <windows.h>

Ccolor::Ccolor()
{
}

ColorStruct setColor(int _color) {
	ColorStruct c = {_color};
	return c;
}

std::ostream & red(std::ostream & os)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Ccolor::Red);
	return os;
}

std::ostream & blue(std::ostream & os)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Ccolor::Blue);
	return os;
}

std::ostream & green(std::ostream & os)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Ccolor::Green);
	return os;
}

std::ostream & reset(std::ostream & os)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Ccolor::White);
	return os;
}

std::ostream & operator<<(std::ostream & os, ColorStruct color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.m_color);
	return os;
}
