#ifndef TEST_H
#define TEST_H

#include "math_lib.h"
#include <iostream>

using namespace std;

class Tests
{
public:
    //-------------- základní operace --------------
    static bool scitani();
    static double scitani_dvou_cisel(double a, double b);

    static bool odecitani();
    static double odecitani_dvou_cisel(double a, double b);

    static bool deleni();
    static bool deleni_dvou_cisel(double a, double b, double* vysledek);

    static bool nasobeni();
    static double nasobeni_dvou_cisel(double a, double b);

    //------------ pokročilejší operace ------------
    static bool mocnina();

    static bool odmocnina();

    static bool modulo();

    static bool faktorial();
};


#endif // MATH_LIB_H
