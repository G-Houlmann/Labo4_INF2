#ifndef matriceIMPL_H
#define matriceIMPL_H
#include "matrice.h"

template <typename T>
matrice<T>::matrice() {
    l = 0;
    c = 0;
    data(l, std::vector<T> (c));
}

template <typename T>
matrice<T>::matrice(unsigned l) {
    this->l = l;
    this->c = 0;
    data = std::vector<std::vector<T>>(l);
}

template <typename T>
matrice<T>::matrice(unsigned l, unsigned c) {
    this->l = l;
    this->c = c;
    data(l, std::vector<T> (c));
}

template <typename T>
const vecteur<T>& matrice<T>::at(unsigned l) const {
    return data.at(l);
}

template <typename T>
vecteur<T>& matrice<T>::at(unsigned l) {
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
    data.resize(l);
    this->l = l;
}

template <typename T>
void matrice<T>::resize(unsigned l, unsigned c) {
    data.resize(l).resize(c);
    this->l = l;
    this->c = c;
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
        if (data.at(i),size() != data.at(i - 1).size())
            return false;
    }
    return true;
}

template <typename T>
vecteur<T> matrice<T>::sommeLigne() const {
    vecteur<T> output;
    for (unsigned i = 0; i < l; i++) {
        T somme = 0;
        for (unsigned j = 0; j < c; j++) {
            somme += this->at(i).at(j);
        }
        output.push_back(somme);
    }
    return output;
}

template <typename T>
vecteur<T> matrice<T>::sommeColonne() const {
    vecteur<T> output;
    for (unsigned i = 0; i < this->c; i++) {
        T somme = 0;
        for (unsigned j = 0; j < this->l; j++) {
            somme += this->at(i).at(j);
        }
        output.push_back(somme);
    }
    return output;
}

template <typename T>
T matrice<T>::sommeDiagonaleGD() const {
    T somme = 0;
    for (unsigned i = 0; i < l; i++) {
        for (unsigned j = 0; i < c; j++) {
            if (i == j)
                somme += this->at(i).at(j);
        }
    }
    return somme;
}

template <typename T>
T matrice<T>::sommeDiagonaleDG() const {
    T somme = 0;
    for (int i = l - 1; i >= 0; i--) {
        for (int j = c - 1; j >= 0; j--) {
            somme += this->at(i).at(j);
        }
    }
    return somme;
}

/*template <typename T>
std::ostream& operator<< <T>(std::ostream& os, const matrice<T>& m) {
    size_t l = m.size();
    size_t c = m.sizeC();
    os << "[";
    for (unsigned i = 0; i < l; i++) {
        os << "[";
        for (unsigned j = 0; j < c; j++) {
            os << m.at(i).at(j);
            if (j == c - 1)
                os << ", ";
        }
        os << "]";
        if (i == l - 1)
            os << ", ";
    }
    os << "]";
    return os;
}*/

template <typename T>
matrice<T> matrice<T>::operator*(int s) const {
    for (unsigned i = 0; i < l; i++) {
        for (unsigned j = 0; j < c; j++) {
            s * data.at(i).at(j);
        }
    }
}

template <typename T>
matrice<T> matrice<T>::operator*(matrice<T> m) const {
    matrice<T> result = m;
    if (l == m.size()) {
        for (unsigned i = 0; i < l; i++) {
            for (unsigned j = 0; j < c; j++) {
                result.at(i).at(j) = this->at(i).at(j) * m.at(i).at(j);
            }
        }
    }
    return result;
}

template <typename T>
matrice<T> matrice<T>::operator+(matrice<T> m) const {
    matrice<T> result = m;
    if (l == m.size()) {
        for (unsigned i = 0; i < l; i++) {
            for (unsigned j = 0; j < c; j++) {
                result.at(i).at(j) = this->at(i).at(j) + m.at(i).at(j);
            }
        }
    }
    return result;
}

#endif // !matriceIMPL_H
