/*
Autor: Marcin Jastrzêbski
*/
#pragma once

#ifndef COLOR_H
#define COLOR_H

//struct Color {
//	short R;
//	short G;
//	short B;
//};

class Color
{
public:
	Color();
	~Color();
	//void setR(short _value);
	//void setG(short _value);
	//void setB(short _value);
	long setRGB(long _value);
	long getRGB();
	//short getR();
	//short getG();
	//short getB();
private:
	long m_RGB;
	//short R;
	//short G;
	//short B;
};
#endif