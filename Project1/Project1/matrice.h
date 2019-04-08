#ifndef matrice_H
#define matrice_H
#include "vecteur.h"

template <typename T>
class Matrice {
    friend std::ostream& operator<< <T>(ostream& os, const Matrice<T>& m);

    public:
        Matrice<T>(unsigned l) : l(l), c(0) {}
        Matrice<T>(unsigned l, unsigned c) : l(l), c(c) {}
        Matrice<T> operator*(int s) const;
        Matrice<T> operator*(Matrice<T> m) const;
        Matrice<T> operator+(Matrice<T> m) const;

        vecteur<T>& at(unsigned l);
        const vecteur<T>& at(unsigned l) const;
        size_t size() const;
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
