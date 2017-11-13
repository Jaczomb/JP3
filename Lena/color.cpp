#include "color.h"

//void Color::setR(short _value)
//{
//	R = _value;
//}
//void Color::setG(short _value)
//{
//	G = _value;
//}
//void Color::setB(short _value)
//{
//	B = _value;
//}
long Color::setRGB(long _value)
{
	m_RGB = _value;
	return m_RGB;
}
//short Color::getR()
//{
//	return R;
//}
//short Color::getG()
//{
//	return G;
//}
//short Color::getB()
//{
//	return B;
//}
long Color::getRGB()
{
	return m_RGB;
}
Color::Color()
{
	//R = 0;
	//G = 0;
	//B = 0;
}

Color::~Color()
{
}