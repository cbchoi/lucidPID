all: lucidTest.o LucidPID.a
	clang++ -L. -o lucidTest lucidTest.o -lLucidPID

LucidPID.a: lucidPropCtrl.cpp 
	clang++ -c lucidPropCtrl.cpp -o LucidPID.o -std=c++11 -D_GLIBCXX_USE_NANOSLEEP
	ar -r libLucidPID.a LucidPID.o

lucidTest.o: lucidTest.cpp
		clang++ -c lucidTest.cpp -o lucidTest.o -std=c++11 -D_GLIBCXX_USE_NANOSLEEP
clean:
	rm lucidTest
	rm *.a
	rm *.o