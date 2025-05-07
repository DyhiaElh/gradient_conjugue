#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <fstream>
using namespace std;

template <typename T>
class Vector {
private:
    int tag;
    int size;
    T* data;

public:
    // Constructeurs et destructeur
    Vector(int tag = 0, int size = 1);
    Vector(const Vector& other);
    ~Vector();

    // Accesseurs
    int Tag() const;
    int Size() const;

    // Méthodes de lecture et écriture de fichier
    void readFromFile(const std::string& filename);
    void writeToFile(const std::string& filename) const;

    // Opérateurs arithmétiques
    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    Vector operator*(T scalar) const;

    // Opérateurs d'affectation arithmétique
    Vector& operator+=(const Vector& other);
    Vector& operator-=(const Vector& other);

    // Produit scalaire
    T dot(const Vector<T>& other) const;

    // Méthode pour échanger des éléments
    void swap_elements(int i, int j);

    // Opérateur d'accés
    Vector& operator=(const Vector& other);
    T& operator[](int index);
    const T& operator[](int index) const;

    // Fonctions friend
    template <typename U>
    friend ostream& operator<<(ostream&, const Vector<U>&);

    template <typename U>
    friend double abs(const Vector<U>&);
};

#include "../cpp/Vector.cpp"
#endif
