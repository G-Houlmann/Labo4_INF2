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

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <string>
#include <stdexcept>
#include <exception>

//Exception indiquant que l'utilisateur a tent� d'acc�der � un �l�ment inaccessible
class index_hors_limite : public std::logic_error {
public:
	explicit index_hors_limite(const std::string& s, const std::string& className)
		: std::logic_error(className + ": " + s) {}
	explicit index_hors_limite(const char* s, const std::string& className)
		: std::logic_error(className + ": " + s) {}
};

//Exceptions indiquant que l'utilisateur a tent� d'initialiser ou de resize
//un vecteur avec une taille trop haute
class taille_trop_haute : public std::logic_error {
public:
	explicit taille_trop_haute(const std::string& s, const std::string& className)
		: std::logic_error(className + ": " + s) {}
	explicit taille_trop_haute(const char* s, const std::string& className)
		: std::logic_error(className + ": " + s) {}
};

//Exception indiquant qu'une op�ration n�c�ssitant 2 vecteurs de m�me 
//taille a �t� tent�e sur 2 vecteurs de tailles diff�rentes
class taille_vecteurs_incompatibles : public std::logic_error {
public:
	explicit taille_vecteurs_incompatibles
	(const std::string& s, const std::string& className)
		: std::logic_error(className + ": " + s) {}
	explicit taille_vecteurs_incompatibles
	(const char* s, const std::string& className)
		: std::logic_error(className + ": " + s) {}
};

//Exception indiquant qu'une op�ration n�c�ssitant 2 matrices de m�me 
//taille a �t� tent�e sur 2 matrices de tailles diff�rentes
class matrice_taille_incompatible : public std::logic_error {
public:
	explicit matrice_taille_incompatible
	(const std::string& s, const std::string& className)
		: std::logic_error(className + ": " + s) {}
	explicit matrice_taille_incompatible
	(const char* s, const std::string& className)
		: std::logic_error(className + ": " + s) {}
};

//Exception indiquant qu'une op�ration ne supportant pas les 
//matrices vides a �t� tent�e sur une matrice vide
class matrice_vide : public std::logic_error {
public:
	explicit matrice_vide(const std::string& s, const std::string& className)
		: std::logic_error(className + ": " + s) {}
	explicit matrice_vide(const char* s, const std::string& className)
		: std::logic_error(className + ": " + s) {}
};




#endif // !EXCEPTIONS_H
