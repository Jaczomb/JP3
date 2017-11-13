#include "obraz.h"

int obraz::getW()
{
	return m_w;
}

int obraz::getH()
{
	return m_h;
}

int obraz::partition(int tablica[], int p, int r) // dzielimy tablice na dwie czesci, w pierwszej wszystkie liczby sa mniejsze badz rowne x, w drugiej wieksze lub rowne od x
{
	//zrodlo http://www.algorytm.org/algorytmy-sortowania/sortowanie-szybkie-quicksort/quick-1-c.html
	int x = tablica[p]; // obieramy x
	int i = p, j = r, w; // i, j - indeksy w tabeli
	while (true) // petla nieskonczona - wychodzimy z niej tylko przez return j
	{
		while (tablica[j] > x) // dopoki elementy sa wieksze od x
			j--;
		while (tablica[i] < x) // dopoki elementy sa mniejsze od x
			i++;
		if (i < j) // zamieniamy miejscami gdy i < j
		{
			w = tablica[i];
			tablica[i] = tablica[j];
			tablica[j] = w;
			i++;
			j--;
		}
		else // gdy i >= j zwracamy j jako punkt podzialu tablicy
			return j;
	}
}

void obraz::quicksort(int tablica[], int p, int r) // sortowanie szybkie
{
	//zrodlo http://www.algorytm.org/algorytmy-sortowania/sortowanie-szybkie-quicksort/quick-1-c.html
	int q;
	if (p < r)
	{
		q = partition(tablica, p, r); // dzielimy tablice na dwie czesci; q oznacza punkt podzialu
		quicksort(tablica, p, q); // wywolujemy rekurencyjnie quicksort dla pierwszej czesci tablicy
		quicksort(tablica, q + 1, r); // wywolujemy rekurencyjnie quicksort dla drugiej czesci tablicy
	}
}
int obraz::getElement(int _i)
{
	return m_colortab[_i];
}

obraz::obraz()
{
	m_w = 512;
	m_h = 512;
	m_max_value = 255;
	m_version = "Ala ma kota";
	m_colortab = new int[m_w*m_h];
	for (int i = 0; i < m_w*m_h; i++)
	{
		m_colortab[i] = 0;
	}
}

obraz obraz::operator=(const obraz & o)
{
	//Symfonia s.740
	//1. sprawdzam, czy to nie kopiowanie samego siebie
	if (&o == this) return *this;
	else
	{
		//2. usuwam poprzednia zawartosc
		delete[] m_colortab;
		m_colortab = NULL;
		//3. Tworze od nowa
		this->m_w = o.m_w;
		this->m_h = o.m_h;
		this->m_max_value = o.m_max_value;
		this->m_version = o.m_version;
		this->m_colortab = new int[m_w*m_h];
		for (int i = 0; i < m_w*m_h; i++)
		{
			m_colortab[i] = o.m_colortab[i];
		}
	}
	return *this;
}

obraz::obraz(const obraz & o)
{
	//wywo³ywany PRZY inicjalizacji
	//wiec chyba nie musze nic kasowac wczesniej jak w operatorze =;
	m_w = o.m_w;
	m_h = o.m_h;
	m_max_value = o.m_max_value;
	m_version = o.m_version;
	m_colortab = new int [m_w*m_h];
	for (int i = 0; i < m_w*m_h; i++)
	{
		m_colortab[i] = o.m_colortab[i];
	}
}

obraz::~obraz()
{
	delete[] m_colortab;
}
