/**********************************************************************************************
**		Autor:				Marcin Jastrzêbski												 **
**		Kontakt:			jaczomb@gmail.com												 **
**		Data:				30.06.2017														 **
**		Nazwa:				Edit.h															 **
**___________________________________________________________________________________________**
** Biblioteka do wyœwietlania okienka z tekstem lub mo¿liwoœci¹ wpisania go					 **
**	void setPosition(int _x, int _y);					//ustalenie pozycji na jakich ma byc **
**														  wpisany tekst						 **
**	void setLength(int _length);						//ustawienie dozwolonej ilosci		 **
**														  znakow w edytorze					 **
**	void setText(std::string _text);					//ustawienie wyswietlanego tekstu	 **
**	void setTextColor(Edit::Color _colortxt);			//ustawienie koloru tekstu			 **
**	void setBackgroundColor(Edit::Color _colorbg);		//ustawienie koloru t³a tekstu		 **
**	void display();										//wyswietlenie ustawionych parametrow**
**	std::string getText();								//pobieranie zawartosci ze zmiennej  **
**														  m_txt								 **
**	void userText();									//pobieranie tekstu od uzytkownika	 **
** Klasa posiada swoj konstruktor z parametrami domniemanymi, konstruktor kopiuj¹cy			 **
** oraz destruktor:																			 **
**********************************************************************************************/
#pragma once

#ifndef EDIT_H
#define EDIT_H
#include <iostream>
#include <string>
#include <Windows.h>
#include <cstdlib>
#include <conio.h>

class Edit
{
private:
	//ZMIENNE								
	int m_x;											//zmienna wysokoœci pobieranej do kursora
	int m_y;											//zmienna szerokoœci pobieranej do kursora
	int m_length;										//zmienna odpowiadajaca za dozwolona ilosc znakow w edytorze
	int m_colortxt;										//zmienna odpowiadajaca za kolor tekstu
	int m_colorbg;										//zmienna odpowiadajaca za kolor tla
	std::string m_text;									//zmienna przechowujaca wyswietlany tekst
	COORD m_c;											//zmienna przechowujaca coordynaty potrzebne do ustawienia kursora
	HANDLE hOut;										//uchwyt
public:
	enum Color											//numery kolorow
	{
		Black,//0
		Blue,//1
		Green,//2
		Red = 4,
		Yellow = 14,
		White //15
	};
	//METODY
	void setPosition(int _x, int _y);					//ustalenie pozycji na jakich ma byc wpisany tekst
	void setLength(int _length);						//ustawienie dozwolonej ilosci znakow w edytorze
	void setText(std::string _text);					//ustawienie wyswietlanego tekstu
	void setTextColor(Edit::Color _colortxt);			//ustawienie koloru tekstu
	void setBackgroundColor(Edit::Color _colorbg);		//ustawienie koloru t³a tekstu
	void display();										//wyswietlenie ustawionych parametrow
	std::string getText();								//pobieranie zawartosci ze zmiennej m_txt 
	void userText();									//pobieranie tekstu od uzytkownika
	//KONSTRUKTORY, DESTRUKTORY
	Edit();												//konstruktor bezparametryczny
	Edit(const Edit & _e);								//konstruktor kopiujacy
	~Edit();											//Pusty destruktor poniewa¿ nie zainicjowa³em ¿adnych zmiennych dynamicznych
	//OPERATORY
	Edit operator=(const Edit & _e);					//operator =
};

#endif // !EDIT_H
