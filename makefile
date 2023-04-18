
target:
	qmake kalkulacka.pro
	make -f Makefile

test: test.o tests.o math_lib.o
	g++ test.o tests.o math_lib.o -o test

test.o: test.cpp
	g++ -c test.cpp

math_lib.o: math_lib.cpp
	g++ -c math_lib.cpp

tests.o: tests.cpp
	g++ -c tests.cpp

clean:
	rm math_lib.o test.o tests.o test