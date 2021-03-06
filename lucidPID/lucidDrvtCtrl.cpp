#include "lucidDrvtCtrl.h"

lucidDrvtCtrl::lucidDrvtCtrl()
{

}

lucidDrvtCtrl::lucidDrvtCtrl(double _Kd)
:m_Kd(_Kd), m_PrevError(0)
{

}

double lucidDrvtCtrl::compute(double dt, double desired, double actual)
{
	#if 0
	if(m_PrevError == 0)
	{
		// inital value
		m_PrevError = (desired - actual);
		return 0;
	}
	else
	#endif
	{
		double Out_d = (dt != 0) ? ((desired - actual) - m_PrevError)/dt: -1;

		m_PrevError = (desired - actual);
		return Out_d*m_Kd;
	}
}