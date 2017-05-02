#pragma once

class lucidIntgCtrl
{
private:
	lucidIntgCtrl();

public:
	// Contructor
	lucidIntgCtrl(double _Ki);

public:
	// Methods
	double compute(double dt, double desired, double actual);

public:
	// Getter/Setter
	inline void set_Ki(double _Ki){ m_Ki = _Ki;}
	inline const double get_Ki(){ return m_Ki; }

	inline void set_Integral(double _int){ m_Integral = _int;}
	inline const double get_Integral(){ return m_Integral;}
private:
	// Integral Term Ki
	double m_Ki;
	double m_Integral;
};