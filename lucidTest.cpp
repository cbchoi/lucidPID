#include <iostream>
#include <fstream>
#include "lucidPropCtrl.h"
#include "lucidPICtrl.h"
#include "lucidPDCtrl.h"

void lucid_print(std::ostream& strm, int _index, double _value)
{
	strm << _value << std::endl;
}

int main(int argc, char** argv)
{
	double _Kp = 3;
	double _Ki = 0.1;
	double _Kd = 0.8;
	int    _Loop = 1000;

	{
		double desired = 20;
		double actural = 0;
		std::ofstream fout("test_P.dat");
		lucidPropCtrl contrl = lucidPropCtrl(_Kp);

		for(int i = 0; i < _Loop; i++)
		{
			actural += contrl.compute(desired, actural);
			//lucid_print(fout, i+1, actural);
			lucid_print(fout, i+1, actural);
		}

		fout.close();
	}

	{
		double desired = 20;
		double actural = 0;
		std::ofstream fout("test_PI.dat");
		lucidPICtrl contrl = lucidPICtrl(_Kp, _Ki);

		for(int i = 0; i < _Loop; i++)
		{
			actural += contrl.compute(0.1, desired, actural);
			//lucid_print(fout, i+1, actural);
			lucid_print(fout, i+1, actural);
		}

		fout.close();
	
	}

	{
		double desired = 20;
		double actural = 0;
		std::ofstream fout("test_PD.dat");
		lucidPDCtrl contrl = lucidPDCtrl(_Kp, _Kd);

		for(int i = 0; i < _Loop; i++)
		{
			actural += contrl.compute(0.1, desired, actural);
			//lucid_print(fout, i+1, actural);
			lucid_print(fout, i+1, actural);
		}

		fout.close();
	
	}
	return 0;
}