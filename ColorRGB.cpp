//********************************************************************************************
//
//naglowek ColorRGB.h
//
//definiuje konstruktor trójparametrowy z klasy ColorRGB; definiuje przeciazanie operatora dla
//klasy ColorRGB; Definuje Gettery;
//
//Autor
//M.Godlewski Grudzieñ 2020
//
//Historia zmian:
//
//Autor         Co zmienil                       data
//M.Godlewski   wersja oryginalna                12/2020
//
//********************************************************************************************

#include "ColorRGB.h"

//************************************************************************************
//Konstruktor
//************************************************************************************

ColorRGB::ColorRGB() :
	red(0),
	green(0),
	blue(0)
{
}

//************************************************************************************
//Destruktor
//************************************************************************************

ColorRGB::~ColorRGB()
{
}

//************************************************************************************
//Konstruktor kopiuj¹cy
//************************************************************************************

ColorRGB::ColorRGB(const ColorRGB& obj) :
	red(obj.red),
	green(obj.green),
	blue(obj.blue)
{
	/*red = obj.red;
	green = obj.green;
	blue = obj.blue;*/
}

//************************************************************************************
//przeciazenie operatora "="
//************************************************************************************


ColorRGB& ColorRGB::operator=(const ColorRGB& obj)
{
	if (this == &obj)
	{
		return *this;
	}
	red = obj.red;
	green = obj.green;
	blue = obj.blue;
	return *this;
}

ColorRGB::ColorRGB(short R, short G, short B) :
	red(R),
	green(G),
	blue(B)
{

}

//************************************************************************************
//Gettery
//************************************************************************************


short ColorRGB::GetR() const
{
	return red;
}

short ColorRGB::GetG() const
{
	return green;
}

short ColorRGB::GetB() const
{
	return blue;
}

//************************************************************************************
//przeciazenie operatora "=="
//************************************************************************************


bool ColorRGB::operator==(const ColorRGB& obj)
{
	short r1 = GetR();
	short r2 = obj.GetR();
	short g1 = GetG();
	short g2 = obj.GetG();
	short b1 = GetB();
	short b2 = obj.GetB();

	if (r1 == r2)
	{
		if (g1 == g2)
		{
			if (b1 == b2)
			{
				return true;
			}
		}
	}
	return false;
}

std::ostream& operator<<(std::ostream& out, ColorRGB const& obj)
{
	out << obj.red << obj.green << obj.blue;

	return out;
}
