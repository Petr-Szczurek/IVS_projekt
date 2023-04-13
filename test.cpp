#include "tests.h"
#include <iostream>

using namespace std;

int main() {
    bool scitani = Tests::scitani();


    if(scitani)
        cout << "Vsechny testy v poradku\n";

	return 0;
}