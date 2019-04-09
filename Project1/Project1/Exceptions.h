#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <string>
#include <stdexcept>
#include <exception>

class index_hors_limite : public std::logic_error {
public:
	explicit index_hors_limite(const std::string& s) : std::logic_error(s) {}
	explicit index_hors_limite(const char* s) : std::logic_error(s) {}
};

class taille_trop_haute : public std::logic_error {
public:
	explicit taille_trop_haute(const std::string& s) : std::logic_error(s) {}
	explicit taille_trop_haute(const char* s) : std::logic_error(s) {}
};

class taille_vecteurs_incompatibles : public std::logic_error {
public:
	explicit taille_vecteurs_incompatibles(const std::string& s) : std::logic_error(s) {}
	explicit taille_vecteurs_incompatibles(const char* s) : std::logic_error(s) {}
};

class matrice_taille_incompatible : public std::logic_error {
public:
	explicit matrice_taille_incompatible(const std::string& s) : std::logic_error(s) {}
	explicit matrice_taille_incompatible(const char* s) : std::logic_error(s) {}
};

class matrice_vide : public std::logic_error {
public:
	explicit matrice_vide(const std::string& s) : std::logic_error(s) {}
	explicit matrice_vide(const char* s) : std::logic_error(s) {}
};




#endif // !EXCEPTIONS_H
