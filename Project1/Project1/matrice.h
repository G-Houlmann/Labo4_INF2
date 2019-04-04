#ifndef matrice_H
#define matrice_H
#include "vecteur.h"

template <typename T>
class Matrice {
    friend std::ostream& operator<<(ostream& os, const Matrice& m);

    public:
        Matrice<T>() {}
        Matrice<T>(unsigned l) : l(l), c(0) {}
        Matrice<T>(unsigned l, unsigned c) : l(l), c(c) {}
        Matrice<T> operator*(int v) const;
        Matrice<T> operator*(Matrice m) const;
        Matrice<T> operator+(Matrice m) const;

        vecteur<T> at(unsigned l) const;
        unsigned size() const;
        void resize(unsigned l);
        void resize(unsigned l, unsigned c);
        bool estVide() const;
        bool estCarree() const;
        bool estReguliere() const;
        vecteur<T> sommeLigne() const;
        vecteur<T> sommeColonne() const;
        T sommeDiagonaleGD() const;
        T sommeDiagonaleDG() const;

    private:
        unsigned l;
        unsigned c;
        vecteur<vecteur <T>> data;
}


#include "matriceImpl.h"
#endif // !matrice_H
