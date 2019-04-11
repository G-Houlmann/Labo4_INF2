#include <iostream>
#include "vecteur.h"
#include "matrice.h"


using namespace std;

int main() {
	vector<double> v = { 1.1, 1.2, 3.3 };
	vecteur<double> vect(v);
	vecteur<double> vect2(v);
	vect2.resize(5);
	matrice<double> m(3, 4);
	m.resize(5, 12);
	
	cout << m.size() << "   " << m.sizeC() << endl;


	system("PAUSE");
	return EXIT_SUCCESS;
}
