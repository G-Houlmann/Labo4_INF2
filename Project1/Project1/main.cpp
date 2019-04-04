#include <iostream>
#include "vecteur.h"

using namespace std;

int main() {
	vector<double> v = { 1.1, 1.2, 3.3 };
	vecteur<double> vect(v);

	double ui = vect.at(0);

	ui = 54;
	cout << vect << endl;




	system("PAUSE");
	return EXIT_SUCCESS;
}
