#include <iostream>
#include <vector>
#include "math_lib.h"

/**
 *   @file profiling.cpp
 *   @author Petr Szczurek
 *   @author Matous Huczala
 *   @author Martin Rybnikar
 */

using namespace std;

int main() 
{
	vector<int> arr; ///< pole znaků
	int i = 0; ///< přepínač podmínek
	int int_input; ///< dočasná proměnná pro hodnoty
	char char_input; ///< načítání znaků
	
	//cyklus pro načtení čísel ze souboru
	do{
		if(i == 0){
			cin >> int_input;
			arr.push_back(int_input);
			i = 1;
		}
		else{
			char_input = getchar();
			i = 0;
		}
	} while(char_input != EOF);

	//výpočet podle vzorce a výpis do konzole
	int suma = 0; ///<součet všech čísel
	int N = arr.size();

	for(int i = 0; i < N; i++)
		suma = Math_lib::secti(suma, arr.at(i));
	
	double n = 0;
	Math_lib::deleni(1.0, N, &n);
	double x = Math_lib::nasobeni(n, suma);
	double Nxx = Math_lib::nasobeni(N, Math_lib::na_x(x, 2));
	double soucet = 0; ///< (xx0 + xx1 + ... )

	for(int i = 0; i < N; i++)
		soucet = Math_lib::secti(soucet, Math_lib::na_x(arr.at(i), 2));

	soucet = Math_lib::odecitani(soucet, Nxx);
	n = 0;
	Math_lib::deleni(1.0, Math_lib::odecitani(N, 1), &n);
	double s = Math_lib::nasobeni(n, soucet);
	
	bool valid = true;
	valid = Math_lib::odmocnina(s, 2, &s);
	if (!valid){
		cout << "Chyba pri pocitani odmocniny\n";
		return -1;
	}
	
	//výpis do konzole
	cout << s << endl;
	arr.clear();

	return 0;
}
