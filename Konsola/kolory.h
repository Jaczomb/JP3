#pragma once

#ifndef KOLORY_H
#define KOLORY_H
//----------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <Windows.h>

inline
void setColor(const unsigned short int&);

//--------------------------------------------------
std::ostream& red(std::ostream&);

std::ostream& blue(std::ostream&);

std::ostream& green(std::ostream&);

std::ostream& white(std::ostream&);
//--------------------------------------------------

struct set_color
{

    const unsigned short int& s_color;

};

inline
set_color setColor(const unsigned short int&);

std::ostream& operator <<(std::ostream&,const set_color&);

//----------------------------------------------------------------------------
#endif //	KOLORY_H
