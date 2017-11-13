/**********************************************************************************************
**		Autor:				Marcin Jastrzêbski												 **
**		Kontakt:			jaczomb@gmail.com												 **
**		Data:				30.06.2017														 **
**		Nazwa:				Edit.h															 **
**___________________________________________________________________________________________**
**  Biblioteka do kolorowania liter w konsoli												 **
**********************************************************************************************/
#pragma once

#ifndef COLOR_H
#define COLOR_H

#include <string>
#include <iostream>

struct ColorStruct {
	int m_color;
};

class Ccolor {
public:
	enum Color {
		Black,//0
		Blue,//1
		Green,//2
		Red = 4,
		Yellow = 14,
		White //15
	};

	Ccolor();

	friend std::ostream & blue(std::ostream& os);			//		prze³adowanie nazw dla kolorów
	friend std::ostream & green(std::ostream& os);
	friend std::ostream & red(std::ostream& os);
	friend std::ostream & reset(std::ostream& os);
	friend std::ostream & operator<<(std::ostream & os, ColorStruct color);
	// Brak destruktora ze wzgledu na brak tablic dynamicznych
	// Brak konstruktora kopiuj¹cego z powodu braku zmiennych w klasie
};

ColorStruct setColor(int _color);

#endif