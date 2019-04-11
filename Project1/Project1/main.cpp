/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : main.cpp
 Auteur(s)   : LAMRANI Soulaymane, HOULMANN Gildas
 Date        : 11.04.2019

 Remarque(s) : Ce programme sert uniquement à tester la librairie réalisée

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include "matrice.h"


using namespace std;

int main() {
	vector<double> v = { 1.1, 1.2, 3.3 };
	vecteur<double> vect(v);
	vecteur<double> vect2(v);
	vect2.resize(200);
	matrice<double> m(3, 4);
	m.resize(5, 12);
	
	cout << m.size() << "   " << m.sizeC() << endl;


	system("PAUSE");
	return EXIT_SUCCESS;
}
