#include "math_lib.h"

//-------------- základní operace --------------
double Math_lib::scitani(double a, double b){
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
double Math_lib::mocnina(double zaklad, double exponent){
    return pow(zaklad, exponent);
}

double Math_lib::odmocnina(double zaklad, double exponent){
    return pow(zaklad, 1 / exponent);
}

bool Math_lib::modulo(int a, int b, int* vysledek){
    if(b == 0)
        return false;
    
    *vysledek = a % b;
    return true;
}

long int Math_lib::faktorial(int a){
    long int vysledek = 1;
    for(int i = 1; i <= a; i++)
        vysledek *= i;
    
    return vysledek;
}
