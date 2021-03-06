/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : vecteurImpl.h
 Auteur(s)   : LAMRANI Soulaymane, HOULMANN Gildas
 Date        : 11.04.2019

 Remarque(s) :

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef VECTEURIMPL_H
#define VECTEURIMPL_H

template<typename T>
vecteur<T>::vecteur(unsigned n) {
	try {
		this->data = std::vector<T>(n);
	}
	catch (std::length_error) {
		throw taille_trop_haute("La taille de vecteur specifiee est trop haute.",
								__FILE__);
	}
	catch (std::bad_alloc) {
		throw erreur_allocation("Une erreur d'allocation est survenue",
			__FILE__);
	}
	this->taille = n;
}

template<typename T>
vecteur<T>::vecteur(std::vector<T> v) {
	try {
		this->data = v;
		this->taille = v.size();
	}
	catch (std::bad_alloc) {
		throw erreur_allocation("Une erreur d'allocation est survenue",
			__FILE__);
	}
}

template<typename T>
vecteur<T>::vecteur(size_t nbElem, T elem) {
	try {
		std::vector<T> v(nbElem, elem);
		data = v;
		taille = nbElem;
	}
	catch (std::bad_alloc) {
		throw erreur_allocation("Une erreur d'allocation est survenue",
			__FILE__);
	}
}

template<typename T>
vecteur<T>::vecteur() {
	std::vector<T> v;
	data = v;
	taille = 0;
}

template<typename T>
T& vecteur<T>::at(unsigned n) {
	if (n >= taille) throw index_hors_limite("L'index specifie est trop grand.",
											 __FILE__);
	return this->data.at(n);
}

template<typename T>
const T& vecteur<T>::at(unsigned n) const {
	if (n >= taille) throw index_hors_limite("L'index specifie est trop grand.",
											 __FILE__);
	return this->data.at(n);
}

template<typename T>
unsigned vecteur<T>::size() const {
	return this->taille;
}

template<typename T>
void vecteur<T>::resize(unsigned n) {
	try {
		this->data.resize(n);
	}
	catch (std::length_error) {
		throw taille_trop_haute("La taille de vecteur specifiee est trop haute.",
								__FILE__);
	}
	catch (std::bad_alloc) {
		throw erreur_allocation("Une erreur d'allocation est survenue",
			__FILE__);
	}
	this->taille = n;
}

template<typename T>
T vecteur<T>::somme() const {
	T somme = NULL;
	for (size_t i = 0; i < this->size(); ++i) {
		somme += this->at(i);
	}
	return somme;
}


template <typename T>
vecteur<T> vecteur<T>::operator*(int n) const {
	vecteur<T> tmp(this->size());
	for (size_t i = 0; i < this->size(); ++i) {
		tmp.at(i) = n * this->at(i);
	}
	return tmp;
}

template <typename T>
vecteur<T> vecteur<T>::operator*(const vecteur& v) const {
	if (this->size() != v.size())
		throw taille_vecteurs_incompatibles
			("Les 2 vecteurs n'ont pas la meme taille.", __FILE__);
	vecteur<T> tmp(this->size());
	for (size_t i = 0; i < this->size(); ++i) {
		tmp.at(i) = v.at(i) * this->at(i);
	}
	return tmp;
}

template <typename T>
vecteur<T> vecteur<T>::operator+(const vecteur& v) const {
	if (this->size() != v.size())
		throw taille_vecteurs_incompatibles
			("Les 2 vecteurs n'ont pas la meme taille. ", __FILE__);
	vecteur<T> tmp(this->size());
	for (size_t i = 0; i < this->size(); ++i) {
		tmp.at(i) = v.at(i) + this->at(i);
	}
	return tmp;
}

template <typename T>
vecteur<T> vecteur<T>::operator-(const vecteur& v) const {
	if (this->size() != v.size())
		throw taille_vecteurs_incompatibles
			("Les 2 vecteurs n'ont pas la meme taille. ", __FILE__);
	vecteur<T> tmp(this->size());
	for (size_t i = 0; i < this->size(); ++i) {
		tmp.at(i) = v.at(i) - this->at(i);
	}
	return tmp;
}

#endif // !VECTEURIMPL_H
