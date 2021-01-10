//********************************************************************************************
//
//naglowek obraz.h
//
//definiuje funkcje zmieniajace zmienne z klasy obraz; definiuje przeciazanie operatora dla
//klasy obraz; definiuje gettery dla klasy obraz;
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

#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "freqcounter.h"

//************************************************************************************
//Konstruktor
//************************************************************************************

template <class T>
freqcounter<T>::freqcounter() :
	width(0),
	height(0),
	maksimum(0),
	wielkosc(width* height)
{

}

freqcounter<ColorRGB>::freqcounter() :
	width(0),
	height(0),
	maksimum(0),
	wielkosc(width* height),
	r_kod("")
{
	color1 = new ColorRGB[wielkosc];
}

//************************************************************************************
//Destruktor
//************************************************************************************

template <class T>
freqcounter<T>::~freqcounter()
{

}

freqcounter<ColorRGB>::~freqcounter()
{
	delete[] color1;
}

//************************************************************************************
//Konstruktor kopiuj¹cy
//************************************************************************************

template <class T>
freqcounter<T>::freqcounter(const freqcounter& obj) :
	width(obj.width),
	height(obj.height),
	maksimum(obj.maksimum),
	wielkosc(obj.wielkosc)
{

}

freqcounter<ColorRGB>::freqcounter(const freqcounter& obj) :
	width(obj.width),
	height(obj.height),
	maksimum(obj.maksimum),
	wielkosc(obj.wielkosc),
	r_kod(obj.r_kod),
	color1(obj.color1)
{

}

//************************************************************************************
//przeciazenie operatora "="
//************************************************************************************

template <class T>
freqcounter<T>& freqcounter<T>::operator=(const freqcounter& obj)
{
	if (this == &obj)
	{
		return *this;
	}
	return *this;
}

void freqcounter<ColorRGB>::addData(const char* name)
{
	int k = 1;											//na poczatku sprawdza mi, kiedy zaczynaja sie same liczby RGB, a potem robi za zmienna pomocnicza
	int l = 0;											//zmienna pomocnicza do czytania rodzaju kodowania i wielkosci tabeli
	long ij = 0;										//jest to miejsce w tablicy
	short h = 5;										//zmienna pomocnicza do sprawdzania komentarzy w pliku
	short r = 0;
	short g = 0;
	short b = 0;

	std::string rgb;
	std::string number;

	std::fstream plik;

	std::stringstream strumien1;

	plik.open(name, std::ios::in);

	if (plik.good() == true)
	{

		while (k == 1)
		{
			std::getline(plik, rgb);
			std::stringstream strumien(rgb);

			while (k == 1)
			{
				if (rgb[0] == '#')								//sprawdzanie czy nie ma komentarza i jego pomijanie
				{
					break;
				}
				if (l == 0)
				{
					r_kod = rgb;								//zapisywanie rodzaju kodowania do zmiennej z pliku
					l++;
					break;
				}
				if (l == 1)
				{
					strumien >> width;							//zapisywanie szerokosci obrazu do zmiennej z pliku
					strumien >> height;							//zapisywanie wysokosci obrazu do zmiennej z pliku
					l++;
					break;
				}
				if (l == 2)
				{
					strumien >> maksimum;						//zapisywanie maksymalna wartosc kazdego koloru obrazu do zmiennej z pliku
					k = 0;
					break;
				}
			}
		}
		wielkosc = width * height;

		ColorRGB* color2;
		color2 = new ColorRGB[wielkosc];								//tworzenie tablicy pomocniczej

		for (int i = 0; i < wielkosc; i = i)
		{
			std::getline(plik, rgb);
			std::stringstream strumien(rgb);

			for (size_t j = 0; j < rgb.length(); j++)
			{
				if (rgb[j] == '#')										//sprawdzanie czy nie ma komentarza i jego pomijanie
				{
					i = i - h;
					break;
				}

				strumien >> r;											//zapisywanie koloru red RGB do zmiennej z pliku
				strumien1 << r;
				number = strumien1.str();
				j++;

				strumien >> g;											//zapisywanie koloru green RGB do zmiennej z pliku
				strumien1 << g;
				number = strumien1.str();
				j++;

				strumien >> b;											//zapisywanie koloru blue RGB do zmiennej z pliku
				strumien1 << b;
				number = strumien1.str();
				j++;

				j = j + number.length() - k;
				k = number.length();

				color2[ij] = ColorRGB(r, g, b);							//zapisywanie koloru RGB do zmiennej w tablicy

				ij++;
				h--;
				i++;
			}
			h = 5;
		}

		color1 = color2;												//przekopiowywanie z tablicy pomocniczej do glownej

		plik.close();
	}

}

void freqcounter<ColorRGB>::create()
{
	std::vector<ColorRGB> kolory;
	std::vector<ColorRGB> sKolory;
	std::vector<int> ilosc;
	int pow = 0;
	int value = 0;
	
	for (int i = 0; i < wielkosc; i++)
	{
		kolory.push_back(color1[i]);
	}

	for (unsigned int i = 0; i < kolory.size(); i++)
	{
		ColorRGB kolor = kolory[0];

		for (unsigned int j = 0; j < kolory.size(); j++)
		{
			if (kolory[j] == kolor)
			{
				if (value == 0)
				{
					sKolory.push_back(kolory[0]);
					value = 1;
				}
				pow++;
				kolory.erase(kolory.begin()+j);
				j--;
			}
		}

		ilosc.push_back(pow);
		pow = 0;
		value = 0;
	}

	std::ofstream plik1("kolory.txt", std::ios::out);

	if (plik1.good())
	{
		for (const auto& e : sKolory)
		{
			plik1 << e << '\t';
		}
	}

	plik1.close();

	std::ofstream plik2("ilosc.txt", std::ios::out);

	if (plik2.good())
	{
		for (const auto& e : ilosc)
		{
			plik2 << e << '\t';
		}
	}

	plik2.close();
}

//************************************************************************************
//Gettery
//************************************************************************************

template <class T>
int freqcounter<T>::GetWielkosc()
{
	return wielkosc;
}

template <class T>
int freqcounter<T>::GetWidth()
{
	return width;
}

template <class T>
int freqcounter<T>::GetHeight()
{
	return height;
}

template <class T>
int freqcounter<T>::GetMaksimum()
{
	return maksimum;
}
