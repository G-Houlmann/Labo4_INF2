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

//Op�rateur de flux affichant les donn�es d'un vecteur entre crochets.
//L'op�rateur de flux du type g�n�rique doit �tre d�fini.
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

	//Obtient l'el�ment en N�me position du vecteur en ref�rence ou en 
	//ref�rence constante.
	T& at(unsigned n);
	const T& at(unsigned n) const;

	//Retourne la taille du vecteur
	unsigned size() const;

	//Modifie la taille du vecteur. Supprime les el�ments si la taille
	//sp�cifi�e est plus petite que la taille actuelle.
	void resize(unsigned n);

	//retourne la somme de tous les �l�ments du vecteur.
	T somme() const;

	//Surcharges d'operateurs

	//Multiplie chaque �l�ment du vecteur par une valeur n.
	//L'op�rateur * du type g�n�rique avec un entier doit �tre d�fini.
	vecteur<T> operator*(int n) const;

	//Multiplie deux vecteurs �l�ment par �l�ment.
	//L'op�rateur * du type g�n�rique doit �tre d�fini.
	vecteur<T> operator*(const vecteur& v) const;

	//Additionne deux vecteurs �l�ment par �l�ment.
	//L'op�rateur + du type g�n�rique doit �tre d�fini.
	vecteur<T> operator+(const vecteur& v) const;

	//Soustrait deux vecteurs �l�ment par �l�ment.
	//L'op�rateur - du type g�n�rique doit �tre d�fini.
	vecteur<T> operator-(const vecteur& v) const;


private:
	std::vector<T> data; //vector contenant les donn�es du vecteur
	size_t taille; //Taille du vecteur
};

#include "vecteurImpl.h"


#endif // !VECTEUR_H
