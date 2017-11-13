#include "Edit.h"

void Edit::setPosition(int _x, int _y)
{
	m_x = _x;
	m_y = _y;
}

void Edit::setLength(int _length)
{
	m_length = _length;
	for (int i = 0; i < m_length; i++)
		m_text += " ";
}

void Edit::setText(std::string _text)
{
	for (int i = 0; i < _text.size(); i++)
		m_text[i] = _text[i];
}

void Edit::setTextColor(Edit::Color _colortxt)
{
	m_colortxt = _colortxt;
}

void Edit::setBackgroundColor(Edit::Color _colorbg)
{
	m_colorbg = _colorbg;
}

void Edit::display()
{
	//wskazuje miejsce zaczecia wyswietlania textu
	m_c.X = m_x-1;
	m_c.Y = m_y-1;
	SetConsoleTextAttribute(hOut, (m_colortxt | m_colorbg * 16));
	SetConsoleCursorPosition(hOut, m_c);
	std::cout << m_text;
	//CloseHandle(hOut);
}

std::string Edit::getText()
{
	return m_text;
}
void Edit::userText()
{
	char character = 0;
	SetConsoleTextAttribute(hOut, (White | Black * 16));
	m_c.X = m_x - 1;
	m_c.Y = m_y - 1;
	
	while ((int)character != 13) // dopóki nie klikniemy enter
	{
		system("cls");
		SetConsoleCursorPosition(hOut, m_c);
		SetConsoleTextAttribute(hOut, (m_colortxt | m_colorbg * 16));
		std::cout << m_text;
		SetConsoleTextAttribute(hOut, (White | Black * 16));
		character = _getch();
		if ((int)character == 8) // BACKSPACE
			m_text = m_text.substr(0, m_text.length() - 1);
		else if (m_text.length() < m_length) // gdy liczba znaków nie przekracza maksymalnej zadeklarowanej
			m_text = m_text + character;
	} 
	std::cout << std::endl;
}
Edit::Edit()
{
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	m_length = 20;
	m_x = 10;
	m_y = 15;
	setLength(8);
	m_text = "";
	m_colortxt = Black;
	m_colorbg = Yellow;
}
Edit::Edit(const Edit & _e)
{
	CloseHandle(hOut);
	hOut = _e.hOut;
	m_x = _e.m_x;
	m_y = _e.m_y;
	m_length = _e.m_length;
	setLength(m_length);
	m_text = _e.m_text;
	m_colortxt = _e.m_colortxt;
	m_colorbg = _e.m_colorbg;
}

Edit::~Edit()
{
	CloseHandle(hOut);
}
Edit Edit::operator=(const Edit & _e)
{
	//Symfonia s.740
	//1. sprawdzam, czy to nie kopiowanie samego siebie
	if (&_e == this) return *this;
	else
	{
		//3. Tworze od nowa
		CloseHandle(hOut);
		hOut = _e.hOut;
		m_x = _e.m_x;
		m_y = _e.m_y;
		m_length = _e.m_length;
		setLength(m_length);
		m_text = _e.m_text;
		m_colortxt = _e.m_colortxt;
		m_colorbg = _e.m_colorbg;
	}
	return *this;
}