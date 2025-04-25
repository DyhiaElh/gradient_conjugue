#include "../hpp/Matrix.hpp"
#include "../hpp/Vector.hpp"
//#include "../hpp/Rational.hpp"
//#include "../hpp/Complex.hpp"
#include "../hpp/Solvers.hpp"
#include <iostream>
using namespace std;

int main() {
    
    
    ////////////////////////
    //cout << "Double" << endl;

    //Matrix<double> C(1, 3);
    //C(0, 0) = 2.5 ; C(0, 1) = -1.5; C(0, 2) = 0;
    //C(1, 0) = -1.5; C(1, 1) = 2.5 ; C(1, 2) = -1.5;
    //C(2, 0) = 0   ; C(2, 1) = -1.5; C(2, 2) = 2.5;

    //Vector<double> d(1, 3);
    //d[0] = 1.5; d[1] = 2.5; d[2] = 3.5;

    //cout << "LU method" << endl;
    //Vector<double> x5(1, 3);
    //SolveLU(C, d, x5);

    //cout << "Matrix C: " << C << endl;
    //cout << "Vector d: " << d << endl;
    //cout << "Solution: " << x5 << endl;
    //cout << "Check: " << C.productVector(x5) << endl;

    //cout << "Gauss method" << endl;
    //Vector<double> x6(1, 3);
    //SolveGauss(C, d, x6);

    //cout << "Matrix C: " << C << endl;
    //cout << "Vector d: " << d << endl;
    //cout << "Solution: " << x6 << endl;

    //cout << "Cholesky method" << endl;
    //Vector<double> x7(1, 3);
    //SolveCholesky(C, d, x7);

    //cout << "Matrix C: " << C << endl;
    //cout << "Vector d: " << d << endl;
    //cout << "Solution: " << x7 << endl;
    //cout << "Check: " << C.productVector(x7) << endl;

    //cout << "ConjugateGradient method" << endl;
    //Vector<double> x8(1, 3);
    //SolveConjugateGradient(C, d, x8, 1e-6, 1000);

    //cout << "Matrix C: " << C << endl;
    //cout << "Vector d: " << d << endl;
    //cout << "Solution: " << x8 << endl;
    //cout << "Check: " << C.productVector(x8) << endl;

    ////////////////////////
    //cout << "Complex" << endl;

    //Matrix<Complex> tempL(2, 3);
    //tempL(0,0) = Complex(1, 0); tempL(0,1) = Complex(0, 0); tempL(0,2) = Complex(0, 0);
    //tempL(1,0) = Complex(0, 1); tempL(1,1) = Complex(1, 0); tempL(1,2) = Complex(0, 0);
    //tempL(2,0) = Complex(1, 1); tempL(2,1) = Complex(0, -1); tempL(2,2) = Complex(1, 0);

    //Matrix<Complex> E = tempL*tempL.Transpose().Conjugate();
    //Vector<Complex> b9(2, 3);
    //b9[0] = Complex(1, 0); b9[1] = Complex(1, 1); b9[2] = Complex(0, -2);

    //cout << "LU method" << endl;
    //Vector<Complex> x9(2, 3);
    //SolveLU(E, b9, x9);

    //cout << "Matrix E: " << E << endl;
    //cout << "Vector b: " << b9 << endl;
    //cout << "Solution: " << x9 << endl;
    //cout << "Check: " << E.productVector(x9) << endl;

    //cout << "Gauss method" << endl;
    //Vector<Complex> x10(2, 3);
    //SolveGauss(E, b9, x10);

    //cout << "Matrix E: " << E << endl;
    //cout << "Vector b: " << b9 << endl;
    //cout << "Solution: " << x10 << endl;
    //cout << "Check: " << E.productVector(x10) << endl;

    //cout << "Cholesky method" << endl;
    //Vector<Complex> x11(2, 3);
    //SolveCholesky(E, b9, x11);

    //cout << "Matrix E: " << E << endl;
    //cout << "Vector b: " << b9 << endl;
    //cout << "Solution: " << x11 << endl;
    //cout << "Check: " << E.productVector(x11) << endl;

    //Matrix<Complex> LdecompE(2, 3);
    //Complex detE;
    //E.DecomposeCholesky(LdecompE, detE);

    //cout << LdecompE << endl;
    //cout << detE << endl;

    //cout << "ConjugateGradient method" << endl;
    //Vector<Complex> x12(2, 3);
    //SolveConjugateGradient(E, b9, x12, 1e-6, 1000);

    //cout << "Matrix E: " << E << endl;
    //cout << "Vector b: " << b9 << endl;
    //cout << "Solution: " << x12 << endl;
    //cout << "Check: " << E.productVector(x12) << endl;

    //////////////////////////
    //cout << "Reading from file and solving" << endl;
    //cout << "Int" << endl;

    //Matrix<int> F(0, 3);
    //Vector<int> g(0, 3);
    //Vector<Rational> x13(0, 3);
    //Vector<double> x14(0, 3);
    //F.readFromFile("../data/matrice_entier.txt");
    //g.readFromFile("../data/vecteur_b_entier.txt");

    //cout << "Matrix F: " << F << endl;
    //cout << "Vector g: " << g << endl;

    //Solve(F, g, x13, "LU", 1e-6, 1000);
    //cout << "Solution LU: " << x13 << endl;

    //Solve(F, g, x13, "Gauss", 1e-6, 1000);
    //cout << "Solution Gauss: " << x13 << endl;

    //Solve(F, g, x14, "Cholesky", 1e-6, 1000);
    //cout << "Solution Chol: " << x14 << endl;
    
    //Solve(F, g, x14, "ConjugateGradient", 1e-6, 1000);
    //cout << "Solution CG: " << x14 << endl;

    //cout << endl << "Double" << endl;

    Matrix<double> H(1, 3);
    Vector<double> i(1, 3);
    Vector<double> x_ex_d(1, 3);
    H.readFromFile("../data/matrice_reelle.txt");
    i.readFromFile("../data/vecteur_b_reel.txt");
    x_ex_d.readFromFile("../data/solution_x_reel.txt");
    Vector<double> x15(1, H.Size());

    //cout << "Matrix H: " << H << endl;
    //cout << "Vector i: " << i << endl;

    //Solve(H, i, x15, "LU", 1e-6, 1000);
    //cout << "Solution LU: " << x15 << endl;

    //Solve(H, i, x15, "Gauss", 1e-6, 1000);
    //cout << "Solution Gauss: " << x15 << endl;

    //Solve(H, i, x15, "Cholesky", 1e-6, 1000);
    //cout << "Solution Chol: " << x15 << endl;

    Solve(H, i, x15, x_ex_d, "ConjugateGradient", 1e-8, 1000, "erreurs_double.csv");
    cout << "Solution CG: " << x15 << endl;
    
    
    cout << "Check: " << H.productVector(x15) << endl;

    //cout << endl << "Complex" << endl;

    //Matrix<Complex> J(2, 0);
    //Vector<Complex> k(2, 0);
    //J.readFromFile("../data/matrice_complexe.txt");
    //k.readFromFile("../data/vecteur_b_complexe.txt");
    //Vector<Complex> x16(2, J.Size());

    //cout << "Matrix J: " << J << endl;
    //cout << "Vector k: " << k << endl;

    //Solve(J, k, x16, "LU", 1e-6, 1000);
    //cout << "Solution LU: " << x16 << endl;

    //Solve(J, k, x16, "Gauss", 1e-6, 1000);
    //cout << "Solution Gauss: " << x16 << endl;

    //Solve(J, k, x16, "Cholesky", 1e-6, 1000);
    //cout << "Solution Chol: " << x16 << endl;

    //Solve(J, k, x16, "ConjugateGradient", 1e-6, 1000);
    //cout << "Solution CG: " << x16 << endl;


cout << "float" << endl;

    //Matrix<float> M(1, 3);
    //M(0, 0) = 2.5 ; M(0, 1) = -1.5; M(0, 2) = 0;
    //M(1, 0) = -1.5; M(1, 1) = 2.5 ; M(1, 2) = -1.5;
    //M(2, 0) = 0   ; M(2, 1) = -1.5; M(2, 2) = 2.5;

    //Vector<float> B(1, 3);
    //B[0] = 1.5; B[1] = 2.5; B[2] = 3.5;
    
    //Vector<float> x(1, 3);
    //SolveConjugateGradient(M, B, x, 1e-6, 1000);

    //cout << "Matrix M: " << M << endl;
    //cout << "Vector B: " << B << endl;
    //cout << "Solution: " << x << endl;
    //cout << "Check: " << M.productVector(x) << endl;
    
    
    Matrix<float> K(0, 3);
    Vector<float> L(0, 3);
    Vector<float> x_ex_f(0, 3);
    K.readFromFile("../data/matrice_float.txt");
    L.readFromFile("../data/vecteur_float.txt");
    x_ex_f.readFromFile("../data/solution_float.txt");
    Vector<float> xL(0, K.Size());

    //cout << "Matrix H: " << K << endl;
    //cout << "Vector i: " << L << endl;
    Solve(K, L, xL, x_ex_f, "ConjugateGradient", 1e-6, 1000, "erreurs_float.csv");
    cout << "Solution CG: " << xL << endl;
    
    
    cout << "Check: " << K.productVector(xL) << endl;

    
    return 0;
}
