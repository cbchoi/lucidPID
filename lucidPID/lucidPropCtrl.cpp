#include "lucidPropCtrl.h"

lucidPropCtrl::lucidPropCtrl()
{

}

lucidPropCtrl::lucidPropCtrl(double _Kp)
:m_Kp(_Kp)
{

}

double lucidPropCtrl::compute(double _desired, double _actual)
{
	// error: _desired - _actual 
	return m_Kp * (_desired - _actual);
}