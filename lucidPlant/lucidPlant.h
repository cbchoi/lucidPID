#pragma once

class lucidPlant
{
public: 
	lucidPlant(double _init, double _prev, double _current, double disturb);

	double process(double _input);
	
private:
	double m_PreviousState;
	double m_PrevPortion;
	double m_CurrentPortion;
	double m_Disturbance;
};