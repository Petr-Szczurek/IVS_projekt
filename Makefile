#Sample Makefile
all: calc.o
	g++ calc.o -o calculator

calc.o: calc.cpp
	g++ -c calc.cpp

test: test.o tests.o math_lib.o
	g++ test.o tests.o math_lib.o -o test

test.o: test.cpp
	g++ -c test.cpp

math_lib.o: math_lib.cpp
	g++ -c math_lib.cpp

tests.o: tests.cpp
	g++ -c tests.cpp

clean:
	rm calc.o math_lib.o test.o calculator test
