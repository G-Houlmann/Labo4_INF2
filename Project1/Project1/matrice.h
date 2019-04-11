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

#ifndef matrice_H
#define matrice_H
#include "vecteur.h"
#include <limits>

template <typename T> class matrice;

/**
 * @brief modifie l'opérateur de flux de sortie pour l'affichage de la matrice
 * @param os : flux de sortie
 * @param m : matrice à afficher
 */
template <typename T>
std::ostream& operator<< (std::ostream& os, const matrice<T>& m) {
	size_t l = m.size();
	size_t c = m.sizeC();
	os << "[";
	for (unsigned i = 0; i < l; i++) {
		os << "[";
		for (unsigned j = 0; j < c; j++) {
			os << m.at(i).at(j);
			if (j != c - 1) os << ", ";
		}
		os << "]";
		if (i != l - 1) os << ", ";
	}
	os << "]";
	return os;
}

template <typename T>
class matrice {
	friend std::ostream& operator<< <T>(std::ostream& os, const matrice<T>& m);

public:
	/**
	 * @brief Constructeur de matrice par défaut. Met le nombre de lignes et de 
	 * colonnes à 0.
	 */
	matrice<T>();

	/**
	 * @brief Constructeur de matrice
	 * @param l : nombre de lignes
	 */
	matrice<T>(unsigned l);

    /**
     * @brief Constructeur de matrice
     * @param l : nombre de lignes
     * @param c : nombre de colonnes
     */
	matrice<T>(unsigned l, unsigned c);

	/**
	 * @brief Modification de l'opérateur de multiplication
	 * @param s : scalaire par lequel faire la multiplication de la matrice
	 * @return : matrice multipliée par un scalaire
	 */
	matrice<T> operator*(T s) const;

	/**
	 * @brief Modification de l'opérateur de multiplication
	 * @param m : matrice par laquelle effetuer la multiplication selon
	 * [[a*b], [c*d, e*f]], donc cellule par cellule
	 * @return : matrice multipliée par une autre
	 */
	matrice<T> operator*(matrice<T> m) const;

	/**
	 * @brief Modification de l'opérateur d'addition
	 * @param m : matrice par laquelle effetuer l'addition selon
	 * [[a*b], [c*d, e*f]], donc cellule par cellule
	 * @return : matrice additionnée par une autre
	 */
	matrice<T> operator+(matrice<T> m) const;

	/**
	 * @brief accès à un vecteur de matrice en écriture
	 * @param l : ligne de la matrice à accéder
	 * @return vecteur de la matrice
	 */
	vecteur<T>& at(unsigned l);

	/**
	 * @brief accès à un vecteur de matrice en lecture
	 * @param l : ligne de la matrice à accéder
	 * @return vecteur de la matrice
	 */
	const vecteur<T>& at(unsigned l) const;

	/**
	 * @brief Retourne le nombre de lignes de la matrice
	 */
	size_t size() const;

	/**
	 * @brief Retourne le nombre de colonnes de la matrice
	 */
	size_t sizeC() const;

    /**
     * @brief modifie le nombre de lignes de la matrice
     */
	void resize(unsigned l);

    /**
     * @brief modifie le nombre de lignes et de colonnes de la matrice
     */
	void resize(unsigned l, unsigned c);

	/**
	 * @brief vérifie que la matrice est vide
	 */
	bool estVide() const;

	/**
	 * @brief vérifie que la matrice est carrée
	 */
	bool estCarree() const;

	/**
	 * @brief vérifie que la matrice est régulière
	 */
	bool estReguliere() const;

    /**
     * @brief effectue la somme des lignes d'une matricevide
     * @return un vecteur contenant la somme de chaque ligne
     */
	vecteur<T> sommeLigne() const;

    /**
     * @brief effectue la somme des colonnes d'une matricevide
     * @return un vecteur contenant la somme de chaque colonne
     */
	vecteur<T> sommeColonne() const;

	/**
	 * @brief effectue la somme de la diagonale gauche à droite d'une matrice carrée
	 */
	T sommeDiagonaleGD() const;

	/**
	 * @brief effectue la somme de la diagonale droite à gauche d'une matrice carrée
	 */
	T sommeDiagonaleDG() const;

private:
    // lignes de la matrice
	unsigned l;

	// colonnes de la matrice
	unsigned c;

	// contenu de la matrice constitué d'un vecteur de vecteurs
	vecteur<vecteur <T>> data = vecteur<vecteur<T>>(0, vecteur<T>(0));
};


#include "matriceImpl.h"
#endif // !matrice_H