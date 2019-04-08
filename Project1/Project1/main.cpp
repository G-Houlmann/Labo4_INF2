#include <iostream>
#include "vecteur.h"

using namespace std;

int main() {
	vector<double> v = { 1.1, 1.2, 3.3 };
	vecteur<double> vect(v);
	vecteur<double> vect2(v);

	vect.at(2) *= 2;
	vect.resize(2);
	//vect.at(3) = 2;

	cout << vect<< endl;




	system("PAUSE");
	return EXIT_SUCCESS;
}
