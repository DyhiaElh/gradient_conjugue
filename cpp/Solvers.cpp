#include "../hpp/Solvers.hpp"
#include <stdexcept>
#include <cmath>
#include <cstring>
#include <fstream>
using namespace std;

//template <typename T>
//void SolveLU(Matrix<T>& A, Vector<T>& b, Vector<T>& x) {
    //if (A.Size() != b.Size() || A.Size() != x.Size()) {
        //throw invalid_argument("Les dimensions des matrices et vecteurs ne correspondent pas.");
    //}

    //if (!A.nonZeroPrincipalMinors()) {
        //throw runtime_error("La matrice n'a pas de décomposition LU.");
    //}

    //Matrix<T> L(A.Tag(), A.Size());
    //Matrix<T> U(A.Tag(), A.Size());
    //T det;
    //A.DecomposeLU(L, U, det);

    //Vector<T> y(A.Tag(), A.Size());
    //for (int i = 0; i < A.Size(); i++) {
        //T sum = 0;
        //for (int j = 0; j < i; j++) {
            //sum += L(i, j) * y[j];
        //}
        //y[i] = (b[i] - sum) / L(i, i);
    //}

    //for (int i = A.Size() - 1; i >= 0; i--) {
        //T sum = 0;
        //for (int j = i + 1; j < A.Size(); j++) {
            //sum += U(i, j) * x[j];
        //}
        //x[i] = (y[i] - sum) / U(i, i);
    //}
//}

//void SolveLUint(Matrix<int>& A, Vector<int>& b, Vector<Rational>& x) {
    //if (A.Size() != b.Size() || A.Size() != x.Size()) {
        //throw invalid_argument("Les dimensions des matrices et vecteurs ne correspondent pas.");
    //}

    //if (!A.nonZeroPrincipalMinors()) {
        //throw runtime_error("La matrice n'a pas de décomposition LU.");
    //}

    //Matrix<Rational> L(A.Tag(), A.Size());
    //Matrix<Rational> U(A.Tag(), A.Size());
    //Rational det;
    //A.DecomposeLU(L, U, det);

    //Vector<Rational> y(A.Tag(), A.Size());
    //for (int i = 0; i < A.Size(); i++) {
        //Rational sum = 0;
        //for (int j = 0; j < i; j++) {
            //sum += L(i, j) * y[j];
        //}
        //y[i] = (Rational(b[i],1) - sum) / L(i, i);
    //}

    //for (int i = A.Size() - 1; i >= 0; i--) {
        //Rational sum = 0;
        //for (int j = i + 1; j < A.Size(); j++) {
            //sum += U(i, j) * x[j];
        //}
        //x[i] = (y[i] - sum) / U(i, i);
    //}
//}

//template <typename T>
//void SolveGauss(Matrix<T>& A, Vector<T>& b, Vector<T>& x) {
    //if (A.Size() != b.Size() || A.Size() != x.Size()) {
        //throw invalid_argument("Les dimensions des matrices et vecteurs ne correspondent pas.");
    //}

    //if (A.determinant() == 0) {
        //throw runtime_error("La matrice n'est pas inversible.");
    //}

    //Matrix<T> RedForm(A.Tag(), A.Size());
    //Vector<T> Redb(A.Tag(), A.Size());
    //T det;
    //A.GaussElimination(RedForm, b, Redb, det);

    //for (int i = A.Size() - 1; i >= 0; i--) {
        //T sum = 0;
        //for (int j = i + 1; j < A.Size(); j++) {
            //sum += RedForm(i, j) * x[j];
        //}
        //x[i] = (Redb[i] - sum) / RedForm(i, i);
    //}
//}

//void SolveGaussInt(Matrix<int>& A, Vector<int>& b, Vector<Rational>& x) {
    //if (A.Size() != b.Size() || A.Size() != x.Size()) {
        //throw invalid_argument("Les dimensions des matrices et vecteurs ne correspondent pas.");
    //}

    //if (A.determinant() == 0) {
        //throw runtime_error("La matrice n'est pas inversible.");
    //}

    //Matrix<Rational> RedForm(A.Tag(), A.Size());
    //Vector<Rational> Redb(A.Tag(), A.Size());
    //Rational det;
    //Vector<int> b_copy = b;
    //A.GaussElimination(RedForm, b_copy, Redb, det);

    //for (int i = A.Size() - 1; i >= 0; i--) {
        //Rational sum = 0;
        //for (int j = i + 1; j < A.Size(); j++) {
            //sum += RedForm(i, j) * x[j];
        //}
        //x[i] = (Redb[i] - sum) / RedForm(i, i);
    //}
//}

//template <typename T>
//void SolveCholesky(Matrix<T>& A, Vector<T>& b, Vector<T>& x) {
    //if (A.Size() != b.Size() || A.Size() != x.Size()) {
        //throw invalid_argument("Les dimensions des matrices et vecteurs ne correspondent pas.");
    //}

    //if (!A.IsHermitian() || !A.IsPositiveDefinite()) {
        //throw runtime_error("La matrice n'est pas hermitienne ou définie positive.");
    //}

    //Matrix<T> L(A.Tag(), A.Size());
    //T det;
    //A.DecomposeCholesky(L, det);

    //Vector<T> y(A.Tag(), A.Size());
    //for (int i = 0; i < A.Size(); i++) {
        //T sum = 0;
        //for (int j = 0; j < i; j++) {
            //sum += L(i, j) * y[j];
        //}
        //y[i] = (b[i] - sum) / L(i, i);
    //}

    //for (int i = A.Size() - 1; i >= 0; i--) {
        //T sum = 0;
        //for (int j = i + 1; j < A.Size(); j++) {
            //if constexpr (is_same<T, Complex>::value) {
                //sum += L(j, i).conjugate() * x[j];
            //} else {
                //sum += L(j, i) * x[j];
            //}
        //}
        //x[i] = (y[i] - sum) / L(i, i);
    //}
//}

//void SolveCholeskyInt(Matrix<int>& A, Vector<int>& b, Vector<double>& x) {
    //if (A.Size() != b.Size() || A.Size() != x.Size()) {
        //throw invalid_argument("Les dimensions des matrices et vecteurs ne correspondent pas.");
    //}

    //if (!A.IsHermitian() || !A.IsPositiveDefinite()) {
        //throw runtime_error("La matrice n'est pas hermitienne ou définie positive.");
    //}

    //Matrix<double> L(1, A.Size());
    //double det;
    //A.DecomposeCholesky(L, det);

    //Vector<double> y(1, A.Size());
    //for (int i = 0; i < A.Size(); i++) {
        //double sum = 0;
        //for (int j = 0; j < i; j++) {
            //sum += L(i, j) * y[j];
        //}
        //y[i] = (b[i] - sum) / L(i, i);
    //}

    //for (int i = A.Size() - 1; i >= 0; i--) {
        //double sum = 0;
        //for (int j = i + 1; j < A.Size(); j++) {
            //sum += L(j, i) * x[j];
        //}
        //x[i] = (y[i] - sum) / L(i, i);
    //}
//}
template <typename T>
double Norm(const Vector<T>& v) {
    T sum = 0.0;
    for (int i = 0; i < v.Size(); i++) {
        sum = sum + v[i] * v[i];
    }
    return std::sqrt(sum);
}

template <typename T>
void SolveConjugateGradient(Matrix<T>& A, Vector<T>& b, Vector<T>& x, const Vector<T>& x_exact, double tol, int maxIter, const std::string& nomFichier) {
    if (A.Size() != b.Size() || A.Size() != x.Size()) {
        throw invalid_argument("Les dimensions des matrices et vecteurs ne correspondent pas.");
    }

    if (tol <= 0 || maxIter <= 0) {
        throw invalid_argument("La tolérance et le nombre d'itérations doivent être positifs.");
    }

    //if(!A.IsPositiveDefinite()) {
    //    throw runtime_error("La matrice n'est pas hermitienne ou définie positive.");
    //}
    std::ofstream fout(nomFichier);
    if (!fout) {
        throw std::runtime_error("Impossible d'ouvrir le fichier.");
    }
    Vector<T> r = b - A.productVector(x);
    Vector<T> p = r;
    Vector<T> Ap = A.productVector(p);
    

    for (int k = 0; k < maxIter; k++) {
        T alpha = r.dot(r) / p.dot(Ap);
        x = x + p * alpha;
        Vector<T> r_next = r - Ap * alpha;
        T residu = Norm(b - A.productVector(x));

        if (residu < tol) {
            cout << "Convergence au résidu à l'itération " << k << " avec résidu = " << residu << endl;
            break;
         }
        if (abs(r_next) < tol) {
            return;
        }
        
    
        T beta = r_next.dot(r_next) / r.dot(r);
        p = r_next + p * beta;
        r = r_next;
        
        Ap = A.productVector(p);
        //cout << "convergence a l'iteration " << k << endl;
        //Calcul de l'erreur
        T erreur = Norm(x_exact - x); 
        
        fout << k << "," << erreur << "," << residu << endl;

        if (erreur < tol) {
            cout << "Convergence à l'itération " << k << " avec erreur = " << erreur << endl;
            break;
        }
        
    }
    
   fout.close();
   
}

//void SolveConjugateGradientInt(Matrix<int>& A, Vector<int>& b, Vector<double>& x, double tol, int maxIter) {
    //if (A.Size() != b.Size() || A.Size() != x.Size()) {
        //throw invalid_argument("Les dimensions des matrices et vecteurs ne correspondent pas.");
    //}

    //if (tol <= 0 || maxIter <= 0) {
        //throw invalid_argument("La tolérance et le nombre d'itérations doivent être positifs.");
    //}

    //if(!A.IsHermitian() || !A.IsPositiveDefinite()) {
        //throw runtime_error("La matrice n'est pas hermitienne ou définie positive.");
    //}

    //Vector<double> b_copy(1, A.Size());
    //Matrix<double> A_copy(1, A.Size());
    //for (int i = 0; i < A.Size(); i++) {
        //b_copy[i] = b[i];
        //for (int j = 0; j < A.Size(); j++) {
            //A_copy(i, j) = A(i, j);
        //}
    //}

    //Vector<double> r = b_copy - A_copy.productVector(x);
    //Vector<double> p = r;
    //Vector<double> Ap = A_copy.productVector(p);

    //for (int k = 0; k < maxIter; k++) {
        //if (abs(r) < tol) {
            //return;
        //}
        
        //double alpha = r.dot(r) / p.dot(Ap);
        //x = x + p * alpha;
        //Vector<double> r_next = r - Ap * alpha;

        //double beta = r_next.dot(r_next) / r.dot(r);
        //p = r_next + p * beta;
        //r = r_next;
        //Ap = A_copy.productVector(p);
    //}
//}

template <typename T, typename S>
void Solve(Matrix<T>& A, Vector<T>& b, Vector<S>& x, const Vector<T>& x_exact, const char* method, double tol, int maxIter, const std::string& nomFichier) {
    //if constexpr (is_same<T, int>::value && is_same<S, Rational>::value) {
        //if (strcmp(method, "LU") == 0) {
            //SolveLUint(A, b, x);
        //} else if (strcmp(method, "Gauss") == 0) {
            //SolveGaussInt(A, b, x);
        //} else {
            //throw invalid_argument("La méthode est inconnue.");
        //}
    //} else if constexpr (is_same<T, int>::value && is_same<S, double>::value) {
        //if (strcmp(method, "Cholesky") == 0) {
            //SolveCholeskyInt(A, b, x);
        //} 
        //if (strcmp(method, "ConjugateGradient") == 0) {
            //SolveConjugateGradientInt(A, b, x, tol, maxIter);
        //} else {
            //throw invalid_argument("La méthode est inconnue.");
        //}
    //} else {
        //if (strcmp(method, "LU") == 0) {
            //SolveLU(A, b, x);
        //} else if (strcmp(method, "Gauss") == 0) {
            //SolveGauss(A, b, x);
        //} else if (strcmp(method, "Cholesky") == 0) {
            //SolveCholesky(A, b, x);
        if constexpr (std::is_same<S, float>::value) {
            // Si le type de x est float, utiliser un fichier spécifique
            //cout << "Exécution pour float, écriture dans " << nomFichier << "_float.csv" << std::endl;
            SolveConjugateGradient(A, b, x, x_exact, tol, maxIter, "erreur_float.csv");
        } else if constexpr (std::is_same<S, double>::value) {
            // Si le type de x est double, utiliser un autre fichier
            //cout << "Exécution pour double, écriture dans " << nomFichier << "_double.csv" << std::endl;
            SolveConjugateGradient(A, b, x, x_exact, tol, maxIter, "erreur_double.csv");
     
        } else {
            throw invalid_argument("La méthode est inconnue.");
        }
    }
