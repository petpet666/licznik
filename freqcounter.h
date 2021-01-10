//***********************************************************************************************
//
//naglowek obraz.h
//
//deklaruje klase obraz; deklaruje w tej klasie zmienn¹ width, height, maksimum, wielkosc,
//color1; deklaruje w tej klasie gettery; deklaruje w tej klasie funkcje liczaca uniklane kolory;
//deklaruje przeciazenie operatora =;
//
//Autor
//M.Godlewski Grudzieñ 2020
//
//Historia zmian:
//
//Autor         Co zmienil                       data
//M.Godlewski   wersja oryginalna                12/2020
//
//***********************************************************************************************

#ifndef _freqcounter_H_
#define _freqcounter_H_
#include "ColorRGB.h"

template <class T>
class freqcounter
{
protected:
	int width;																	//szerokosc pliku.ppm w pikselach
	int height;																	//wysokosc pliku.ppm w pikselach
	int maksimum;																//maksymalna wartosc kazdego koloru
	int wielkosc;																//ilosc pixeli w pliku .ppm

public:
	freqcounter();																//konstruktor
	virtual ~freqcounter();														//wirtualny destruktor
	freqcounter(const freqcounter& obj);										//konstruktor kopiujacy
	freqcounter& operator=(const freqcounter& obj);								//operator przeciazania dla '='

	int GetWielkosc();															//Getter dla zmiennej wielkosc
	int GetWidth();																//Getter dla zmiennej width
	int GetHeight();															//Getter dla zmiennej height
	int GetMaksimum();															//Getter dla zmiennej maksimum

};

template <>
class freqcounter <ColorRGB>
{
protected:
	int width;																	//szerokosc pliku.ppm w pikselach
	int height;																	//wysokosc pliku.ppm w pikselach
	int maksimum;																//maksymalna wartosc kazdego koloru
	int wielkosc;																//ilosc pixeli w pliku .ppm
	std::string r_kod;

public:
	ColorRGB* color1;															//deklaracja potrzebna do stworzenia tablicy dynamicznej

	freqcounter();																//konstruktor
	virtual ~freqcounter();														//wirtualny destruktor
	freqcounter(const freqcounter& obj);										//konstruktor kopiujacy
	freqcounter& operator=(const freqcounter& obj);								//operator przeciazania dla '='

	void addData(const char* name);
	void create();

	int GetWielkosc();															//Getter dla zmiennej wielkosc
	int GetWidth();																//Getter dla zmiennej width
	int GetHeight();															//Getter dla zmiennej height
	int GetMaksimum();															//Getter dla zmiennej maksimum
};

#endif // _freqcounter_H_