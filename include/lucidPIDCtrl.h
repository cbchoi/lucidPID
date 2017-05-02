#pragma once

#include "lucidPropCtrl.h"
#include "lucidIntgCtrl.h"
#include "lucidDrvtCtrl.h"

class lucidPIDCtrl
{
private:
	lucidPIDCtrl();

public:
	lucidPIDCtrl(double _Kp, double _Ki, double _Kd);

public:
	double compute(double dt, double desired, double actual);

private:
	lucidPropCtrl m_PropController;
	lucidIntgCtrl m_IntgController;
	lucidDrvtCtrl m_DrvtController;
};