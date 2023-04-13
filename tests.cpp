#include "tests.h"

//-------------- základní operace --------------
bool Tests::scitani(){
    int inc = 0;

    double res = scitani_dvou_cisel(2, 2);
    if(res != 4){
        cout << "Chyba ve scitani 2 + 2 != " << res << endl;
        inc++;
    }

    res = scitani_dvou_cisel(10, 15);
    if(res != 25){
        cout << "Chyba ve scitani 10 + 15 != " << res << endl;
        inc++;
    }

    res = scitani_dvou_cisel(100.56, 150.21);
    if(res != 250.77){
        cout << "Chyba ve scitani 100,56 + 150,21 != " << res << endl;
        inc++;
    }

    res = scitani_dvou_cisel(-10, 15);
    if(res != 5){
        cout << "Chyba ve scitani -10 + 15 != " << res << endl;
        inc++;
    }

    res = scitani_dvou_cisel(10000, 0);
    if(res != 10000){
        cout << "Chyba ve scitani 10000 + 0 != " << res << endl;
        inc++;
    }

    res = scitani_tri_cisel(100.32, 0, 23.09);
    if(res != 123.41){
        cout << "Chyba ve scitani 100,32 + 0 + 23,09 != " << res << endl;
        inc++;
    }

    res = scitani_tri_cisel(100.32, 13232.45, 23.09);
    if(res != 13355.86){
        cout << "Chyba ve scitani 100,32 + 13232,45 + 23,09 != " << res << endl;
        inc++;
    }

    if(inc == 0){
        cout << "Scitani probehlo uspesne\n";
        return true;
    }
    return false;
}

double Tests::scitani_dvou_cisel(double a, double b){
    return Math_lib::scitani(a, b);
}

double Tests::scitani_tri_cisel(double a, double b, double c){
    double h = Math_lib::scitani(a, b);
    return Math_lib::scitani(h, c);
}

bool Tests::odecitani(){

}

bool Tests::odecitani_dvou_cisel(){

}

bool Tests::odecitani_tri_cisel(){

}

bool Tests::deleni(){

}

bool Tests::deleni_dvou_cisel(){

}

bool Tests::deleni_tri_cisel(){

}

bool Tests::deleni_nulou(){

}

bool Tests::deleni_nuly(){

}

bool Tests::nasobeni(){

}

bool Tests::nasobeni_dvou_cisel(){

}

bool Tests::nasobeni_tri_cisel(){

}

bool Tests::nasobeni_nulou(){

}

//------------ pokročilejší operace ------------
bool Tests::mocnina(){

}

bool Tests::mocnina_nula_zaklad(){

}

bool Tests::mocnina_nula_exponent(){

}

bool Tests::odmocnina(){

}

bool Tests::odmocnina_nula_zaklad(){

}

bool Tests::odmocnina_nula_exponent(){

}

bool Tests::modulo(){

}

bool Tests::modulo_nulou(){

}

bool Tests::modulo_nuly(){

}

bool Tests::faktorial(){

}

bool Tests::faktorial_nuly(){

}
