#include "../hpp/Vector.hpp"
//#include "../hpp/Complex.hpp"
#include <fstream>
#include <stdexcept>
#include <cmath>
#include <iostream>
using namespace std;

// Constructor
template <typename T>
Vector<T>::Vector(int tag, int size) : tag(tag), size(size), data(new T[size]()) {}

// Copy Constructor
template <typename T>
Vector<T>::Vector(const Vector& other) : tag(other.tag), size(other.size), data(new T[other.size]) {
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

// Destructor
template <typename T>
Vector<T>::~Vector() {
    delete[] data;
}

// Accessors
template <typename T>
int Vector<T>::Tag() const {
    return tag;
}

template <typename T>
int Vector<T>::Size() const {
    return size;
}

// File I/O
template <typename T>
void Vector<T>::readFromFile(const std::string& filename) {
    FILE* file = fopen(filename.c_str(), "r");
    if (!file) {
        throw runtime_error("Impossible d'ouvrir le fichier.");
    }

    int type, rows, cols;
    fscanf(file, "%d", &type);
    fscanf(file, "%d %d", &rows, &cols);

    if (type < 0 || type > 2 || rows <= 0 || cols <= 0 || cols != 1) {
        fclose(file);
        throw invalid_argument("Type ou dimensions de vecteur invalides.");
    }

    if ((is_same<T, double>::value && type != 1) ||
        (is_same<T, float>::value && type != 0)) {
        fclose(file);
        throw invalid_argument("Type de vecteurs et type dans le fichier incompatibles.");
    }

    tag = type;
    size = rows;
    data = new T[size];

    for (int i = 0; i < rows; i++) {
        //if constexpr (is_same<T, Complex>::value) {
            //double real, imag;
            //fscanf(file, "%lf %lf", &real, &imag);
            //data[i] = Complex(real, imag);
        //} else 
        if constexpr (is_same<T, double>::value) {
            double value;
            fscanf(file, "%lf", &value);
            data[i] = static_cast<T>(value);
        } else if constexpr (is_same<T, float>::value) {
            float value;
            fscanf(file, "%f", &value);
            data[i] = static_cast<T>(value);
        } else {
            fclose(file);
            throw invalid_argument("Type non supporté dans readFromFile.");
        }
    }

    fclose(file);
}

template <typename T>
void Vector<T>::writeToFile(const std::string& filename) const {
    FILE* file = fopen(filename.c_str(), "w");
    if (!file) {
        throw runtime_error("Impossible d'ouvrir le fichier.");
    }

    fprintf(file, "%d\n%d %d\n", tag, size, 1);

    for (int i = 0; i < size; i++) {
        //if constexpr (is_same<T, Complex>::value) {
            //fprintf(file, "%lf %lf\n", data[i].Real(), data[i].Imag());
        //} else 
        if constexpr (is_same<T, double>::value) {
            fprintf(file, "%lf\n", data[i]);
        } else if constexpr (is_same<T, float>::value) {
            fprintf(file, "%f\n", data[i]);
        } else {
            fclose(file);
            throw invalid_argument("Type non supporté dans writeToFile.");
        }
    }

    fclose(file);
}

// Vector Operations
template <typename T>
Vector<T> Vector<T>::operator+(const Vector& other) const {
    if (size != other.size) {
        throw invalid_argument("Les vecteurs doivent avoir la même taille pour l'addition.");
    }
    Vector result(tag, size);
    for (int i = 0; i < size; ++i) {
        result.data[i] = data[i] + other.data[i];
    }
    return result;
}

template <typename T>
Vector<T> Vector<T>::operator-(const Vector& other) const {
    if (size != other.size) {
        throw invalid_argument("Les vecteurs doivent avoir la même taille pour la soustraction.");
    }
    Vector result(tag, size);
    for (int i = 0; i < size; ++i) {
        result.data[i] = data[i] - other.data[i];
    }
    return result;
}

template <typename T>
Vector<T> Vector<T>::operator*(T scalar) const {
    Vector result(tag, size);
    for (int i = 0; i < size; ++i) {
        result.data[i] = data[i] * scalar;
    }
    return result;
}

template <typename T>
Vector<T>& Vector<T>::operator+=(const Vector& other) {
    if (size != other.size) {
        throw invalid_argument("Les vecteurs doivent avoir la même taille pour l'addition.");
    }
    for (int i = 0; i < size; ++i) {
        data[i] += other.data[i];
    }
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator-=(const Vector& other) {
    if (size != other.size) {
        throw invalid_argument("Les vecteurs doivent avoir la même taille pour la soustraction.");
    }
    for (int i = 0; i < size; ++i) {
        data[i] -= other.data[i];
    }
    return *this;
}

// Dot Product
template <typename T>
T Vector<T>::dot(const Vector<T>& other) const {
    if (size != other.Size()) {
        throw invalid_argument("Les vecteurs doivent avoir la même taille pour le produit scalaire.");
    }

    T result = 0;
    for (int i = 0; i < size; ++i) {
        //if constexpr (is_same<T, Complex>::value) {
            //result += data[i] * other[i].conjugate();
        //} else {
            result += data[i] * other[i];
        //}
    }
    return result;
}

// Assignment and Access
template <typename T>
void Vector<T>::swap_elements(int i, int j) {
    if (i < 0 || j < 0 || i >= size || j >= size) {
        throw out_of_range("L'indice est hors limites.");
    }
    swap(data[i], data[j]);
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
    if (this != &other) {
        delete[] data;
        tag = other.tag;
        size = other.size;
        data = new T[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template <typename T>
T& Vector<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("L'indice est hors limites.");
    }
    return data[index];
}

template <typename T>
const T& Vector<T>::operator[](int index) const {
    if (index < 0 || index >= size) {
        throw out_of_range("L'indice est hors limites.");
    }
    return data[index];
}

// Stream Operator
template <typename T>
ostream& operator<<(ostream& out, const Vector<T>& v) {
    out << endl;
    for (int i = 0; i < v.Size(); ++i) {
        out << v.data[i] << endl;
    }
    return out;
}

// Friend Functions
template <typename T>
double abs(const Vector<T>& v) {
    double result = 0;
    for (int i = 0; i < v.Size(); ++i) {
        result += abs(v[i]);
    }
    return sqrt(result);
}
