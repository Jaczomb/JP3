/**********************************************************************************************
**		Autor:				Marcin Jastrzębski												 **
**		Kontakt:			jaczomb@gmail.com												 **
**		Data:				30.06.2017														 **
**		Nazwa:				ppm.h															 **
**___________________________________________________________________________________________**
** Klasa dziedzicząca dane po obrazie (Wysokość, szerokość i tablica kolorów)				 **
**	int getW();											//pobieranie wysokosci				 **
**	int getH();											//pobieranie r						 **
**	int partition(int tablica[], int p, int r);			//do quicksorta						 **
**	void quicksort(int tablica[], int p, int r);		//quicksort							 **
**	int getElement(int _i);								//pobiera element z tablicy kolorow	 **
** Klasa posiada swoj konstruktor z parametrami domniemanymi, konstruktor kopiujący			 **
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
	ppm(const ppm & o);									//konstruktor kopiujący
	~ppm();												//destruktor

	//OPERATORY
	ppm operator=(const ppm & o);						//operator =
};

#endif