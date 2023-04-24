#ifndef MATH_LIB_H
#define MATH_LIB_H

/**
 *   @file math_lib.h
 *   @authors Petr Szczurek
 *   @authors Matous Huczala
 *   @authors Martin Rybnikar
 *   @brief Deklarace třídy a funkcí matematické knihovny
 */

/**
 * @brief Funkce matematické knihovny
 */
class Math_lib
{
public:
    Math_lib();

public:

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
static double secti(double a, double b);

/** 
 * @brief Odčítání.
 *
 * Odečte dva čísla a vrátí výsledek.
 * 
 * Příklad užití:
 * @code{.cpp}
 * double x = Math_lib::odecitani(12.0, 2.5)
 * @endcode
 * 
 * @param[in] a Hodnota od které se odčítá
 * @param[in] b Hodnota kterou se odčítá
 * @return Výsledek rozdílu.
*/
static double odecitani(double a, double b);

/** 
 * @brief Dělení.
 *
 * Vydělí dva čísla a vrátí zda se operace povedla.
 * 
 * Příklad užití:
 * @code{.cpp}
 * bool x = Math_lib::deleni(10.0, 2.5, vysledek);
 * @endcode
 * 
 * @param[in] a Dělenec.
 * @param[in] b Dělitel.
 * @param[out] vysledek Ukazatel na výslednou hodnotu.
 * @return @c TRUE pokud se operace povedla. Jinak @c FALSE.
*/
static bool deleni(double a, double b, double* vysledek);

/** 
 * @brief Násobení.
 *
 * Vynásobí dva čísla a vrátí výsledek.
 * 
 * Příklad užití:
 * @code{.cpp}
 * double x = Math_lib::nasobeni(13.1, 10.5);
 * @endcode
 * 
 * @param[in] a 1. Hodnota k násobení.
 * @param[in] b 2. Hodnota k násobení.
 * @return Výsledek násobení
*/
static double nasobeni(double a, double b);

/*******************************************************************************
 * Pokročilejší operace
 ******************************************************************************/

/** 
 * @brief n-tá Odmocnina.
 *
 * Odmocní danou hodnotu zvolenou odmocninou. Prvně zaokrouhlí základ a potom vypočítá.
 * 
 * Příklad užití:
 * @code{.cpp}
 * bool x = Math_lib::odmocnina(27.4, 3, vysledek);
 * @endcode
 * 
 * @param[in] a Hodnota kterou chceme odmocnit. - základ.
 * @param[in] b Hodnota odmocniny. - exponent.
 * @param[out] vysledek Ukazatel na výslednou hodnotu.
 * @return @c TRUE pokud se operace povedla. Jinak @c FALSE.
*/
static bool odmocnina(double a, int b, double* vysledek);

/** 
 * @brief Modulo.
 *
 * Vrátí zbytek po dělení.
 * 
 * Příklad užití:
 * @code{.cpp}
 * bool x = Math_lib::modulo(27, 3, vysledek);
 * @endcode
 * 
 * @param[in] a Hodnota kterou chceme vydělit.
 * @param[in] b Hodnota kterou dělíme
 * @param[out] vysledek Ukazatel na výslednou hodnotu.
 * @return @c TRUE pokud se operace povedla. Jinak @c FALSE.
*/
static bool modulo(int a, int b, double* vysledek);

/** 
 * @brief Faktoriál.
 *
 * Vrátí výsledek faktoriálu daného čísla.
 * 
 * Příklad užití:
 * @code{.cpp}
 * bool x = Math_lib::faktorial(4, vysledek);
 * @endcode
 * 
 * @param[in] a Hodnota ze které chceme faktoriál vypočítat.
 * @param[out] vysledek Ukazatel na výslednou hodnotu.
 * @return @c TRUE pokud se operace povedla. Jinak @c FALSE.
*/
static bool faktorial(int a, int* vysledek);

/** 
 * @brief Obecná mocnina.
 *
 * Umocní danou hodnotu konktrétním exponentem.
 * 
 * Příklad užití:
 * @code{.cpp}
 * double x = Math_lib::na_x(4.0, 2);
 * @endcode
 * 
 * @param[in] a Hodnota kterou chceme umocnit.
 * @param[out] b Exponent.
 * @return Výsledek umocnění.
*/
static double na_x(double a, int b);
};


#endif // MATH_LIB_H
