#include "../hpp/Matrix.hpp"
//#include "../hpp/Rational.hpp"
#include <fstream>
#include <cstdio>
using namespace std;

// Constructeurs et destructeur
template <typename T>
Matrix<T>::Matrix(int tag, int size) : tag(tag), size(size) {
    data = new T*[size];
    for (int i = 0; i < size; i++) {
        data[i] = new T[size];
        for (int j = 0; j < size; j++) {
            data[i][j] = 0;
        }
    }
}

template <typename T>
Matrix<T>::Matrix(const Matrix &M) : tag(M.tag), size(M.size) {
    data = new T*[size];
    for (int i = 0; i < size; i++) {
        data[i] = new T[size];
        for (int j = 0; j < size; j++) {
            data[i][j] = M.data[i][j];
        }
    }
}

template <typename T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < size; i++) {
        delete[] data[i];
    }
    delete[] data;
}

// Méthodes d'accès
template <typename T>
int Matrix<T>::Size() const {
    return size;
}

template <typename T>
int Matrix<T>::Tag() const {
    return tag;
}

template <typename T>
void Matrix<T>::readFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        throw runtime_error("Impossible d'ouvrir le fichier.");
    }

    int type, rows, cols;
    fscanf(file, "%d", &type);
    fscanf(file, "%d %d", &rows, &cols);

    if (type < 0 || type > 2 || rows <= 0 || cols <= 0 || rows != cols) {
        fclose(file);
        throw invalid_argument("Type ou dimensions de matrice invalides.");
    }

    if ((is_same<T, double>::value && type != 1) ||
        (is_same<T, float>::value && type != 0)) {
        fclose(file);
        throw invalid_argument("Type de matrice et type dans le fichier incompatibles.");
    }

    size = cols;
    tag = type;

    data = new T*[size];
    for (int i = 0; i < size; ++i) {
        data[i] = new T[size];
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            //if constexpr (is_same<T, Complex>::value) {
                //double real, imag;
                //fscanf(file, "%lf %lf", &real, &imag);
                //data[i][j] = Complex(real, imag);
            //} else 
            if constexpr (is_same<T, double>::value) {
                double value;
                fscanf(file, "%lf", &value);
                data[i][j] = (T)(value);
            } else if constexpr (is_same<T, float>::value) {
                float value;
                fscanf(file, "%f", &value);
                data[i][j] = (T)(value);
            } else {
                fclose(file);
                throw invalid_argument("Type non supporté dans readFromFile.");
            }
        }
    }

    fclose(file);
}

template <typename T>
void Matrix<T>::writeToFile(const char *filename) const {
    FILE* file = fopen(filename, "w");
    if (!file) {
        throw runtime_error("Impossible d'ouvrir le fichier.");
    }

    fprintf(file, "%d\n", tag);
    fprintf(file, "%d %d\n", size, size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            //if constexpr (is_same<T, Complex>::value) {
                //fprintf(file, "%lf %lf  ", data[i][j].Real(), data[i][j].Imag());
            //}
            //else 
            if constexpr (is_same<T, double>::value) {
                fprintf(file, "%lf ", data[i][j]);
            }
            else if constexpr (is_same<T, float>::value) {
                fprintf(file, "%d ", data[i][j]);
            } 
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

// Décomposition de matrices
//template <typename T>
//template <typename S>
//void Matrix<T>::DecomposeLU(Matrix<S>& L, Matrix<S>& U, S& det) const {
    //if (!(is_same<T, S>::value || (is_same<T, int>::value && is_same<S, Rational>::value))) {
        //throw invalid_argument(
            //"Paramètres de template invalides pour la décomposition LU. "
            //"S attendu == T ou T == int et S == Rational."
        //);
    //}

    //if (size != L.Size() || size != U.Size()) {
        //throw invalid_argument("Les tailles des matrices ne correspondent pas pour la décomposition LU.");
    //}

    //if (!nonZeroPrincipalMinors()) {
        //throw runtime_error("La matrice n'a pas de décomposition LU.");
    //}

    //det = 1;

    //for (int i = 0; i < size; i++) {
        //L(i, i) = 1;

        //for (int j = i; j < size; j++) {
            //S sum(0);
            //for (int k = 0; k < i; k++) {
                //sum += L(i, k) * U(k, j);
            //}
            //U(i, j) = S((*this)(i, j)) - sum;
        //}

        //for (int j = i + 1; j < size; j++) {
            //S sum(0);
            //for (int k = 0; k < i; k++) {
                //sum += L(j, k) * U(k, i);
            //}
            //L(j, i) = (S((*this)(j, i)) - sum) / U(i, i);
        //}

        //det *= U(i, i);
    //}
//}

//template <typename T>
//template <typename S>
//void Matrix<T>::GaussElimination(Matrix<S>& RedForm, Vector<T>& b, Vector<S>& Redb, S& det) const {
    //// Valider les paramètres de template
    //if (!(is_same<T, S>::value || (is_same<T, int>::value && is_same<S, Rational>::value))) {
        //throw invalid_argument(
            //"Paramètres de template invalides pour l'élimination de Gauss. "
            //"S attendu == T ou T == int et S == Rational."
        //);
    //}

    //if (size != RedForm.Size() || size != Redb.Size()) {
        //throw invalid_argument("Les tailles des matrices ne correspondent pas pour l'élimination de Gauss.");
    //}

    //// Copier la matrice et le vecteur
    //int size = RedForm.Size();
    //int tag;
    //if constexpr (is_same<S, Rational>::value || is_same<S, int>::value) {
        //tag = 0;
    //} else if constexpr (is_same<S, double>::value) {
        //tag = 1;
    //} else if constexpr (is_same<S, Complex>::value) {
        //tag = 2;
    //} else {
        //throw invalid_argument("Paramètre de template invalide pour l'élimination de Gauss.");
    //}

    //RedForm = Matrix<S>(tag, size);
    //Redb = Vector<S>(tag, size);
    //for (int i = 0; i < size; i++) {
        //for (int j = 0; j < size; j++) {
            //RedForm(i, j) = (*this)(i, j);
        //}
        //Redb[i] = b[i];
    //}

    //det = 1;

    //for (int i = 0; i < size; i++) {
        //if (RedForm(i, i) == 0) {
            //bool swapped = false;
            //for (int j = i + 1; j < size; j++) {
                //if (RedForm(j, i) != 0) {
                    //RedForm.swapRows(i, j);
                    //swap(Redb[i], Redb[j]);
                    //det = det*(-1);
                    //swapped = true;
                    //break;
                //}
            //}
            //if (!swapped) {
                //det = 0;
                //return;
            //}
        //}

        //S pivot = RedForm(i, i);
        //det *= pivot;

        //for (int k = i; k < size; k++) {
            //RedForm(i, k) /= pivot;
        //}
        //Redb[i] /= pivot;

        //for (int j = i + 1; j < size; j++) {
            //S factor = RedForm(j, i);
            //for (int k = i; k < size; k++) {
                //RedForm(j, k) -= factor * RedForm(i, k);
            //}
            //Redb[j] -= factor * Redb[i];
        //}
    //}
//}
// Décomposition de Cholesky
//template <typename T>
//template <typename S>
//void Matrix<T>::DecomposeCholesky(Matrix<S>& L, S& det) const {
    //// Valider les paramètres de template
    //if (!(is_same<T, S>::value || (is_same<T, int>::value && is_same<S, double>::value))) {
        //throw invalid_argument(
            //"Paramètres de template invalides pour la décomposition de Cholesky. "
            //"S attendu == T ou T == int et S == Rational."
        //);
    //}

    //if (size != L.Size()) {
        //throw invalid_argument("Les tailles des matrices ne correspondent pas pour la décomposition de Cholesky.");
    //}

    //if (!IsHermitian() || !IsPositiveDefinite()) {
        //throw runtime_error("La matrice n'a pas de décomposition de Cholesky.");
    //}

    //det = 1;

    //for (int i = 0; i < size; i++) {
        //for (int j = 0; j <= i; j++) {
            //S sum = 0;
            //for (int k = 0; k < j; k++) {
                //if constexpr (is_same<S, Complex>::value) {
                    //sum += L(i, k) * L(j, k).conjugate();
                //} else {
                    //sum += L(i, k) * L(j, k);
                //}
            //}

            //if (i == j) {
                //L(i, i) = sqrt((*this)(i, i) - sum);
            //} else {
                //L(i, j) = ((*this)(i, j) - sum) / L(j, j);
            //}
        //}

        //det *= L(i, i);
    //}
//}

// Propriétés de la matrice
template <typename T>
Matrix<T> Matrix<T>::Transpose() const {
    Matrix<T> result(tag, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result.data[i][j] = data[j][i];
        }
    }
    return result;
}

//template <typename T>
//Matrix<T> Matrix<T>::Conjugate() const {
    //Matrix<T> result(tag, size);
    //for (int i = 0; i < size; i++) {
        //for (int j = 0; j < size; j++) {
            //if constexpr (is_same<T, Complex>::value) {
                //result.data[i][j] = data[i][j].conjugate();
            //} else {
                //result.data[i][j] = data[i][j];
            //}
        //}
    //}
    //return result;
//}

template <typename T>
Matrix<T> Matrix<T>::principalMinor(int k) const {
    if (k < 0 || k >= size+1) {
        throw out_of_range("L'indice de la sous-matrice principale est hors limites.");
    }

    Matrix<T> result(tag, k);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            result.data[i][j] = data[i][j];
        }
    }
    return result;
}

//template <typename T>
//bool Matrix<T>::IsHermitian() const {
    //for (int i = 0; i < size; i++) {
        //for (int j = 0; j < size; j++) {
            //if constexpr (is_same<T, Complex>::value) {
                //if (data[i][j] != data[j][i].conjugate()) {
                    //return false;
                //}
            //} else {
                //if (data[i][j] != data[j][i]) {
                    //return false;
                //}
            //}
        //}
    //}
    //return true;
//}

template <typename T>
bool Matrix<T>::IsPositiveDefinite() const {
    for(int k=1; k<=size; k++){
        T det = principalMinor(k).determinant();
        
            if (det <= 0) {
                return false;
            }
        }

    return true;
}

template <typename T>
bool Matrix<T>::IsInvertible() const {
    return determinant() != 0;
}

template <typename T>
bool Matrix<T>::nonZeroPrincipalMinors() const {
    for(int k=1; k<=size; k++){
        if (principalMinor(k).determinant() == 0) {
            return false;
        }
    }

    return true;
}

template <typename T>
T Matrix<T>::determinant() const {
    Matrix<T> temp(*this);
    T det = 1;

    for (int i = 0; i < size; i++) {
        if (temp(i, i) == 0) {
            bool swapped = false;
            for (int j = i + 1; j < size; j++) {
                if (temp(j, i) != 0) {
                    temp.swapRows(i, j);
                    det = det * (-1);
                    swapped = true;
                    break;
                }
            }
            if (!swapped) {
                return 0;
            }
        }

        if(temp(i, i) == 0){
            return 0;
        }

        det *= temp(i, i);

        for (int j = i + 1; j < size; j++) {
            T factor = temp(j, i) / temp(i, i);
            for (int k = i; k < size; k++) {
                temp(j, k) -= factor * temp(i, k);
            }
        }
    }

    return det;
}

template <typename T>
T& Matrix<T>::operator[](int i) {
    if (i < 0 || i >= size) {
        throw out_of_range("Les indices sont hors limites.");
    }
    return data[i];
}

// Opérateurs arithmétiques
template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix &M) const {
    if (size != M.size) {
        throw invalid_argument("Les tailles des matrices ne correspondent pour faire l'addition.");
    }

    Matrix<T> result(tag, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result.data[i][j] = data[i][j] + M.data[i][j];
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix &M) const {
    if (size != M.size) {
        throw invalid_argument("Les tailles des matrices ne correspondent pour faire la soustraction.");
    }

    Matrix<T> result(tag, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result.data[i][j] = data[i][j] - M.data[i][j];
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix &M) const {
    if (size != M.size) {
        throw invalid_argument("Les tailles des matrices ne correspondent pour faire la multiplication.");
    }

    Matrix<T> result(tag, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result.data[i][j] += data[i][k] * M.data[k][j];
            }
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(T scalar) const {
    Matrix<T> result(tag, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result.data[i][j] = data[i][j] * scalar;
        }
    }
    return result;
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& M) {
    if (this == &M) {
        return *this;
    }

    // Libérer la mémoire existante
    for (int i = 0; i < size; i++) {
        delete[] data[i];
    }
    delete[] data;

    size = M.size;
    tag = M.tag;
    data = new T*[size];
    for (int i = 0; i < size; i++) {
        data[i] = new T[size];
        for (int j = 0; j < size; j++) {
            data[i][j] = M.data[i][j];
        }
    }

    return *this;
}

template <typename T>
T& Matrix<T>::operator()(int i, int j) {
    if (i < 0 || j < 0 || i >= size || j >= size) {
        throw out_of_range("Les indices de ligne sont hors limites.");
    }
    return data[i][j];
}

template <typename T>
const T& Matrix<T>::operator()(int i, int j) const {
    if (i < 0 || j < 0 || i >= size || j >= size) {
        throw out_of_range("Les indices de ligne sont hors limites.");
    }
    return data[i][j];
}

template <typename T>
void Matrix<T>::swapRows(int i, int j) {
    if (i < 0 || j < 0 || i >= size || j >= size) {
        throw out_of_range("Les indices de ligne sont hors limites.");
    }

    T* temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

template <typename T>
Vector<T> Matrix<T>::productVector(const Vector<T>& V) const {
    if (size != V.Size()) {
        throw invalid_argument("La matrice et le vecteur n'ont pas les bonnes taille pour les multiplier.");
    }

    Vector<T> result(tag, size);
    for (int i = 0; i < size; i++) {
        result[i] = 0;
        for (int j = 0; j < size; j++) {
            result[i] += data[i][j] * V[j];
        }
    }
    return result;
}

template <typename T>
ostream& operator<<(ostream& out, const Matrix<T>& M) {
    out << endl;
    for (int i = 0; i < M.Size(); i++) {
        for (int j = 0; j < M.Size(); j++) {
            out << M(i, j) << " ";
        }
        out << endl;
    }
    return out;
}
