#include <iostream>
#include <vector>
#include "math_lib.h"

using namespace std;

int main() {
	vector<int> arr;
	int i = 0;
	int int_input;
	char char_input;
	
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

	//dale uz je jen vypocet podle vzorecku a vypis do konzole
	int suma = 0; //součet všech čísel
	int N = arr.size();

	for(int i = 0; i < N; i++)
		suma += arr.at(i);
	
	double x = (1.0 / N) * suma;
	double Nxx = N * Math_lib::na_x(x, 2);
	double soucet = 0; // (xx0 + xx1 + ... )

	for(int i = 0; i < N; i++)
		soucet += Math_lib::na_x(arr.at(i), 2);
	
	soucet -= Nxx;
	double s = (1.0 / (N - 1)) * soucet;
	
	s = Math_lib::odmocnina(s, 2);

	//vypis do konzole
	cout << s << endl;
	arr.clear();

	return 0;
}
