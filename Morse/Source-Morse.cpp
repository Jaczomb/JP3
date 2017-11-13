#include <iostream>
#include "Morse.h"
#include "TabMorse.h"

int main()
{
	Morse m;
	m.setFrequency(1000);			//czestotliwosc
	m.setPause(400);				//przerwa miedzy slowami
	m.setDotTime(100);				//czas trwania kropki
	m.setDashTime(200);				//czas trawnia kreski
	m.setCharPause(200);			//przerwa miedzy znakami
	m << "Ala ma kota";				//nie zabezpieczac przed glupota
	std::cout << std::endl;			//MOJE

	long i = 0x5A5A5A5A;
	double d = 123456789;
	std::cout << std::endl;			//MOJE							
	m << i << pause << d;

	//getchar();						//MOJE
	return 0;
}