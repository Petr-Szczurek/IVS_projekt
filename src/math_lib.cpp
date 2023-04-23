#include "math_lib.h"
#include <cmath>

/**
 *   @file math_lib.cpp
 *   @author Petr Szczurek
 *   @author Matous Huczala
 *   @author Martin Rybnikar
 */

//-------------- základní operace --------------//

/** 
 * @brief Sčítání.
 *
 * Sečte dva čísla a vrátí výsledek.
 * 
 * Příklad užití:
 * @code{.cpp}
 * double x = Math_lib::secti(3.4, 3.6)
 * @endcode
 * 
 * @param[in] a 1. Hodnota k sečtení
 * @param[in] b 2. Hodnota k sečtení
 * @return Výsledek součtu.
*/
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

//------------ pokročilejší operace --------------//
double Math_lib::na_x(double zaklad, int exponent){
    return pow(zaklad, exponent);
}

bool Math_lib::odmocnina(double zaklad, int exponent, double* vysledek){
    bool sign = true; ///<kontrola kladného nebo záporného čísla
    if (exponent <= 0)
        return false;
    if (exponent%2 == 0){ // ošetření sudých odmocnin a záporného základu
        if (zaklad < 0)
            return false;
    }
    if (zaklad < 0){
        sign = false;
        zaklad = zaklad * -1;
    }

    double zaklad2 = round(zaklad); ///<zaokrouhlení čísla
    int zaklad3 = static_cast<int>(zaklad2); ///<převod čísla na int
    *vysledek = pow(zaklad3, 1.0/exponent); ///<výpočet odmocniny
    if (!sign)
        *vysledek = *vysledek * -1;
    
    return true;
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
    }
    else{
        return false;
    }
}