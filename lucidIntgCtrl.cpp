#include "lucidIntgCtrl.h"

lucidIntgCtrl::lucidIntgCtrl()
{

}

lucidIntgCtrl::lucidIntgCtrl(double _Ki)
:m_Ki(_Ki), m_Integral(0)
{

}

double lucidIntgCtrl::compute(double dt, double desired, double actual)
{
	m_Integral = (desired - actual) * dt;
	return m_Ki * m_Integral;
}