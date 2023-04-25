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
	mkdir ../../xszczu00
	
	mkdir doc
	mv doc ../../xszczu00
	doxygen Doxyfile
	mv html ../../xszczu00/doc
	mv latex ../../xszczu00/doc
	
	
	mkdir install
	mv install ../../xszczu00
	mv ../../Profiling ../../xszczu00/install
#	mv ../../Kalkulacka ../../xszczu00/install	až bude hotová instalačka kalkulačky
	
	mkdir repo
	mv repo ../../xszczu00
	mv ../../IVS_projekt ../../xszczu00/repo

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