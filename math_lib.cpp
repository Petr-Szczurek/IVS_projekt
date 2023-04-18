#include "math_lib.h"
#include <cmath>


//-------------- základní operace --------------
double Math_lib::secti(double a, double b){
    return a + b;
}

double Math_lib::odecitani(double a, double b){
    return a - b;
}

bool Math_lib::deleni(double a, double b, double* vysledek){
    if(b == 0)
        return false;

    *vysledek = a / b;
    return true;
}

double Math_lib::nasobeni(double a, double b){
    return a * b;
}

//------------ pokročilejší operace ------------
double Math_lib::na_x(double zaklad, int exponent){
    return pow(zaklad, exponent);
}

double Math_lib::odmocnina(double zaklad, int exponent){
    if(exponent == 0)
        return 0;
    return pow(zaklad, 1.0/exponent);
}

bool Math_lib::modulo(int a, int b, double* vysledek){
    if(b == 0)
        return false;

    *vysledek = a % b;
    return true;
}

bool Math_lib::faktorial(int a, int* vysledek){
    if(a >= 0){
        int b = 1;
        for(int i = 1; i <= a; i++)
        {
            b *= i;
        }
        *vysledek = b;
        return true;
    }else{
        return false;
    }
}










