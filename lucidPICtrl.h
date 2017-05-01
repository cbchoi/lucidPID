#pragma once
#include "lucidPropCtrl.h"
#include "lucidIntgCtrl.h"

class lucidPICtrl
{
private:
	lucidPICtrl();

public:
	lucidPICtrl(double _Kp, double _Ki);

public:
	double compute(double dt, double desired, double actual);

private:
	lucidPropCtrl m_PropController;
	lucidIntgCtrl m_IntgController;
};