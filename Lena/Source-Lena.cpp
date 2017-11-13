#include "ppm.h"
#include <iostream>

int liczkolory(obraz & o);

int main()
{
	obraz *ob = new ppm("lena.ppm");

	int kolor;
	kolor = liczkolory(*ob);

	std::cout << "Unikalne kolory: " << kolor<<std::endl;

	system("pause");

	delete ob;

	return 0;
}
int liczkolory(obraz & o)
{
	//sprawdzam posortowana tablice
	int licznik = 0;
	int pomoc;
	for (int i = 0; i < o.getW()*o.getH(); i++)
	{
		if (i == 0)
		{
			licznik++;								//pierwszy kolor tez jest unikalny
			pomoc = o.getElement(i);
		}
		else if (pomoc != o.getElement(i))
		{
			licznik++;
			pomoc = o.getElement(i);
		}
	}
	return licznik;
}