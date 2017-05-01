#include "lucidPICtrl.h"

lucidPICtrl::lucidPICtrl()
:m_PropController(-1), m_IntgController(-1)
{

}

lucidPICtrl::lucidPICtrl(double _Kp, double _Ki)
:m_PropController(_Kp), m_IntgController(_Ki)
{

}

double lucidPICtrl::compute(double dt, double desired, double actual)
{
	return m_PropController.compute(desired, actual) + m_IntgController.compute(dt, desired, actual);
}