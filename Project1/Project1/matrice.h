#ifndef matrice_H
#define matrice_H
#include "vecteur.h"

template <typename T> class matrice;

template <typename T>
std::ostream& operator<< (std::ostream& os, const matrice<T>& m) {
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
}

template <typename T>
class matrice {
    friend std::ostream& operator<< <T>(std::ostream& os, const matrice<T>& m);

    public:
        matrice<T>();
        matrice<T>(unsigned l);
        matrice<T>(unsigned l, unsigned c);
        matrice<T> operator*(int s) const;
        matrice<T> operator*(matrice<T> m) const;
        matrice<T> operator+(matrice<T> m) const;

        vecteur<T>& at(unsigned l);
        const vecteur<T>& at(unsigned l) const;
        size_t size() const;
        size_t sizeC() const;
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
        vecteur<vecteur <T>> data = vecteur<vecteur<T>> (0, vecteur<T>(0));
};


#include "matriceImpl.h"
#endif // !matrice_H
