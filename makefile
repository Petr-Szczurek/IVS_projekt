# all: (přeloží projekt – včetně programu pro profiling)
# pack (zabalí projekt tak, aby mohl být odevzdán)
# clean (smaže všechny soubory, co nemají být odevzdány)
# test (spustí testy matematické knihovny) 
# doc (spustí generování dokumentace)
# run (spustí program)
# profile (spustí překlad programu pro výpočet směrodatné odchylky na profiling)
# default - all

target:
	qmake kalkulacka.pro
	make -f Makefile

test: test.o tests.o math_lib.o
	g++ test.o tests.o math_lib.o -o test

clean:
	rm math_lib.o test.o tests.o test

test.o: test.cpp
	g++ -c test.cpp

tests.o: tests.cpp
	g++ -c tests.cpp

math_lib.o: math_lib.cpp
	g++ -c math_lib.cpp
