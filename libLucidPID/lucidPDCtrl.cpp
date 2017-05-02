#include "lucidPDCtrl.h"

lucidPDCtrl::lucidPDCtrl()
:m_PropController(-1), m_DrvtController(-1)
{

}

lucidPDCtrl::lucidPDCtrl(double _Kp, double _Kd)
:m_PropController(_Kp), m_DrvtController(_Kd)
{

}

double lucidPDCtrl::compute(double dt, double desired, double actual)
{
	return m_PropController.compute(desired, actual) 
		   + m_DrvtController.compute(dt, desired, actual);
}