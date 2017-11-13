
#include "Macierz.h"

// metoda odpowiedzialna za przypisywanie wartosci macierzy 
void Macierz::set(int a, int b, double c)
{
	//zabezpieczenie przed wyjœciem poza zakres tablicy
	if (a < m_size&&b < m_size)
	{
		m_tab[a][b] = c;
	}
	//w momencie gdy uzytkownik wyjdzie poza zakres, zostanie '0'
	// w miejscu przypisywania.
}

// metoda odpowiedzialna za zmiane rozmiaru macierzy
void Macierz::setsize(long _size)
{
	//1. Przepisuje macierz do pomocniczej zmiennej
	Macierz Pom(m_size);
	Pom = *this;
	Pom.testprint('P');

	//2. Kasuje i zeruje aktualna macierz.
	for (int i = 0; i < m_size; i++)
	{
		delete[] m_tab[i];
	}
	delete[] m_tab;
	m_tab = NULL;

	//3. Tworze macierz z nowym rozmiarem
	//m_size = _size;
	m_tab = new double *[_size];
	for (int i = 0; i < _size; i++)
	{
		m_tab[i] = new double[_size];
	}
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			m_tab[i][j] = 0.0;
		}
	}
	//4. Przepisuje wartosci z pomocniczej
	long _sizewew;
	//4a. znajduje mniejszy rozmiar by nie wyjsc poza tablice przy przepisywaniu
	if (m_size > _size)
		_sizewew = _size;
	else
		_sizewew = m_size;
	//przepisuje
	Pom.testprint('P');
	for (int i = 0; i < _sizewew; i++)
	{
		for (int j = 0; j < _sizewew; j++)
		{
			m_tab[i][j] = Pom.m_tab[i][j];
		}
	}
	//5. dopisuje poprawny rozmiar do obiektu
	m_size = _size;
	this->testprint('T');
}

//metoda testowego printowania
void Macierz::testprint(char litera)
{
	std::cout << "Macierz " << litera << std::endl;
	for (int i = 0; i < m_size; i++)
	{
		for (int j = 0; j < m_size; j++)
		{
			std::cout << "tabica[" << i << "][" << j << "] \t" << m_tab[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

// Prze³adowanie operatora =
Macierz & Macierz::operator=(const Macierz &_a)
{
	//Symfonia s.740
	//1. sprawdzam, czy to nie kopiowanie samego siebie
	if (&_a == this) return *this;

	else
	{
		//2. usuwam poprzednia zawartosc
		for (int i = 0; i < m_size; i++)
		{
			delete[] m_tab[i];
		}
		delete[] m_tab;
		m_tab = NULL;

		//3. Tworze od nowa
		m_size = _a.m_size;
		m_tab = new double *[m_size];
		for (int i = 0; i < m_size; i++)
		{
			m_tab[i] = new double[m_size];
		}
		for (int i = 0; i < m_size; i++)
		{
			for (int j = 0; j < m_size; j++)
			{
				m_tab[i][j] = _a.m_tab[i][j];
			}
		}
		return *this;
	}
}

// Prze³adowanie operatora *
Macierz Macierz::operator*(const Macierz &_a)
{
	//zabezpieczenie - Mnozymy tylko macierze o tym samym rozmiarze
	if (m_size == _a.m_size)
	{
		Macierz W(_a.m_size);
		for (int i = 0; i < m_size; i++)
		{
			for (int j = 0; j < m_size; j++)
			{
				for (int k = 0; k < m_size; k++)
				{
					W.m_tab[i][j] += m_tab[i][k] * _a.m_tab[k][j];
				}
			}
		}
		return W;
		W.testprint('W');
	}
	else
	{
		//jak s¹ rozne rozmiary to zwracam to co bylo
		std::cout << "Mnozenie nie jest mozliwe" << std::endl;
		std::cout << "Zwracam oryginalna wartosc"<<std::endl;
		return *this;
	}
}

// Prze³adowanie operatora ==
bool Macierz::operator ==(const Macierz &_a)
{
	//wywo³ywany PO inicjalizacji
	bool wynik = true;
	//zabezpieczam dla roznych rozmiarow
	if (m_size == _a.m_size)
	{
		for (int i = 0; i < m_size; i++)
		{
			for (int j = 0; j < m_size; j++)
			{
				if (m_tab[i][j] != _a.m_tab[i][j])
				{
					wynik = false;
					break;
				}
			}
		}
		return wynik;
	}
	else
		return false;
}

// Konstruktor kopiuj¹cy
Macierz::Macierz(const Macierz &_wzorzec)
{
	//wywo³ywany PRZY inicjalizacji
	//wiec chyba nie musze nic kasowac wczesniej jak w operatorze =;
	//Macierz A(B); Macierz A= Macierz(B); Macierz A = B;

	//wywo³anie konstruktora dla danego obiektu
	this->Macierz::Macierz(_wzorzec.m_size);
	for (int i = 0; i < m_size; i++)
	{
		for (int j = 0; j < m_size; j++)
		{
			m_tab[i][j] = _wzorzec.m_tab[i][j];
		}
	}
}

// Konstruktor bezparametryczny /z wartoscia domyslna
Macierz::Macierz(long _size)
{
	//domniemanie tworzy macierz [[2]x[2]]
	//gdy jest podany parametr to [[_size] x [_size]]
	m_size = _size;
	m_tab = new double *[_size];
	for (int i = 0; i < _size; i++)
	{
		m_tab[i] = new double[_size];
	}

	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			m_tab[i][j] = 0.0;
		}
	}
}

// Destruktor
Macierz::~Macierz()
{
	//std::cout << "DESTRUKTOR" << std::endl;
	//w destruktorze powinienem usuwac dynamiczne tablice
}