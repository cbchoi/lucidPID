# lucidPID: C++ library for PID Controller
The lucidPID Controller is simple PID Controller library. The lucidPID Controller implements the controller based on the control theory. 

## Design Concept
The lucidPID Controller adopts the object-oriented design concepts. 

## How to use it
Utilizing lucidPID Controller is easy and intuitive. All you need to do is just instantiate an instance. 

### Propositional Controller
```C++
double _Kp = 1;
int    _Loop = 50;
double desired = 20;
double actural = 0;
double request = 0;
lucidPropCtrl contrl = lucidPropCtrl(_Kp);
for(int i = 0; i < _Loop; i++)
{
    request = contrl.compute(desired, actural);
    actural = plant.compute(request);
    std::cout << "Desire:" << desired <<"\tRequest:" << request <<"\tActual:" << actural << std::endl; 
}
```
