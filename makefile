# all: (přeloží projekt – včetně programu pro profiling)
# pack (zabalí projekt tak, aby mohl být odevzdán)
# clean (smaže všechny soubory, co nemají být odevzdány)
# test (spustí testy matematické knihovny) 
# doc (spustí generování dokumentace)
# run (spustí program)
# profile (spustí překlad programu pro výpočet směrodatné odchylky na profiling)
# default - all

all: profiling
	qmake kalkulacka.pro
	make -f Makefile

pack:

clean:
	rm math_lib.o test.o tests.o profiling.o main.o Makefile moc_window.o window.o test profiling kalkulacka 

test: test.o tests.o math_lib.o
	g++ test.o tests.o math_lib.o -o test
	./test

doc:

run:
	./kalkulacka

profile: profiling.o math_lib.o
	g++ profiling.o math_lib.o -o profiling

#-------------------------------------------------------#
test.o: test.cpp
	g++ -c test.cpp

tests.o: tests.cpp
	g++ -c tests.cpp

math_lib.o: math_lib.cpp
	g++ -c math_lib.cpp

profiling.o: profiling.cpp
	g++ -c profiling.cpp