#include "tests.h"
#include <iostream>

using namespace std;

int main() {
    bool scitani = Tests::secti();
    bool odecitani = Tests::odecitani();
    bool deleni = Tests::deleni();
    bool nasobeni = Tests::nasobeni();

    bool mocnina = Tests::na_x();
    bool odmocnina = Tests::odmocnina();
    bool modulo = Tests::modulo();
    bool faktorial = Tests::faktorial();

    if(scitani && odecitani && deleni && nasobeni && mocnina && odmocnina && modulo && faktorial)
        cout << "Vsechny testy v poradku\n";

	return 0;
}