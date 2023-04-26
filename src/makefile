CXX = g++

all: profile
	qmake6 kalkulacka.pro
	make -f Makefile

# pro zabalení je potřeba mít instalační balíčky v adresáři nad repozitářem a adresář xlongin... nesmí existovat ve stejnem adresáři.
pack:
	mkdir -p ../../xszczu00_xhucza02_xrybni10
	
	mkdir -p doc
	rm -rf ../../xszczu00_xhucza02_xrybni10/doc
	mv doc ../../xszczu00_xhucza02_xrybni10
	doxygen Doxyfile
	mv -f html ../../xszczu00_xhucza02_xrybni10/doc
	mv -f latex ../../xszczu00_xhucza02_xrybni10/doc
	
	mkdir -p install
	mv -i -n install ../../xszczu00_xhucza02_xrybni10
	mv -i -n ../../stddev_04_amd64.deb ../../xszczu00_xhucza02_xrybni10/install
	mv -i -n ../../kalkulacka_04_amd64.deb ../../xszczu00_xhucza02_xrybni10/install
	
	mkdir  -p repo
	rm -rf ../../xszczu00_xhucza02_xrybni10/repo
	mv -f repo ../../xszczu00_xhucza02_xrybni10
	cp -R ../../IVS_projekt ../../xszczu00_xhucza02_xrybni10/repo/

	cd .. && cd .. && zip -r xszczu00_xhucza02_xrybni10.zip xszczu00_xhucza02_xrybni10/
	rm -rf ../../xszczu00_xhucza02_xrybni10

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