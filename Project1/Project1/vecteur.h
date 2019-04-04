#ifndef VECTEUR_H
#define VECTEUR_H
#include <vector>
#include <iostream>

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
};


//IMPLEMENTATION------------------------------------------------------------------

template<typename T>
//Exceptions : length error si n trop grand
vecteur<T>::vecteur(unsigned n) {
	this->data = std::vector<T>(n);
}

template<typename T>
//Exceptions : aucune
vecteur<T>::vecteur(std::vector<T> v) {
	this->data = v;
}

template<typename T>
//Exceptions : out of range si n >= taille
T& vecteur<T>::at(unsigned n) {
	return this->data.at(n);
}

template<typename T>
//Exceptions : out of range si n >= taille
const T& vecteur<T>::at(unsigned n) const{
	return this->data.at(n);
}

template<typename T>
//Exceptions : aucune
unsigned vecteur<T>::size() const{
	return this->data.size();
}

template<typename T>
//Exceptions : length error si n trop grand
void vecteur<T>::resize(unsigned n) {
	this->data.resize(n);
}

template<typename T>
//Exceptions : aucune
const T& vecteur<T>::somme() const{
	T somme = NULL;
	for (size_t i = 0; i < this->size(); ++i) {
		somme += this->at(i);
	}
	return somme;
}


template <typename T>
//Exceptions : aucune
vecteur<T> vecteur<T>::operator*(int n) const{
	vecteur<T> tmp(this->size());
	for (size_t i = 0; i < this->size(); ++i) {
		tmp.at(i) = n * this->at(i);
	}
	return tmp;
}

template <typename T>
//Exceptions : index out of range si 2 vects pas de même taille
vecteur<T> vecteur<T>::operator*(const vecteur& v) const{
	if (this->size() != v.size());
	vecteur<T> tmp(this->size());
	for (size_t i = 0; i < this->size(); ++i) {
		tmp.at(i) = v.at(i) * this->at(i);
	}
}

template <typename T>
//Exceptions : index out of range si 2 vects pas de même taille
vecteur<T> vecteur<T>::operator+(const vecteur& v) const{
	if (this->size() != v.size());
	vecteur<T> tmp(this->size());
	for (size_t i = 0; i < this->size(); ++i) {
		tmp.at(i) = v.at(i) + this->at(i);
	}
}

template <typename T>
//Exceptions : index out of range si 2 vects pas de même taille
vecteur<T> vecteur<T>::operator-(const vecteur& v) const{
	if (this->size() != v.size());
	vecteur<T> tmp(this->size());
	for (size_t i = 0; i < this->size(); ++i) {
		tmp.at(i) = v.at(i) - this->at(i);
	}
}


//#include "vecteurImpl.h"


#endif // !VECTEUR_H
