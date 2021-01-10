//**************************************************************************************
//
//naglowek ColorRGB.h
//
//deklaruje klase ColorRGB; deklaruje w tej klasie zmienn¹ red, green, blue;
//deklaruje w tej klasie konstruktor trójparametrowy; Deklaruje w tej klasie Gettery
//deklaruje przeciazenie operatora = oraz operatora ==;
//
//Autor
//M.Godlewski Grudzieñ 2020
//
//Historia zmian:
//
//Autor         Co zmienil                       data
//M.Godlewski   wersja oryginalna                12/2020
//
//***************************************************************************************

#ifndef _ColorRGB_H_
#define _ColorRGB_H_

#include <iostream>

class ColorRGB
{
protected:
	short red;																	//zmienna odpowiadajca za kolor red w RGB
	short green;																//zmienna odpowiadajca za kolor green w RGB
	short blue;																	//zmienna odpowiadajca za kolor blue w RGB

public:
	ColorRGB();																	//konstruktor
	~ColorRGB();																//destruktor
	ColorRGB(const ColorRGB& obj);												//konstruktor kopiujacy
	ColorRGB& operator=(const ColorRGB& obj);									//przeciazenie operatora '=' 

	bool operator== (const ColorRGB& obj);										//przeciazenie operatora '==' 

	ColorRGB(short R, short G, short B);										//konstruktor Trojparametrowy

	friend std::ostream& operator<<(std::ostream& out, ColorRGB const& obj);

	short GetR() const;															//Getter dla zmiennej red
	short GetG() const;															//Getter dla zmiennej green
	short GetB() const;															//Getter dla zmiennej blue
};

#endif // _ColorRGB_H_