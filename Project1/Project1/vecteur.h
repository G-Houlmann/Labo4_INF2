/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : vecteur.h
 Auteur(s)   : LAMRANI Soulaymane, HOULMANN Gildas
 Date        : 11.04.2019

 Remarque(s) :

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef VECTEUR_H
#define VECTEUR_H
#include <vector>
#include <iostream>
#include "Exceptions.h"

template <typename T> class vecteur;

//Opérateur de flux affichant les données d'un vecteur entre crochets.
//L'opérateur de flux du type générique doit être défini.
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
	vecteur<T>();

	//Methodes

	//Obtient l'elément en Nème position du vecteur en reférence ou en 
	//reférence constante.
	T& at(unsigned n);
	const T& at(unsigned n) const;

	//Retourne la taille du vecteur
	unsigned size() const;

	//Modifie la taille du vecteur. Supprime les eléments si la taille
	//spécifiée est plus petite que la taille actuelle.
	void resize(unsigned n);

	//retourne la somme de tous les éléments du vecteur.
	T somme() const;

	//Surcharges d'operateurs

	//Multiplie chaque élément du vecteur par une valeur n.
	//L'opérateur * du type générique avec un entier doit être défini.
	vecteur<T> operator*(int n) const;

	//Multiplie deux vecteurs élément par élément.
	//L'opérateur * du type générique doit être défini.
	vecteur<T> operator*(const vecteur& v) const;

	//Additionne deux vecteurs élément par élément.
	//L'opérateur + du type générique doit être défini.
	vecteur<T> operator+(const vecteur& v) const;

	//Soustrait deux vecteurs élément par élément.
	//L'opérateur - du type générique doit être défini.
	vecteur<T> operator-(const vecteur& v) const;


private:
	std::vector<T> data; //vector contenant les données du vecteur
	size_t taille; //Taille du vecteur
};

#include "vecteurImpl.h"


#endif // !VECTEUR_H
