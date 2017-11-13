/**********************************************************************************************
**		Autor:				Marcin Jastrz�bski												 **
**		Kontakt:			jaczomb@gmail.com												 **
**		Data:				30.06.2017														 **
**		Nazwa:				ppm.h															 **
**___________________________________________________________________________________________**
** Klasa dziedzicz�ca dane po obrazie (Wysoko��, szeroko�� i tablica kolor�w)				 **
**	int getW();											//pobieranie wysokosci				 **
**	int getH();											//pobieranie r						 **
**	int partition(int tablica[], int p, int r);			//do quicksorta						 **
**	void quicksort(int tablica[], int p, int r);		//quicksort							 **
**	int getElement(int _i);								//pobiera element z tablicy kolorow	 **
** Klasa posiada swoj konstruktor z parametrami domniemanymi, konstruktor kopiuj�cy			 **
** oraz destruktor:																			 **
**********************************************************************************************/


#pragma once

#ifndef PPM_H
#define PPM_H

#include "obraz.h"
#include <iostream>
#include <set>

class ppm : public obraz {
public:
	//KONSTRUKTORY DESTRUKTORY
	ppm(std::string _filename="Error");					//kostruktor bezparametryczny
	ppm(const ppm & o);									//konstruktor kopiuj�cy
	~ppm();												//destruktor

	//OPERATORY
	ppm operator=(const ppm & o);						//operator =
};

#endif