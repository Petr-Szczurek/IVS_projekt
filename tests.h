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
    static double scitani_tri_cisel(double a, double b, double c);

    static bool odecitani();
    static bool odecitani_dvou_cisel();
    static bool odecitani_tri_cisel();

    static bool deleni();
    static bool deleni_dvou_cisel();
    static bool deleni_tri_cisel();
    static bool deleni_nulou();
    static bool deleni_nuly();

    static bool nasobeni();
    static bool nasobeni_dvou_cisel();
    static bool nasobeni_tri_cisel();
    static bool nasobeni_nulou();

    //------------ pokročilejší operace ------------
    static bool mocnina();
    static bool mocnina_nula_zaklad();
    static bool mocnina_nula_exponent();

    static bool odmocnina();
    static bool odmocnina_nula_zaklad();
    static bool odmocnina_nula_exponent();

    static bool modulo();
    static bool modulo_nulou();
    static bool modulo_nuly();

    static bool faktorial();
    static bool faktorial_nuly();
};


#endif // MATH_LIB_H
