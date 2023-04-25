# all: (přeloží projekt – včetně programu pro profiling)
# pack (zabalí projekt tak, aby mohl být odevzdán)
# clean (smaže všechny soubory, co nemají být odevzdány)
# test (spustí testy matematické knihovny) 
# doc (spustí generování dokumentace)
# run (spustí program)
# profile (spustí překlad programu pro výpočet směrodatné odchylky na profiling)
# default - all
CXX = g++

#all: profile test
#	qmake6 kalkulacka.pro
#	make -f Makefile

pack:

clean:
	rm -f *.o test stddev kalkulacka moc_predefs.h moc_window.cpp 

test: test.o tests.o math_lib.o
	$(CXX) $^ -o $@
	./$@

doc:
	doxygen Doxyfile
	
run:
	./kalkulacka

profile: profiling.o math_lib.o
	$(CXX) $^ -o stddev

#-------------------------------------------------------#
test.o: test.cpp
	$(CXX) -c $^

tests.o: tests.cpp
	$(CXX) -c $^

math_lib.o: math_lib.cpp
	$(CXX) -c $^

profiling.o: profiling.cpp
	$(CXX) -c $^