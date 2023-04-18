#ifndef MATH_LIB_H
#define MATH_LIB_H

class Math_lib
{
public:
    Math_lib();

public:
    static double secti(double a, double b);
    static double odecitani(double a, double b);
    static bool deleni(double a, double b, double* vysledek);
    static double nasobeni(double a, double b);

    static double odmocnina(double a, int b);
    static bool modulo(int a, int b, double* vysledek);
    static bool faktorial(int a, int* vysledek);
    static double na_x(double a, int b);
};


#endif // MATH_LIB_H
