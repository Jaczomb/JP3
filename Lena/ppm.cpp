#include "ppm.h"
#include <fstream>
#include <string>

ppm::ppm(std::string _filename)
{
	if (_filename == "Error")
	{
		std::cout << "Nieprawidlowa nazwa pliku" << std::endl;
	}
	else
	{
		std::fstream ppm_file;
		ppm_file.open(_filename, std::ios::in);		//otwieram plik

		std::string bufor;
		std::string rgb;
		int liczba;
		getline(ppm_file, bufor); // Wersja

		m_version = bufor;

		ppm_file >> m_w >> m_h; // Wysokoœæ i szerokoœæ (px)
		ppm_file >> m_max_value; // Maksymalna wartoœæ koloru

		//usuwam poprzednia zawartosc
		delete[] m_colortab;
		m_colortab = NULL;

		m_colortab = new int[m_w * m_h];

		for (long long i = 0; i < m_w * m_h; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				ppm_file >> bufor;
				liczba = stoi(bufor);
				if (liczba < 10)
				{
					rgb += "00" + std::to_string(liczba);
				}
				else if (liczba < 100)
				{
					rgb += "0" + std::to_string(liczba);
				}
				else
				{
					rgb += std::to_string(liczba);
				}
			}
			m_colortab[i] = (stoi(rgb));
			rgb = "";
		}
		quicksort(m_colortab, 0, ((getW()*getH()) - 1));
		ppm_file.close();
	}
}
ppm::ppm(const ppm & o)
{
	//wywo³ywany PRZY inicjalizacji
	//wiec chyba nie musze nic kasowac wczesniej jak w operatorze =;
	m_w = o.m_w;
	m_h = o.m_h;
	m_max_value = o.m_max_value;
	m_version = o.m_version;
	m_colortab = new int[m_w*m_h];
	for (int i = 0; i < m_w*m_h; i++)
	{
		m_colortab[i] = o.m_colortab[i];
	}
}
ppm::~ppm()
{
	delete[] m_colortab;
}

ppm ppm::operator=(const ppm & o)
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