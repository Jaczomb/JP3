/**********************************************************************************************
**		Autor:				Marcin Jastrzêbski												 **
**		Kontakt:			jaczomb@gmail.com												 **
**		Data:				05.06.2017														 **
**		Nazwa:				Macierz.h	v0.1													 **
**___________________________________________________________________________________________**
**	Data			| Wersja			| Zmiany											 **
**	05.06.2017		| .v0.1				| dziala dla podanego maina							 **
**	05.06.2017		| .v0.2				| usunac testoweprinty i niepotrzebne printy (raki w programowaniu) **
**********************************************************************************************/
#pragma once

#ifndef MACIERZ_H
#define MACIERZ_H

#include <iostream>

class Macierz
{
private:
	//ZMIENNE
	double **m_tab;								// tablica z ktorej tworzona jest macierz
	long m_size;								// rozmiar naszej macierzy
public:
	//METODY
	void set(int _a, int _b, double _c);		// metoda odpowiedzialna za przypisywanie wartosci macierzy 
	void setsize(long _size = 2);				// metoda odpowiedzialna za zmiane rozmiaru macierzy
	void testprint(char litera);				// NIEISTOTNE
	//OPERATORY
	Macierz &operator =(const Macierz &_a);		// Prze³adowanie operatora =
	Macierz operator *(const Macierz &_a);			// Prze³adowanie operatora *
	bool operator ==(const Macierz &_a);			// Prze³adowanie operatora ==
	//KONSTRUKTORY, DESTRUKTORY
	Macierz(const Macierz &_wzorzec);				// Konstruktor kopiuj¹cy
	Macierz(long _size = 2);					// Konstruktor bezparametryczny /z wartoscia domyslna
	~Macierz();									// Destruktor
};

#endif // !MACIERZ_H