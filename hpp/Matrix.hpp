#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "../hpp/Vector.hpp"
using namespace std;

template <typename T>
class Matrix {
    private:
        int tag;
        int size;
        T **data;

    public:        
        // Constructeurs et destructeur
        Matrix(int tag = 0, int size = 1);
        Matrix(const Matrix &M);
        ~Matrix();

        // Méthodes d'accès
        int Size() const;
        int Tag() const;

        // Affichage et lecture/écriture
        void readFromFile(const std::string& filename);
        void writeToFile(const std::string& filename) const;

        // Décomposition de matrices
        //template <typename S>
        //void DecomposeLU(Matrix<S>& L, Matrix<S>& U, S& det) const;

        //template <typename S>
        //void GaussElimination(Matrix<S>& RedForm, Vector<T>& b, Vector<S>& Redb, S& det) const;

        //template <typename S>
        //void DecomposeCholesky(Matrix<S> &L, S &det) const;

        // Propriétés de la matrice
        Matrix Transpose() const;
        //Matrix Conjugate() const;
        Matrix principalMinor(int k) const;
        T determinant() const;
        //bool IsHermitian() const;
        bool IsPositiveDefinite() const;
        bool IsInvertible() const;
        bool nonZeroPrincipalMinors() const;

        // Opérateurs arithmétiques
        Matrix operator+(const Matrix &M) const;
        Matrix operator-(const Matrix &M) const;
        Matrix operator*(const Matrix &M) const;
        Vector<T> productVector(const Vector<T>& V) const;
        Matrix<T> operator*(T scalar) const;

        // Opérateur d'affectation
        Matrix& operator=(const Matrix &M);

        // Accès et manipulation des données
        T& operator[](int i);
        T& operator()(int i, int j);
        const T& operator()(int i, int j) const;
        void swapRows(int i, int j);

        template <typename U>
        friend ostream& operator<<(ostream& out, const Matrix<U>& M);
};

#include "../cpp/Matrix.cpp"
#endif
