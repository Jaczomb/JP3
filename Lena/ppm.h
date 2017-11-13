/**********************************************************************************************
**		Autor:				Marcin Jastrzêbski												 **
**		Kontakt:			jaczomb@gmail.com												 **
**		Data:				30.06.2017														 **
**		Nazwa:				ppm.h															 **
**___________________________________________________________________________________________**
** Klasa dziedzicz¹ca dane po obrazie (Wysokoœæ, szerokoœæ i tablica kolorów)				 **
**	int getW();											//pobieranie wysokosci				 **
**	int getH();											//pobieranie r						 **
**	int partition(int tablica[], int p, int r);			//do quicksorta						 **
**	void quicksort(int tablica[], int p, int r);		//quicksort							 **
**	int getElement(int _i);								//pobiera element z tablicy kolorow	 **
** Klasa posiada swoj konstruktor z parametrami domniemanymi, konstruktor kopiuj¹cy			 **
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
	ppm(const ppm & o);									//konstruktor kopiuj¹cy
	~ppm();												//destruktor

	//OPERATORY
	ppm operator=(const ppm & o);						//operator =
};

#endif