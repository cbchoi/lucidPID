#include "lucidPlant.h"

lucidPlant::lucidPlant(double _init, double _prev, double _current, double disturb)
	:m_PreviousState(_init), m_PrevPortion(_prev), m_CurrentPortion(_current), m_Disturbance(disturb)
{

}

double lucidPlant::process(double _input)
{
	double out = m_PrevPortion * m_PreviousState 
				 + m_CurrentPortion* _input 
				 + m_Disturbance;

	m_PreviousState = out;
	return out;
}
