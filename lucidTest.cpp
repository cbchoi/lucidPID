#include <iostream>
#include <fstream>
#include "lucidPropCtrl.h"

void lucid_print(std::ostream& strm, int _index, double _value)
{
	strm << _index << ", " << _value << std::endl;
}

int main(int argc, char** argv)
{
	double desired = 20;
	double actural = 0;

	std::ofstream fout("test.csv");
	lucidPropCtrl contrl = lucidPropCtrl(0.9);

	for(int i = 0; i < 20; i++)
	{
		actural += contrl.compute(desired, actural);
		//lucid_print(fout, i+1, actural);
		lucid_print(std::cout, i+1, actural);
	}

	fout.close();
	return 0;
}