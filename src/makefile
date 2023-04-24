# all: (přeloží projekt – včetně programu pro profiling)
# pack (zabalí projekt tak, aby mohl být odevzdán)
# clean (smaže všechny soubory, co nemají být odevzdány)
# test (spustí testy matematické knihovny) 
# doc (spustí generování dokumentace)
# run (spustí program)
# profile (spustí překlad programu pro výpočet směrodatné odchylky na profiling)
# default - all
CXX = g++

#all: profiling test
#	qmake kalkulacka.pro
#	make -f Makefile

pack:

clean:
	rm math_lib.o test.o tests.o profiling.o main.o moc_window.o window.o test profiling kalkulacka 
#	rm Makefile

test: test.o tests.o math_lib.o
	$(CXX) test.o tests.o math_lib.o -o test
	./test

doc:

run:
	./kalkulacka

profile: profiling.o math_lib.o
	$(CXX) profiling.o math_lib.o -o profiling

#-------------------------------------------------------#
test.o: test.cpp
	$(CXX) -c test.cpp

tests.o: tests.cpp
	$(CXX) -c tests.cpp

math_lib.o: math_lib.cpp
	$(CXX) -c math_lib.cpp

profiling.o: profiling.cpp
	$(CXX) -c profiling.cpp