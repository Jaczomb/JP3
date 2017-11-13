/**********************************************************************************************
**		Autor:				Marcin Jastrzêbski												 **
**		Kontakt:			jaczomb@gmail.com												 **
**		Data:				30.06.2017														 **
**		Nazwa:				obraz.h															 **
**___________________________________________________________________________________________**
** Klasa przechowuj¹ca dane o obrazie (Wysokoœæ, szerokoœæ i tablica kolorów)				 **
**	int getW();											//pobieranie wysokosci				 **
**	int getH();											//pobieranie r						 **
**	int partition(int tablica[], int p, int r);			//do quicksorta						 **
**	void quicksort(int tablica[], int p, int r);		//quicksort							 **
**	int getElement(int _i);								//pobiera element z tablicy kolorow	 **
** Klasa posiada swoj konstruktor z parametrami domniemanymi, konstruktor kopiuj¹cy			 **
** oraz destruktor:																			 **
**********************************************************************************************/
#pragma once

#ifndef OBRAZ_H
#define OBRAZ_H

#include <string>

class obraz {
protected:
	//ZMIENNE
	int m_w;												//zmienna przechowujaca wysokosc tablicy
	int m_h;												//zmienna przechowujaca szerokosc tablicy
	int m_max_value;										//maksymalna wartosc koloru
	std::string m_version;									//zmienna przechowujaca wersje obrazu
	int *m_colortab;
public:
	//int *m_colortab;										//tablica kolorow

	//METODY
	int getW();												//pobieranie wysokosci
	int getH();												//pobieranie r
	int partition(int tablica[], int p, int r);				//do quicksorta
	void quicksort(int tablica[], int p, int r);			//quicksort
	int getElement(int _i);									//pobiera element z tablicy kolorow

	//KONSTRUKTORY DESTRUKTORY
	obraz();												//konstruktor bezparametryczny
	obraz(const obraz & o);									//konstruktor kopiuj¹cy
	~obraz();												//destruktor

	//OPERATORY
	obraz operator=(const obraz & o);						//operator =
};

#endif