#ifndef MATH_LIB_H
#define MATH_LIB_H

#include <cmath>

class Math_lib
{
public:
    //-------------- základní operace --------------
    static double scitani(double a, double b);
    static double odecitani(double a, double b);
    static bool deleni(double a, double b, double* vysledek);
    static double nasobeni(double a, double b);

    //------------ pokročilejší operace ------------
    static double mocnina(double zaklad, double exponent);
    static double odmocnina(double zaklad, double exponent);
    static bool modulo(int a, int b, int* vysledek);
    static long int faktorial(int a);
};


#endif // MATH_LIB_H
