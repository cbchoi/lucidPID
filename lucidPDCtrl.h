#pragma once

#include "lucidPropCtrl.h"
#include "lucidDrvtCtrl.h"

class lucidPDCtrl
{
private:
	lucidPDCtrl();

public:
	lucidPDCtrl(double _Kp, double _Kd);

public:
	double compute(double dt, double desired, double actual);

private:
	lucidPropCtrl m_PropController;
	lucidDrvtCtrl m_DrvtController;
};