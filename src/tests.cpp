#include "tests.h"

/**
 *   @file tests.cpp
 *   @author Petr Szczurek
 *   @author Matous Huczala
 *   @author Martin Rybnikar
 * 
 *   @brief Implementace jednotlivých testů na jednotlivé funkce matematické knihovny.
 */

//==============================================//
//-------------- základní operace --------------//
//==============================================//

/**
 * @brief Testy na sčítání. 
 */
bool Tests::secti(){
    int inc = 0;

    double res = scitani_dvou_cisel(2, 2);
    if(res != 4){
        cout << "Chyba pri scitani 2 + 2 != " << res << endl;
        inc++;
    }

    res = scitani_dvou_cisel(10, 15);
    if(res != 25){
        cout << "Chyba pri scitani 10 + 15 != " << res << endl;
        inc++;
    }

    res = scitani_dvou_cisel(100.56, 150.21);
    if(res != 250.77){
        cout << "Chyba pri scitani 100,56 + 150,21 != " << res << endl;
        inc++;
    }

    res = scitani_dvou_cisel(-10, 15);
    if(res != 5){
        cout << "Chyba pri scitani -10 + 15 != " << res << endl;
        inc++;
    }

    res = scitani_dvou_cisel(10000, 0);
    if(res != 10000){
        cout << "Chyba pri scitani 10000 + 0 != " << res << endl;
        inc++;
    }

    if(inc == 0){
        cout << "Scitani probehlo uspesne\n";
        return true;
    }
    return false;
}

double Tests::scitani_dvou_cisel(double a, double b){
    return Math_lib::secti(a, b);
}

/**
 * @brief Testy na odčítání. 
 */
bool Tests::odecitani(){
    int inc = 0;

    double res = odecitani_dvou_cisel(2, 2);
    if(res != 0){
        cout << "Chyba pri odecitani 2 - 2 != " << res << endl;
        inc++;
    }

    res = odecitani_dvou_cisel(10, 15);
    if(res != -5){
        cout << "Chyba pri odecitani 10 - 15 != " << res << endl;
        inc++;
    }

    res = odecitani_dvou_cisel(150.18, 100.56);
    if(res != 150.18 - 100.56){
        cout << "Chyba pri odecitani 150,21 - 100,56 != " << res << endl;
        inc++;
    }

    res = odecitani_dvou_cisel(-10, 15);
    if(res != -25){
        cout << "Chyba pri odecitani -10 - 15 != " << res << endl;
        inc++;
    }

    res = odecitani_dvou_cisel(10000, 0);
    if(res != 10000){
        cout << "Chyba pri odecitani 10000 - 0 != " << res << endl;
        inc++;
    }

    if(inc == 0){
        cout << "Odecitani probehlo uspesne\n";
        return true;
    }
    return false;
}

double Tests::odecitani_dvou_cisel(double a, double b){
    return Math_lib::odecitani(a, b);
}

/**
 * @brief Testy na dělení. 
 */
bool Tests::deleni(){
    int inc = 0;
    double res = 0;

    bool cnt = deleni_dvou_cisel(2, 2, &res);
    if(!cnt){
        cout << "Nulou nelze delit\n";
        inc++;
    }
    else if(res != 1){
        cout << "Chyba pri deleni 2 / 2 != " << res << endl;
        inc++;
    }

    cnt = deleni_dvou_cisel(1000, 10, &res);
    if(!cnt){
        cout << "Nulou nelze delit\n";
        inc++;
    }
    else if(res != 100){
        cout << "Chyba pri deleni 1000 / 10 != " << res << endl;
        inc++;
    }

    cnt = deleni_dvou_cisel(10, 1000, &res);
    if(!cnt){
        cout << "Nulou nelze delit\n";
        inc++;
    }
    else if(res != 0.01){
        cout << "Chyba pri deleni 10 / 1000 != " << res << endl;
        inc++;
    }

    cnt = deleni_dvou_cisel(0, 10, &res);
    if(!cnt){
        cout << "Nulou nelze delit\n";
        inc++;
    }
    else if(res != 0){
        cout << "Chyba pri deleni 0 / 10 != " << res << endl;
        inc++;
    }

    cnt = deleni_dvou_cisel(524, 0, &res);
    if(cnt){
        cout << "Nulou nelze delit\n";
        inc++;
    }

    if(inc == 0){
        cout << "Deleni probehlo uspesne\n";
        return true;
    }
    return false;
}

bool Tests::deleni_dvou_cisel(double a, double b, double* vysledek){
    return Math_lib::deleni(a, b, vysledek);
}

/**
 * @brief Testy na násobení. 
 */
bool Tests::nasobeni(){
    int inc = 0;

    double res = nasobeni_dvou_cisel(2, 5);
    if(res != 10){
        cout << "Chyba pri nasobeni 2 * 5 != " << res << endl;
        inc++;
    }

    res = nasobeni_dvou_cisel(5, 2);
    if(res != 10){
        cout << "Chyba pri nasobeni 5 * 2 != " << res << endl;
        inc++;
    }

    res = nasobeni_dvou_cisel(100, 100);
    if(res != 10000){
        cout << "Chyba pri nasobeni 100 * 100 != " << res << endl;
        inc++;
    }

    res = nasobeni_dvou_cisel(25, 0);
    if(res != 0){
        cout << "Chyba pri nasobeni 25 * 0 != " << res << endl;
        inc++;
    }

    res = nasobeni_dvou_cisel(24423, 23232);
    if(res != 567395136){
        cout << "Chyba pri nasobeni 24423 * 23232 != " << res << endl;
        inc++;
    }

    if(inc == 0){
        cout << "Nasobeni probehlo uspesne\n";
        return true;
    }
    return false;
}

double Tests::nasobeni_dvou_cisel(double a, double b){
    return Math_lib::nasobeni(a, b);
}

//==============================================//
//------------ pokročilejší operace ------------//
//==============================================//

/**
 * @brief Testy na obecnou mocninu. 
 */
bool Tests::na_x(){
    int inc = 0;

    double res = Math_lib::na_x(2, 3);
    if(res != 8){
        cout << "Chyba pri pocitani mocniny 2 ^ 3 != " << res << endl;
        inc++;
    }

    res = Math_lib::na_x(3, 2);
    if(res != 9){
        cout << "Chyba pri pocitani mocniny 3 ^ 2 != " << res << endl;
        inc++;
    }

    res = Math_lib::na_x(10, 5);
    if(res != 100000){
        cout << "Chyba pri pocitani mocniny 10 ^ 5 != " << res << endl;
        inc++;
    }

    res = Math_lib::na_x(2, 8);
    if(res != 256){
        cout << "Chyba pri pocitani mocniny 2 ^ 8 != " << res << endl;
        inc++;
    }

    res = Math_lib::na_x(10, 0);
    if(res != 1){
        cout << "Chyba pri pocitani mocniny 10 ^ 0 != " << res << endl;
        inc++;
    }

    res = Math_lib::na_x(0, 1);
    if(res != 0){
        cout << "Chyba pri pocitani mocniny 0 ^ 1 != " << res << endl;
        inc++;
    }

    if(inc == 0){
        cout << "Vypocet mocniny probehl uspesne\n";
        return true;
    }
    return false;
}

/**
 * @brief Testy na obecnou odmocninu. 
 */
bool Tests::odmocnina(){
    int inc = 0;
    double res = 0;

    bool cnt = Math_lib::odmocnina(-8.4, 3, &res);
    if(!cnt){
        cout << "Chyba pri pocitani odmocniny1\n";
        inc++;
    }
    else if(res != -2){
        cout << "Chyba pri vypoctu odmocniny 3 v 8 != " << res << endl;
        inc++;
    }

    cnt = Math_lib::odmocnina(16, 2, &res);
    if(!cnt){
        cout << "Chyba pri pocitani odmocniny2\n";
        inc++;
    }
    else if(res != 4){
        cout << "Chyba pri pocitani odmocniny 2 v 16 != " << res << endl;
        inc++;
    }

    cnt = Math_lib::odmocnina(10000, 4, &res);
    if(!cnt){
        cout << "Chyba pri pocitani odmocniny3\n";
        inc++;
    }
    else if(res != 10){
        cout << "Chyba pri pocitani odmocniny 4 v 10000 != " << res << endl;
        inc++;
    }

    cnt = Math_lib::odmocnina(256, 8, &res);
    if(!cnt){
        cout << "Chyba pri pocitani odmocniny4\n";
        inc++;
    }
    else if(res != 2){
        cout << "Chyba pri pocitani odmocniny 8 v 256 != " << res << endl;
        inc++;
    }

    cnt = Math_lib::odmocnina(10, 0, &res);
    if(cnt){
        cout << "Chyba pri pocitani odmocniny5\n";
        inc++;
    }

    cnt = Math_lib::odmocnina(0, 1, &res);
    if(!cnt){
        cout << "Chyba pri pocitani odmocniny6\n";
        inc++;
    }
    else if(res != 0){
        cout << "Chyba pri pocitani odmocniny 1 v 0 != " << res << endl;
        inc++;
    }

    cnt = Math_lib::odmocnina(-0.5, 1, &res);
    if(!cnt){
        cout << "Chyba pri pocitani odmocniny6\n";
        inc++;
    }
    else if(res != -1){
        cout << "Chyba pri pocitani odmocniny 1 v -0.5 != " << res << endl;
        inc++;
    }

    if(inc == 0){
        cout << "Vypocet odmocniny probehl uspesne\n";
        return true;
    }
    return false;
}

/**
 * @brief Testy na modulo. 
 */
bool Tests::modulo(){
    int inc = 0;
    double res = 0;

    bool cnt = Math_lib::modulo(10, 2, &res);
    if(!cnt){
        cout << "Nulou nelze delit\n";
        inc++;
    }
    else if(res != 0){
        cout << "Chyba pri vypoctu modula 10 % 2 != " << res << endl;
        inc++;
    }
    
    cnt = Math_lib::modulo(11, 2, &res);
    if(!cnt){
        cout << "Nulou nelze delit\n";
        inc++;
    }
    else if(res != 1){
        cout << "Chyba pri vypoctu modula 11 % 2 != " << res << endl;
        inc++;
    }

    cnt = Math_lib::modulo(16, 100, &res);
    if(!cnt){
        cout << "Nulou nelze delit\n";
        inc++;
    }
    else if(res != 16){
        cout << "Chyba pri vypoctu modula 16 % 100 != " << res << endl;
        inc++;
    }

    cnt = Math_lib::modulo(10, 0, &res);
    if(cnt){
        cout << "Nulou nelze delit\n";
        inc++;
    }

    cnt = Math_lib::modulo(0, 2, &res);
    if(!cnt){
        cout << "Nulou nelze delit\n";
        inc++;
    }
    else if(res != 0){
        cout << "Chyba pri vypoctu modula 10 % 2 != " << res << endl;
        inc++;
    }

    if(inc == 0){
        cout << "Vypocet modula probehl uspesne\n";
        return true;
    }
    return false;
}

/**
 * @brief Testy na faktoriál. 
 */
bool Tests::faktorial(){
    int inc = 0;
    int res = 0;

    bool cnt = Math_lib::faktorial(4, &res);
    if(!cnt){
        cout << "Nelze pocitat faktorial ze zaporne hodnoty\n";
        inc++;
    }
    else if(res != 24){
        cout << "Chyba pri vypoctu faktorialu 4! != " << res << endl;
        inc++;
    }

    cnt = Math_lib::faktorial(5, &res);
    if(!cnt){
        cout << "Nelze pocitat faktorial ze zaporne hodnoty\n";
        inc++;
    }
    else if(res != 120){
        cout << "Chyba pri vypoctu faktorialu 5! != " << res << endl;
        inc++;
    }

    cnt = Math_lib::faktorial(10, &res);
    if(!cnt){
        cout << "Nelze pocitat faktorial ze zaporne hodnoty\n";
        inc++;
    }
    else if(res != 3628800){
        cout << "Chyba pri vypoctu faktorialu 10! != " << res << endl;
        inc++;
    }

    cnt = Math_lib::faktorial(11, &res);
    if(!cnt){
        cout << "Nelze pocitat faktorial ze zaporne hodnoty\n";
        inc++;
    }
    else if(res != 39916800){
        cout << "Chyba pri vypoctu faktorialu 100! != " << res << endl;
        inc++;
    }

    cnt = Math_lib::faktorial(0, &res);
    if(!cnt){
        cout << "Nelze pocitat faktorial ze zaporne hodnoty\n";
        inc++;
    }
    else if(res != 1){
        cout << "Chyba pri vypoctu faktorialu 0! != " << res << endl;
        inc++;
    }

    if(inc == 0){
        cout << "Vypocet faktorialu probehl uspesne\n";
        return true;
    }
    return false;
}