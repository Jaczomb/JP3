/**********************************************************************************************
**		Autor:				Marcin Jastrzêbski												 **
**		Kontakt:			jaczomb@gmail.com												 **
**		Data:				10.06.2017														 **
**		Nazwa:				TabMorse.h														 **
**___________________________________________________________________________________________**
** Klasa odpowiedzialna za stworzenie obiektu sk³adaj¹cego siê z 2 wartosci typu char, oraz  **
** jednej wartosci typu string. Klasa wyposazona nastepujace metody:						 **
** 1.	void set(char _d, char _m, std::string _morse)										 **
**		- metoda odpowiedzialna za ustawienie wartoœæ obiektu,								 **
** 2.	char showsmall()																	 **
**		- daje dostep do podgladu malej litery												 **
** 3.	char showbig()																		 **
**		- daje dostep do podgladu wielkiej litery											 **
** 4.	std::string showmorsecode()															 **
**		- daje dostep do podgladu kodu morse'a												 **
** Klasa posiada swoj konstruktor z parametrami domniemanymi, oraz destruktor:				 **
** 1.	TabMorse(char _le = 'NULL', char _le2 = 'NULL', std::string _mo = "NULL")			 **
**		- Obiekt mozna wywolac z domyslnymi wartosciami ustawionymi na NULL lub nadac		 **
**		  w konstruktorze wartosci poczatkowe												 **
** 2.	~TabMorse()																			 **
**********************************************************************************************/
#pragma once

#ifndef TABMORSE_H
#define TABMORSE_H
#include <string>

class TabMorse
{
private:
	//ZMIENNE
	char m_bigletter;										//duza litera
	char m_smletter;										//mala litera
	std::string m_morse;									//kod morsa dla danej litery
public:
	//METODY
	void set(char _d, char _m, std::string _morse);			//ustawia wartoœæ obiektu
	char showsmall();										//daje dostep do podgladu malej litery
	char showbig();											//daje dostep do podgladu wielkiej litery
	std::string showmorsecode();							//daje dostep do podgladu kodu morse'a
	//KONSTRUKTOR/ DESTRUKTOR
	//konstruktor kopiujacy niepotrzebny
	TabMorse(char _le = NULL, char _le2 = NULL, std::string _mo = "NULL");
	~TabMorse();
};
#endif // !TABMORSE_H