#ifndef SOLVERS_HPP
#define SOLVERS_HPP

#include "../hpp/Matrix.hpp"
#include "../hpp/Vector.hpp"
//#include "../hpp/Rational.hpp"
//#include "../hpp/Complex.hpp"
using namespace std;

//template <typename T>
//void SolveLU(const Matrix<T>& A, const Vector<T>& b, Vector<T>& x);

//void SolveLUint(const Matrix<int>& A, const Vector<int>& b, Vector<Rational>& x);

//template <typename T>
//void SolveGauss(const Matrix<T>& A, const Vector<T>& b, Vector<T>& x);

//void SolveGaussInt(const Matrix<int>& A, const Vector<int>& b, Vector<Rational>& x);

//template <typename T>
//void SolveCholesky(const Matrix<T>& A, const Vector<T>& b, Vector<T>& x);

//void SolveCholeskyInt(const Matrix<int>& A, const Vector<int>& b, Vector<double>& x);

template <typename T>
void SolveConjugateGradient(const Matrix<T>& A, const Vector<T>& b, Vector<T>& x, const Vector<T>& x_exact, double tol, int maxIter, const std::string& nomFichier);

//void SolveConjugateGradientInt(const Matrix<int>& A, const Vector<int>& b, Vector<double>& x, double tol, int maxIter);

template <typename T, typename S>
void Solve(Matrix<T>& A, Vector<T>& b, Vector<S>& x, const Vector<T>& x_exact, const char* method, double tol, int maxIter, const std::string& nomFichier);

#include "../cpp/Solvers.cpp"
#endif // SOLVERS_HPP
