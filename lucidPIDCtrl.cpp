#include "lucidPIDCtrl.h"

lucidPIDCtrl::lucidPIDCtrl()
:m_PropController(-1), m_IntgController(-1), m_DrvtController(-1)
{

}

lucidPIDCtrl::lucidPIDCtrl(double _Kp, double _Ki, double _Kd)
:m_PropController(_Kp), m_IntgController(_Ki), m_DrvtController(_Kd)
{

}

double lucidPIDCtrl::compute(double dt, double desired, double actual)
{
	return m_PropController.compute(desired, actual) 
		   + m_IntgController.compute(dt, desired, actual) 
		   + m_DrvtController.compute(dt, desired, actual);
}