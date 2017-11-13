//**********************************************************************************
//***    BIBLIOTEKI    *************************************************************
#include "TabMorse.h"
//**********************************************************************************
//***      METODY      *************************************************************
//**********************************************************************************
//ustawia wartoœæ obiektu
void TabMorse::set(char _d, char _m, std::string _morse)
{
	m_bigletter = _d;
	m_smletter = _m;
	m_morse = _morse;
}
//**********************************************************************************
//daje dostep do podgladu malej litery
char TabMorse::showbig()
{
	return m_bigletter;
}
//**********************************************************************************
//daje dostep do podgladu wielkiej litery
char TabMorse::showsmall()
{
	return m_smletter;
}
//**********************************************************************************
//daje dostep do podgladu kodu morse'a
std::string TabMorse::showmorsecode()
{
	return m_morse;
}
//**********************************************************************************
//konstruktor
TabMorse::TabMorse(char _le, char _le2, std::string _mo) 
	: m_bigletter(_le), m_smletter(_le2), m_morse(_mo)
{
}
//**********************************************************************************
//destruktor
TabMorse::~TabMorse()
{
}
//**********************************************************************************