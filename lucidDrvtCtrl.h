#pragma once

class lucidDrvtCtrl
{
private:
	lucidDrvtCtrl();

public:
	// Contructor
	lucidDrvtCtrl(double _Kd);

public:
	// Methods
	double compute(double dt, double desired, double actual);

public:
	// Getter/Setter
	inline void set_Kd(double _Kd){ m_Kd = _Kd;}
	inline const double get_Kd(){ return m_Kd; }

private:
	// Derivative Term Kd
	double m_Kd;
	double m_PrevError;
};