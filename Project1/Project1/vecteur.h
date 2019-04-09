#ifndef VECTEUR_H
#define VECTEUR_H
#include <vector>
#include <iostream>
#include "Exceptions.h"

template <typename T> class vecteur;

template <typename T>
std::ostream& operator<< (std::ostream& stream, const vecteur<T>& v) {
	stream << "[";
	for (size_t i = 0; i < v.size(); ++i) {
		stream << v.at(i);
		if(i != v.size() - 1) stream << ", ";
	}
	stream << "]";
	return stream;
}

template<typename T>
class vecteur {
	friend std::ostream& operator<< <T>(std::ostream& stream, const vecteur& v);
public:
	//Constructeurs
	vecteur<T>(unsigned n);
	vecteur<T>(std::vector<T>);
	vecteur<T>(size_t nbElem, T elem);

	//Methodes
	T& at(unsigned n);
	const T& at(unsigned n) const;
	unsigned size() const;
	void resize(unsigned n);
	const T& somme() const;

	//Surcharges d'operateurs
	vecteur<T> operator*(int n) const;
	vecteur<T> operator*(const vecteur& v) const;
	vecteur<T> operator+(const vecteur& v) const;
	vecteur<T> operator-(const vecteur& v) const;


private:
	std::vector<T> data;
	size_t taille;
};


//IMPLEMENTATION------------------------------------------------------------------


#include "vecteurImpl.h"


#endif // !VECTEUR_H
