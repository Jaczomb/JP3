/**********************************************************************************************
**		Autor:				Marcin Jastrzêbski												 **
**		Kontakt:			jaczomb@gmail.com												 **
**		Data:				10.06.2017														 **
**		Nazwa:				Morse.h														 **
**___________________________________________________________________________________________**
** Klasa odpowiedzialna za stworzenie obiektu sk³adaj¹cego siê z 5 wartosci typu long,		 **
** odpowiadajacych za parametry potrzebne do obdlugi funkcji Beep() z biblioteki windows.h	 **
** dodatkowo Klasa tworzy wewnatrz siebie obiekt klasy TabMorse a takze wypelnie go w		 **
** konstruktorze wartosciami. Do dyspozycji sa nastepujace metody:							 **
** 1.	void setFrequency(long _freq)			//ustawienie czestotliwosci					 **
** 2.	void setPause(long _pause);				//ustawienie dlugosc pauzy					 **
** 3.	void setDotTime(long _dottime);			//ustawia dlugosc kropki					 **
** 4.	void setDashTime(long _dashtime);		//ustawia dlugosc kreski					 **
** 5.	void setCharPause(long _charpause);		//ustawia dlugosc przerwy miedzy znakami	 **
** 6.	void toMorse(std::string _string);	//metoda zmieniajaca string w pikajacego morsa	 **
** Klasa posiada prze³adowany operator << dla  kazdego typu zmiennych, dzieki czemu			 **
** zapis obiektklasy<<"napis"; powoduje wybbepanie slowa "napis" w alfabecie morse'a		 **
** Klasa posiada swoj konstruktor z parametrami domniemanymi, oraz destruktor:				 **
** 1.	Morse(long _frequency = 1000, long _pause = 400, long _dottime = 200,				 **
**			  long _dashtime = 200, long _charpause = 400);									 **
**			  - Obiekt mozna wywolac z domyslnymi wartosciami								 **
**			  lub nadac w konstruktorze wartosci poczatkowe									 **
** 2.	~Morse();																			 **
** Klasa posiada zdefiniowana nazwe "pause" oznaczajaca znak spacji w alfabecie morse'a		 **
**********************************************************************************************/

#pragma once

#ifndef MORSE_H
#define MORSE_H
#include <iostream>
#include <Windows.h>		//beep
#include "TabMorse.h"		//zawiera <string>
#define pause " "			//definiuje nazwe pauzy

class Morse
{
private:
	TabMorse *m_tabznakow;						//tablica znakow/kod morse'a
	const int m_size = 52;					//wielkosc tablicy znakow/kod morse'a
	long m_frequency;
	long m_pause;
	long m_dottime;
	long m_dashtime;
	long m_charpause;
	//METODY
	void fill();							//wype³nianie tablicy m_tabznakow obiektami
public:
	void setFrequency(long _freq);			//ustawia czestotliwosc
	void setPause(long _pause);				//ustawia dlugosc pauzy
	void setDotTime(long _dottime);			//ustawia dlugosc kropki
	void setDashTime(long _dashtime);		//ustawia dlugosc kreski
	void setCharPause(long _charpause);		//ustawia dlugosc przerwy miedzy znakami
	void toMorse(std::string _string);		//metoda zmieniajaca string w pikajacego morsa
	//OPERATORY
	Morse &operator =(const Morse &_a);
	Morse operator <<(std::string _string);
	Morse operator <<(long _liczba);
	Morse operator <<(double _liczba);
	Morse operator <<(int _liczba);
	Morse operator <<(char _znak);
	//KONSTRUKTORY, DESTRUKTORY
	Morse(const Morse &_wzor);				//konstruktor kopiujacy
	Morse(long _frequency = 1000,			//konstruktor
		long _pause = 400,
		long _dottime = 200,
		long _dashtime = 200,
		long _charpause = 400);
	~Morse();								//destruktor
};
#endif // !MORSE_H