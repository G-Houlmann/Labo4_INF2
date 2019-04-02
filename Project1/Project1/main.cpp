#include <iostream>
#include "vecteur.h"

using namespace std;

int main() {
	vector<double> v = { 1.1, 1.2, 3.3 };
	vecteur<double> vect(v);

	cout << vect.at(2);



	system("PAUSE");
	return EXIT_SUCCESS;
}
