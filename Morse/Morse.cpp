#include "Morse.h"

// wype³nianie tablicy m_tabznakow obiektami
void Morse::fill()
{
	// zrodlo https://pl.wikipedia.org/wiki/Kod_Morse%E2%80%99a
	// autor: Marcin Jastrzebski
	m_tabznakow = new TabMorse[m_size];
	m_tabznakow[0].set('A', 'a', ".-");
	m_tabznakow[1].set('B', 'b', ".-...");
	m_tabznakow[2].set('C', 'c', "-.-.");
	m_tabznakow[3].set('D', 'd', "-..");
	m_tabznakow[4].set('E', 'e', ".");
	m_tabznakow[5].set('F', 'f', "..-.");
	m_tabznakow[6].set('G', 'g', "--.");
	m_tabznakow[7].set('H', 'h', "....");
	m_tabznakow[8].set('I', 'i', "..");
	m_tabznakow[9].set('J', 'j', ".---");
	m_tabznakow[10].set('K', 'k', "-.-");
	m_tabznakow[11].set('L', 'l', ".-..");
	m_tabznakow[12].set('M', 'm', "--");
	m_tabznakow[13].set('N', 'n', "-.");
	m_tabznakow[14].set('O', 'o', "---");
	m_tabznakow[15].set('P', 'p', ".--.");
	m_tabznakow[16].set('Q', 'q', "--.-");
	m_tabznakow[17].set('R', 'r', ".-.");
	m_tabznakow[18].set('S', 's', "...");
	m_tabznakow[19].set('T', 't', "-");
	m_tabznakow[20].set('U', 'u', "..-");
	m_tabznakow[21].set('V', 'v', "...-");
	m_tabznakow[22].set('W', 'w', ".--");
	m_tabznakow[23].set('X', 'x', "-..-");
	m_tabznakow[24].set('Y', 'y', "-.--");
	m_tabznakow[25].set('Z', 'z', "--..");
	m_tabznakow[26].set('1', '1', ".----");
	m_tabznakow[27].set('2', '2', "..---");
	m_tabznakow[28].set('3', '3', "...--");
	m_tabznakow[29].set('4', '4', "....-");
	m_tabznakow[30].set('5', '5', ".....");
	m_tabznakow[31].set('6', '6', "-....");
	m_tabznakow[32].set('7', '7', "--...");
	m_tabznakow[33].set('8', '8', "---..");
	m_tabznakow[34].set('9', '9', "----.");
	m_tabznakow[35].set('0', '0', "-----");
	m_tabznakow[36].set('.', '.', ".-.-.-");
	m_tabznakow[37].set(',', ',', "--..--");
	m_tabznakow[38].set('"', '"', ".----.");
	m_tabznakow[39].set('_', '_', "..--.-");
	m_tabznakow[40].set(':', ':', "---...");
	m_tabznakow[41].set(';', ';', "-.-.-.");
	m_tabznakow[42].set('?', '?', "..--..");
	m_tabznakow[43].set('!', '!', "-.-.--");
	m_tabznakow[44].set('-', '-', "-....-");
	m_tabznakow[45].set('+', '+', ".-.-.");
	m_tabznakow[46].set('/', '/', "-..-.");
	m_tabznakow[47].set('(', '(', "-.--.");
	m_tabznakow[48].set(')', ')', "-.--.-");
	m_tabznakow[49].set('=', '=', "-...-");
	m_tabznakow[50].set('@', '@', ".--.-.");
	m_tabznakow[51].set(' ', ' ', "^");
}

//ustawia czestotliwosc
void Morse::setFrequency(long _freq)
{
	m_frequency = _freq;
}

//ustawia dlugosc pauzy
void Morse::setPause(long _pause)
{
	m_pause = _pause;
}

//ustawia dlugosc kropki
void Morse::setDotTime(long _dottime)
{
	m_dottime = _dottime;
}

//ustawia dlugosc kreski
void Morse::setDashTime(long _dashtime)
{
	m_dashtime = _dashtime;
}

//ustawia dlugosc przerwy miedzy znakami
void Morse::setCharPause(long _charpause)
{
	m_charpause = _charpause;
}

//metoda zmieniajaca string w pikajacego morsa
void Morse::toMorse(std::string _string)
{
	//int dlugosc_stringu = static_cast<int>(_string.length());
	for (int i = 0; i < static_cast<int>(_string.length()); i++)	//dlugosc stringu
	{
		for (int j = 0; j < m_size; j++)		//dlugosc tablicy znak/kod morse'a
		{
			if (_string[i] == m_tabznakow[j].showbig() || _string[i] == m_tabznakow[j].showsmall())
			{
				std::cout << _string[i];	//tekst wyswietlania
				for (int k = 0; k < static_cast<int>(m_tabznakow[j].showmorsecode().length()); k++)
				{
					if (m_tabznakow[j].showmorsecode()[k] == '-')
					{
						Beep(DWORD(m_frequency), DWORD(m_dashtime));
						Sleep(m_charpause);
					}
					else if (m_tabznakow[j].showmorsecode()[k] == '.')
					{
						Beep(DWORD(m_frequency), DWORD(m_dottime));
						Sleep(m_charpause);
					}
					else if (m_tabznakow[j].showmorsecode()[k] == '^')
					{
						Sleep(m_pause);				//dla spacji
					}
				}
				break;
			}
		}
	}
}

//operator =
Morse &Morse::operator =(const Morse &_a)
{
	//Symfonia s.740
	//1. sprawdzam, czy to nie kopiowanie samego siebie
	if (&_a == this) return *this;

	else
	{
		//2. usuwam poprzednia zawartosc
		delete[] m_tabznakow;
		m_tabznakow = NULL;

		//3. Tworze od nowa
		m_tabznakow = new TabMorse[m_size];
		for (int i = 0; i < m_size; i++)
		{
			m_tabznakow[i] = _a.m_tabznakow[i];
		}
		m_frequency = _a.m_frequency;
		m_pause = _a.m_pause;
		m_dottime = _a.m_dottime;
		m_dashtime = _a.m_dashtime;
		m_charpause = _a.m_charpause;
		return *this;
	}
}

//przeladowanie dla stringa
Morse Morse::operator <<(std::string _string)
{
	toMorse(_string);
	return *this;
}

//przeladowanie dla longa
Morse Morse::operator <<(long _liczba)
{
	std::string _string;
	_string = std::to_string(_liczba);
	toMorse(_string);
	return *this;
}

//przeladowanie dla longa
Morse Morse::operator <<(double _liczba)
{
	std::string _string;
	_string = std::to_string(_liczba);
	toMorse(_string);
	return *this;
}

//przeladowanie dla inta
Morse Morse::operator <<(int _liczba)
{
	std::string _string;
	_string = std::to_string(_liczba);
	toMorse(_string);
	return *this;
}

//przeladowanie dla chara
Morse Morse::operator <<(char _znak)
{
	std::string _string;
	_string = std::to_string(_znak);
	toMorse(_string);
	return *this;
}

//konstruktor kopiujacy
Morse::Morse(const Morse &_wzor)
{
	fill();					//wypelnianie m_tabznakow;
	m_frequency = _wzor.m_frequency;
	m_pause = _wzor.m_pause;
	m_dottime = _wzor.m_dottime;
	m_dashtime = _wzor.m_dashtime;
	m_charpause = _wzor.m_charpause;
}

//konstruktor
Morse::Morse(long _frequency, long _pause, long _dottime, long _dashtime, long _charpause)
	: m_frequency(_frequency), m_pause(_pause), m_dottime(_dottime), m_dashtime(_dashtime), m_charpause(_charpause)
{
	//Tworze tablice znakow 
	//mala litera / duza litera / kod morse
	fill();
}

//destruktor
Morse::~Morse()
{
	delete[] m_tabznakow;
}
