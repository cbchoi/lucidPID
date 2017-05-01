#pragma once

class lucidPropCtrl
{
private:
	lucidPropCtrl();

public:
	// Contructor
	lucidPropCtrl(double _Kp);

public:
	// Methods
	double compute(double desired, double actual);

public:
	// Getter/Setter
	inline void set_Kp(double _Kp){ m_Kp = _Kp;}
	inline const double get_Kp(){ return m_Kp; }

private:
	// Propositional Term Kp
	double m_Kp;
};
