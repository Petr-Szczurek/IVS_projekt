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
 * Sečte dva čísla a vrátí výsledek. Implementace funkce.
 * 
 * @param[in] a 1. Hodnota k sečtení
 * @param[in] b 2. Hodnota k sečtení
 * @return Výsledek součtu.
*/
double Math_lib::secti(double a, double b){
    return a + b;
}

/** 
 * @brief Odčítání.
 *
 * Odečte dva čísla a vrátí výsledek. Implementace funkce.
 * 
 * @param[in] a Hodnota od které se odčítá
 * @param[in] b Hodnota kterou se odčítá
 * @return Výsledek rozdílu.
*/
double Math_lib::odecitani(double a, double b){
    return a - b;
}

/** 
 * @brief Dělení.
 *
 * Vydělí dva čísla a vrátí zda se operace povedla. Implementace funkce.
 * 
 * @param[in] a Dělenec.
 * @param[in] b Dělitel.
 * @param[out] vysledek Ukazatel na výslednou hodnotu.
 * @return @c TRUE pokud se operace povedla. Jinak @c FALSE.
*/
bool Math_lib::deleni(double a, double b, double* vysledek){
    if(b == 0)
        return false;

    *vysledek = a / b;
    return true;
}

/** 
 * @brief Násobení.
 *
 * Vynásobí dva čísla a vrátí výsledek. Implementace funkce.
 * 
 * @param[in] a 1. Hodnota k násobení.
 * @param[in] b 2. Hodnota k násobení.
 * @return Výsledek násobení
*/
double Math_lib::nasobeni(double a, double b){
    return a * b;
}

//------------ pokročilejší operace --------------//

/** 
 * @brief Obecná mocnina.
 *
 * Umocní danou hodnotu konktrétním exponentem. Implementace funkce.
 * 
 * @param[in] a Hodnota kterou chceme umocnit.
 * @param[out] vysledek Exponent.
 * @return Výsledek umocnění.
*/
double Math_lib::na_x(double zaklad, int exponent){
    return pow(zaklad, exponent);
}

/** 
 * @brief n-tá Odmocnina.
 *
 * Odmocní danou hodnotu zvolenou odmocninou. Prvně zaokrouhlí základ a potom vypočítá. Implementace funkce.
 * 
 * @param[in] a Hodnota kterou chceme odmocnit. - základ.
 * @param[in] b Hodnota odmocniny. - exponent.
 * @param[out] vysledek Ukazatel na výslednou hodnotu.
 * @return @c TRUE pokud se operace povedla. Jinak @c FALSE.
*/
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

/** 
 * @brief Modulo.
 *
 * Vrátí zbytek po dělení. Implementace funkce.
 * 
 * @param[in] a Hodnota kterou chceme vydělit.
 * @param[in] b Hodnota kterou dělíme
 * @param[out] vysledek Ukazatel na výslednou hodnotu.
 * @return @c TRUE pokud se operace povedla. Jinak @c FALSE.
*/
bool Math_lib::modulo(int a, int b, double* vysledek){
    if(b == 0)
        return false;

    *vysledek = a % b;
    return true;
}

/** 
 * @brief Faktoriál.
 *
 * Vrátí výsledek faktoriálu daného čísla. Implementace funkce.
 * 
 * @param[in] a Hodnota ze které chceme faktoriál vypočítat.
 * @param[out] vysledek Ukazatel na výslednou hodnotu.
 * @return @c TRUE pokud se operace povedla. Jinak @c FALSE.
*/
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