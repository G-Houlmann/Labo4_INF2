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

template<typename T>
//Exceptions : length error si n trop grand
vecteur<T>::vecteur(unsigned n) {
	try {
		this->data = std::vector<T>(n);
	}
	catch (...) {
		throw taille_trop_haute("La taille de vecteur specifiee est trop haute");
	}
	this->taille = n;
}

template<typename T>
//Exceptions : aucune
vecteur<T>::vecteur(std::vector<T> v) {
	this->data = v;
	this->taille = v.size();
}

template<typename T>
//Exceptions : out of range si n >= taille
T& vecteur<T>::at(unsigned n) {
	if (n >= taille) throw index_hors_limite("L'index specifie est trop grand");
	return this->data.at(n);
}

template<typename T>
//Exceptions : out of range si n >= taille
const T& vecteur<T>::at(unsigned n) const{
	if (n >= taille) throw index_hors_limite("L'index specifie est trop grand");
	return this->data.at(n);
}

template<typename T>
//Exceptions : aucune
unsigned vecteur<T>::size() const{
	return this->taille;
}

template<typename T>
//Exceptions : length error si n trop grand
void vecteur<T>::resize(unsigned n) {
	try {
		this->data.resize(n);
	}
	catch (...) {
		throw taille_trop_haute("La taille de vecteur specifiee est trop haute");
	}
	this->taille = n;
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
	if (this->size() != v.size())
		throw taille_vecteurs_incompatibles("Les 2 vecteurs n'ont pas la meme taille");
	vecteur<T> tmp(this->size());
	for (size_t i = 0; i < this->size(); ++i) {
		tmp.at(i) = v.at(i) * this->at(i);
	}
	return tmp;
}

template <typename T>
//Exceptions : index out of range si 2 vects pas de même taille
vecteur<T> vecteur<T>::operator+(const vecteur& v) const{
	if (this->size() != v.size())
		throw taille_vecteurs_incompatibles("Les 2 vecteurs n'ont pas la meme taille");
	vecteur<T> tmp(this->size());
	for (size_t i = 0; i < this->size(); ++i) {
		tmp.at(i) = v.at(i) + this->at(i);
	}
	return tmp;
}

template <typename T>
//Exceptions : index out of range si 2 vects pas de même taille
vecteur<T> vecteur<T>::operator-(const vecteur& v) const{
	if (this->size() != v.size())
		throw taille_vecteurs_incompatibles("Les 2 vecteurs n'ont pas la meme taille. Fichier: __FILE__ ; Fonction : __func__ ; Ligne: __LINE__.");
	vecteur<T> tmp(this->size());
	for (size_t i = 0; i < this->size(); ++i) {
		tmp.at(i) = v.at(i) - this->at(i);
	}
	return tmp;
}


//#include "vecteurImpl.h"


#endif // !VECTEUR_H
