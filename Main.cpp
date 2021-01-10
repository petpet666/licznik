#include <iostream>
#include "freqcounter.h"

int main()
{
	freqcounter <ColorRGB> fr_c;
	fr_c.addData("lena.ppm");
	fr_c.create();
	//freqcounter <char> fr_ch;
	//freqcounter <int> fr_i;
	//freqcounter <std::string> fr_s;

	return 0;
}