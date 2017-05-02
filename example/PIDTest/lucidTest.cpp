#include <iostream>
#include <fstream>
#include "lucidPropCtrl.h"
#include "lucidPICtrl.h"
#include "lucidPDCtrl.h"
#include "lucidPIDCtrl.h"

class Plant
{
public: 
	Plant(double _init, double _prev, double _current, double disturb)
	:m_PreviousValue(_init), m_PrevPortion(_prev), m_CurrentPortion(_current), m_Disturbance(disturb)
	{

	}

	double compute(double _input)
	{
		double out = m_PrevPortion * m_PreviousValue 
					 + m_CurrentPortion* _input 
					 + m_Disturbance;

		m_PreviousValue = out;

		std::cout << out << std::endl;
		return out;
	}

private:
	double m_PreviousValue;
	double m_PrevPortion;
	double m_CurrentPortion;
	double m_Disturbance;
};

void lucid_print(std::ostream& strm, int _index, double _value)
{
	strm << _value << std::endl;
}

int main(int argc, char** argv)
{
	double _Kp = 1;
	double _Ki = 1;
	double _Kd = 0.1;
	int    _Loop = 50;
	double _dt = 1;

	{
		double desired = 20;
		double actural = 0;
		double request = 0;
		std::ofstream fout("test_P.dat");
		lucidPropCtrl contrl = lucidPropCtrl(_Kp);
		Plant plant = Plant(actural, 0.7, 0.5, 0);

		for(int i = 0; i < _Loop; i++)
		{
			request = contrl.compute(desired, actural);
			//std::cout << "r\t" << request << std::endl;
			actural = plant.compute(request);
			//lucid_print(fout, i+1, actural);
			lucid_print(fout, i+1, actural);
		}

		fout.close();
	}
	std::cin.get();
	{
		double desired = 20;
		double actural = 0;
		double request = 0;
		std::ofstream fout("test_PI.dat");
		lucidPICtrl contrl = lucidPICtrl(_Kp, _Ki);
		Plant plant = Plant(actural, 0.7, 0.5, 0);
		
		for(int i = 0; i < _Loop; i++)
		{
			request = contrl.compute(_dt, desired, actural);
			//std::cout << "r\t" << request << std::endl;
			actural = plant.compute(request);
			//lucid_print(fout, i+1, actural);
			lucid_print(fout, i+1, actural);
		}

		fout.close();
	
	}
	std::cin.get();
	{
		double desired = 20;
		double actural = 0;
		double request = 0;
		std::ofstream fout("test_PD.dat");
		lucidPDCtrl contrl = lucidPDCtrl(_Kp, _Kd);
		Plant plant = Plant(actural, 0.7, 0.5, 0);
		
		for(int i = 0; i < _Loop; i++)
		{
			request = contrl.compute(_dt, desired, actural);
			//std::cout << "r\t" << request << std::endl;
			actural = plant.compute(request);
			//lucid_print(fout, i+1, actural);
			lucid_print(fout, i+1, actural);
		}

		fout.close();
	
	}
	std::cin.get();
	{
		double desired = 20;
		double actural = 0;
		double request = 0;
		std::ofstream fout("test_PID.dat");
		lucidPIDCtrl contrl = lucidPIDCtrl(_Kp, _Ki, _Kd);
		Plant plant = Plant(actural, 0.7, 0.5, 0);
		
		for(int i = 0; i < _Loop; i++)
		{
			request = contrl.compute(_dt, desired, actural);
			//std::cout << "r\t" << request << std::endl;
			actural = plant.compute(request);
			//lucid_print(fout, i+1, actural);
			lucid_print(fout, i+1, actural);
		}

		fout.close();
	
	}
	return 0;
}