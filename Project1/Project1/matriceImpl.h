#ifndef matriceIMPL_H
#define matriceIMPL_H
#include "matrice.h"

Matrice<T>::Matrice<T>() {
    
}

template <typename T>
const vecteur<T>& Matrice<T>::at(unsigned l) const {
    return data.at(l);
}

template <typename T>
vecteur<T>& Matrice<T>::at(unsigned l) {
    return data.at(l);
}

template <typename T>
size_t Matrice<T>::size() {
    return l;
}

template <typename T>
T Matrice<T>::resize(unsigned l) {
    
}

template <typename T>
bool Matrice<T>::estVide() const {
    return !(l || c);
}

template <typename T>
bool Matrice<T>::estCarree() const {
    return (l == c);
}

template <typename T>
bool Matrice<T>::estReguliere() const {
    for (unsigned i = 1; i < l; i++) {
        if (data.at(i),size() != data.at(i - 1).size())
            return false;
    }
    return true;
}

template <typename T>
vecteur<T> Matrice<T>::sommeLigne() const {
    vecteur<T> output;
    for (unsigned i = 0; i < l; i++) {
        T somme = 0;
        for (unsigned j = 0; j < c; j++) {
            somme += data.at(i).at(j);
        }
        output.push_back(somme);
    }
    return output;
}

template <typename T>
vecteur<T> Matrice<T>::sommeColonne() const {
    vecteur<T> output;
    for (unsigned i = 0; i < c; i++) {
        T somme = 0;
        for (unsigned j = 0; j < l; j++) {
            somme += data.at(i).at(j);
        }
        output.push_back(somme);
    }
    return output;
}

template <typename T>
T Matrice<T>::sommeDiagonaleGD() const {
    T somme = 0;
    for (unsigned i = 0; i < l; i++) {
        for (unsigned j = 0; i < c; j++) {
            if (i == j)
                somme += data.at(i).at(j);
        }
    }
    return somme;
}

template <typename T>
T Matrice<T>::sommeDiagonaleDG() const {
    T somme = 0;
    for (int i = l - 1; i >= 0; i--) {
        for (int j = c - 1; j >= 0; j--) {
            somme += data.at(i).at(j);
        }
    }
    return somme;
}

template <typename T>
ostream& Matrice<T>::opreator<< <T>(ostream& os; const Matrice<T>& m) {
    os << "[";
    for (unsigned i = 0; i < l; i++) {
        os << "[";
        for unsigned j = 0; j < c; j++) {
            os << data.at(i).at(j);
            if (j == c - 1)
                os << ", ";
        }
        os << "]";
        if (i == l - 1)
            os << ", ";
    }
    os << "]";
    return os;
}

template <typename TY
Matrice<T> Matrice<T>::operator*(int s) const {
    for (unsigned i = 0; i < l; i++) {
        for (unsigned j = 0; j < c; j++) {
            s * data.at(i).at(j);
        }
    }
}

template <typenmae T>
Matrice<T> Matrice<T>::operator*(Matrice<T> m) const {}

template <typename T>
Matrice<T> Matrice<T>::operator+(Matrice<T> m) const {
    Matrice<T> result = m;
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
