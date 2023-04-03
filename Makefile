#Sample Makefile
calc: calc.o
	g++ calc.o -o calculator

calc.o: calc.cpp
	g++ -c calc.cpp

clean:
	rm calc.o calculator
