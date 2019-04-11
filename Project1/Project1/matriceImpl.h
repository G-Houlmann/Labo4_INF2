/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Exceptions.h
 Auteur(s)   : LAMRANI Soulaymane, HOULMANN Gildas
 Date        : 11.04.2019

 Remarque(s) :

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
*/

#ifndef matriceIMPL_H
#define matriceIMPL_H
#include "matrice.h"

template <typename T>
matrice<T>::matrice() {
	l = 0;
	c = 0;
	vecteur<vecteur<T>> matrice(l, vecteur<T>(c));
	data = matrice;
}

template <typename T>
matrice<T>::matrice(unsigned l) {
	this->l = l;
	this->c = 0;
	try {
		vecteur<vecteur<T>> matrice(l);
		data = matrice;
	}
	catch (...) {
		throw taille_trop_haute("La taille de matrice specifiee est trop haute", __FILE__);
	}
}

template <typename T>
matrice<T>::matrice(unsigned l, unsigned c) {
	if (l != std::numeric_limits<unsigned>::max())
		this->l = l;
	else
		throw taille_trop_haute("La taille de matrice specifiee est trop haute", __FILE__);
	if (c != std::numeric_limits<unsigned>::max())
		this->c = c;
	else
		throw taille_trop_haute("La taille de matrice specifiee est trop haute", __FILE__);
	try {
		vecteur<T> vect(c);
		vecteur<vecteur<T>> matrice(l, vect);
		data = matrice;
	}
	catch (...) {
		throw taille_trop_haute("La taille de matrice specifiee est trop haute", __FILE__);
	}
}

template <typename T>
const vecteur<T>& matrice<T>::at(unsigned l) const {
	if (l >= this->l)
		throw index_hors_limite("Accès hors limite de la matrice.", __FILE__);
	return data.at(l);
}

template <typename T>
vecteur<T>& matrice<T>::at(unsigned l) {
	if (l >= this->l)
		throw index_hors_limite("Accès hors limite de la matrice.", __FILE__);
	return data.at(l);
}

template <typename T>
size_t matrice<T>::size() const {
	return l;
}

template <typename T>
size_t matrice<T>::sizeC() const {
	return c;
}

template <typename T>
void matrice<T>::resize(unsigned l) {
	if (l != std::numeric_limits<unsigned>::max()) {
		data.resize(l);
		this->l = l;
	}
	else
		throw taille_trop_haute("La taille de matrice specifiee est trop haute", __FILE__);

}

template <typename T>
void matrice<T>::resize(unsigned l, unsigned c) {
	if (l != std::numeric_limits<unsigned>::max()) {
		data.resize(l);
		this->l = l;
		if (c != std::numeric_limits<unsigned>::max()) {
			for (unsigned i = 0; i < l; i++) {
				data.at(i).resize(c);
			}
			this->c = c;
		}
		else
			throw taille_trop_haute("La taille de matrice specifiee est trop haute", __FILE__);
	}
	else
		throw taille_trop_haute("La taille de matrice specifiee est trop haute", __FILE__);
}

template <typename T>
bool matrice<T>::estVide() const {
	return !(l || c);
}

template <typename T>
bool matrice<T>::estCarree() const {
	return (l == c);
}

template <typename T>
bool matrice<T>::estReguliere() const {
	for (unsigned i = 1; i < l; i++) {
		if (this->at(i).size() != this->at(i - 1).size())
			return false;
	}
	return true;
}

template <typename T>
vecteur<T> matrice<T>::sommeLigne() const {
	vecteur<T> output(l);
	if (!this->estVide()) {
		for (unsigned i = 0; i < l; i++) {
			T somme = 0;
			for (unsigned j = 0; j < c; j++) {
				somme += this->at(i).at(j);
			}
			output.at(i) = somme;
		}
	}
	else {
		throw matrice_vide("La matrice ne doit pas être vide pour calculer la somme des lignes", __FILE__);
	}
	return output;
}

template <typename T>
vecteur<T> matrice<T>::sommeColonne() const {
	vecteur<T> output(c);
	if (!this->estVide()) {
		for (unsigned i = 0; i < c; i++) {
			T somme = 0;
			for (unsigned j = 0; j < l; j++) {
				somme += this->at(j).at(i);
			}
			output.at(i) = somme;
		}
	}
	else {
		throw matrice_vide("La matrice ne doit pas être vide pour calculer la somme des colonnes", __FILE__);
	}
	return output;
}

template <typename T>
T matrice<T>::sommeDiagonaleGD() const {
	T somme = 0;
	if (this->estCarree() && !this->estVide()) {
		for (unsigned i = 0; i < l; i++) {
			for (unsigned j = 0; i < c; j++) {
				if (i == j)
					somme += this->at(i).at(j);
			}
		}
	}
	else {
		throw matrice_taille_incompatible("La matrice doit être carrée pour calculer sa diagonale", __FILE__);
	}
	return somme;
}

template <typename T>
T matrice<T>::sommeDiagonaleDG() const {
	T somme = 0;
	if (this->estCarree() && !this->estVide()) {
		for (int i = l - 1; i >= 0; i--) {
			for (int j = c - 1; j >= 0; j--) {
				somme += this->at(i).at(j);
			}
		}
	}
	else {
		throw matrice_taille_incompatible("La matrice doit être carrée pour calculer sa diagonale", __FILE__);
	}
	return somme;
}

template <typename T>
matrice<T> matrice<T>::operator*(int s) const {
	for (unsigned i = 0; i < l; i++) {
		for (unsigned j = 0; j < c; j++) {
			s * this->at(i).at(j);
		}
	}
}

template <typename T>
matrice<T> matrice<T>::operator*(matrice<T> m) const {
	matrice<T> result = m;
	if (l == m.size()) {
		for (unsigned i = 0; i < l; i++) {
			if (this->at(i).size() == m.at(i).size()) {
				for (unsigned j = 0; j < c; j++) {
					result.at(i).at(j) = this->at(i).at(j) * m.at(i).at(j);
				}
			}
			else {
				throw matrice_taille_incompatible("Taille des matrices incompatibles", __FILE__);
			}
		}
	}
	else {
		throw matrice_taille_incompatible("Taille des matrices incompatibles", __FILE__);
	}
	return result;
}

template <typename T>
matrice<T> matrice<T>::operator+(matrice<T> m) const {
	matrice<T> result = m;
	if (l == m.size()) {
		for (unsigned i = 0; i < l; i++) {
			if (this->at(i).size() == m.at(i).size()) {
				for (unsigned j = 0; j < c; j++) {
					result.at(i).at(j) = this->at(i).at(j) + m.at(i).at(j);
				}
			}
			else {
				throw matrice_taille_incompatible("Taille des matrices incompatibles", __FILE__);
			}
		}
	}
	else {
		throw matrice_taille_incompatible("Taille des matrices incompatibles", __FILE__);
	}
	return result;
}

#endif // !matriceIMPL_H