#ifndef VECTEUR_H
#define VECTEUR_H
#include <vector>
#include <iostream>

template<typename T>
class vecteur {
	friend std::ostream& operator<<(std::ostream& stream, const vecteur& v);
public:
	//Constructeurs
	vecteur<T>(unsigned n);
	vecteur<T>(std::vector<T>);

	//Methodes
	T at(unsigned n);
	unsigned size();
	void resize(unsigned n);
	T somme();

	//Surcharges d'operateurs
	vecteur operator*(int n);
	vecteur operator*(const vecteur& v);
	vecteur operator+(const vecteur& v);
	vecteur operator-(const vecteur& v);


private:
	std::vector<T> data;
};


//IMPLEMENTATION------------------------------------------------------------------

template<typename T>
vecteur<T>::vecteur(unsigned n) {
	this->data = std::vector<T>(n);
}

template<typename T>
vecteur<T>::vecteur(std::vector<T> v) {
	this->data = v;
}

template<typename T>
T vecteur<T>::at(unsigned n) {
	return this->data.at(n);
}

template<typename T>
unsigned vecteur<T>::size() {
	return this->data.size();
}

template<typename T>
void vecteur<T>::resize(unsigned n) {

}

template<typename T>
T vecteur<T>::somme() {

}

template <typename T>
std::ostream& operator<<(std::ostream& s, const vecteur<T>& v) {
	return std::cout << "lkjéj";
}



//#include "vecteurImpl.h"


#endif // !VECTEUR_H
