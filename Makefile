all: lucidTest.o LucidPID.a
	clang++ -L. -o lucidTest lucidTest.o -lLucidPID

LucidPID.a: lucidPropCtrl.cpp 
	clang++ -c lucidPropCtrl.cpp lucidIntgCtrl.cpp lucidPICtrl.cpp lucidDrvtCtrl.cpp lucidPDCtrl.cpp lucidPIDCtrl.cpp -std=c++11 -D_GLIBCXX_USE_NANOSLEEP
	ar -r libLucidPID.a lucidPropCtrl.o lucidIntgCtrl.o lucidPICtrl.o lucidDrvtCtrl.o lucidPDCtrl.o lucidPIDCtrl.o

lucidTest.o: lucidTest.cpp
		clang++ -c lucidTest.cpp -o lucidTest.o -std=c++11 -D_GLIBCXX_USE_NANOSLEEP
clean:
	rm lucidTest
	rm *.a
	rm *.o
	rm *.dat