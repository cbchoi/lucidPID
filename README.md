# lucidPID: C++ library for PID Controller
The lucidPID Controller is simple PID Controller library. The lucidPID Controller implements the controller based on the control theory. 

## Design Concept
The lucidPID Controller adopts the object-oriented design concepts. 

## How to use it
Utilizing lucidPID Controller is easy and intuitive. All you need to do is just instantiate an instance. 

### Proportional Controller
```C++
// Proportional gain
double _Kp = 1;

// Desired valuer
double desired = 20;
double actural = 0;
double request = 0;

// Instantiating controller
lucidPropCtrl contrl = lucidPropCtrl(_Kp);

for(int i = 0; i < _Loop; i++)
{
    request = contrl.compute(desired, actural);
    actual = request; // You must pass request value to the plant
    std::cout << "Desire:" << desired <<"\tRequest:" << request <<"\tActual:" << actural << std::endl; 
}
```
