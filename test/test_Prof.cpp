#include "../hpp/Matrix.hpp"
#include "../hpp/Vector.hpp"
#include "../hpp/Rational.hpp"
#include "../hpp/Complex.hpp"
#include "../hpp/Solvers.hpp"
#include <iostream>
using namespace std;

int main() {



    // Test avec matrice intialisée [int]
    cout << endl << "Matrice et vecteur de type int"<< endl;

    Matrix<int> A1(0, 3);
    A1(0, 0) = 2; A1(0, 1) = -1; A1(0, 2) = 0;  //  2 -1  0
    A1(1, 0) = -1; A1(1, 1) = 2; A1(1, 2) = -1; // -1  2 -1
    A1(2, 0) = 0; A1(2, 1) = -1; A1(2, 2) = 2;  //  0 -1  2

    Vector<int> b1(0, 3);
    b1[0] = 1; b1[1] = 2; b1[2] = 3;           // (1, 2, 3)

    cout << "A1:\n" << A1 << "\n";
    cout << "b1:\n" << b1 << "\n";

    Vector<Rational> x1(0, 3);
    Solve(A1, b1, x1, "Gauss", 1e-6, 1000);
    cout << "Solution Gauss: " << x1 << "\n";

    Vector<Rational> x2(0, 3);
    Solve(A1, b1, x2, "LU", 1e-6, 1000);
    cout << "Solution LU: " << x2 << "\n";

    Vector<double> x3(0, 3);
    Solve(A1, b1, x3, "Cholesky", 1e-6, 1000);
    cout << "Solution Cholesky: " << x3 << "\n";

    Vector<double> x4(0, 3);
    Solve(A1, b1, x4, "ConjugateGradient", 1e-6, 1000);
    cout << "Solution ConjugateGradient: " << x4 << "\n";
    //////////////////////////////////////




    // Test avec matrice intialisée [double]
    cout << endl << "Matrice et vecteur de type double"<< endl;

    Matrix<double> A2(1, 3);
    A2(0, 0) = 2.5; A2(0, 1) = -1.5; A2(0, 2) = 0;    //  2.5 -1.5  0.0
    A2(1, 0) = -1.5; A2(1, 1) = 2.5; A2(1, 2) = -1.5; // -1.5  2.5 -1.5
    A2(2, 0) = 0; A2(2, 1) = -1.5; A2(2, 2) = 2.5;    //  0.0 -1.5  2.5
 
    Vector<double> b2(1, 3);
    b2[0] = 1.5; b2[1] = 2.5; b2[2] = 3.5;            // (1.5, 2.5, 3.5)

    cout << "A2:\n" << A2 << "\n";
    cout << "b2:\n" << b2 << "\n";

    Vector<double> x5(1, 3);
    Solve(A2, b2, x5, "Gauss", 1e-6, 1000);
    cout << "Solution Gauss: " << x5 << "\n";

    Vector<double> x6(1, 3);
    Solve(A2, b2, x6, "LU", 1e-6, 1000);
    cout << "Solution LU: " << x6 << "\n";

    Vector<double> x7(1, 3);
    Solve(A2, b2, x7, "Cholesky", 1e-6, 1000);
    cout << "Solution Cholesky: " << x7 << "\n";

    Vector<double> x8(1, 3);
    Solve(A2, b2, x8, "ConjugateGradient", 1e-6, 1000);
    cout << "Solution ConjugateGradient: " << x8 << "\n";
    //////////////////////////////////////




    // Test avec matrice intialisée [Complex]
    cout << endl << "Matrice et vecteur de type Complex"<< endl;

    Matrix<Complex> A3(2, 3);
    A3(0, 0) = Complex(2, 0); A3(0, 1) = Complex(0, -1); A3(0, 2) = Complex(0, 0);  //  2 -i  0
    A3(1, 0) = Complex(0, 1); A3(1, 1) = Complex(2, 0); A3(1, 2) = Complex(0, -1);  //  i  2 -i
    A3(2, 0) = Complex(0, 0); A3(2, 1) = Complex(0, 1); A3(2, 2) = Complex(2, 0);   //  0  i  2

    Vector<Complex> b3(2, 3);
    b3[0] = Complex(1, 1); b3[1] = Complex(2, -1); b3[2] = Complex(3, 2);          // (1+i, 2-i, 3+2i)

    cout << "A3:\n" << A3 << "\n";
    cout << "b3:\n" << b3 << "\n";

    Vector<Complex> x9(2, 3);
    Solve(A3, b3, x9, "Gauss", 1e-6, 1000);
    cout << "Solution Gauss: " << x9 << "\n";

    Vector<Complex> x10(2, 3);
    Solve(A3, b3, x10, "LU", 1e-6, 1000);
    cout << "Solution LU: " << x10 << "\n";

    Vector<Complex> x11(2, 3);
    Solve(A3, b3, x11, "Cholesky", 1e-6, 1000);
    cout << "Solution Cholesky: " << x11 << "\n";

    Vector<Complex> x12(2, 3);
    Solve(A3, b3, x12, "ConjugateGradient", 1e-6, 1000);
    cout << "Solution ConjugateGradient: " << x12 << "\n";
    //////////////////////////////////////




    // Test avec matrice lu à partir d'un fichier [int]
    cout << endl << "Matrice et vecteur de type int lu à partir d'un fichier"<< endl;

    Matrix<int> A4;
    Vector<int> b4;
    A4.readFromFile("../data/matrice_entier.txt");
    b4.readFromFile("../data/vecteur_b_entier.txt");

    cout << "A4:\n" << A4 << "\n";
    cout << "b4:\n" << b4 << "\n";

    int size1 = A4.Size();

    Vector<Rational> x13(0, size1);
    Solve(A4, b4, x13, "Gauss", 1e-6, 1000);
    cout << "Solution Gauss: " << x13 << "\n";

    Vector<Rational> x14(0, size1);
    Solve(A4, b4, x14, "LU", 1e-6, 1000);
    cout << "Solution LU: " << x14 << "\n";

    Vector<double> x15(0, size1);
    Solve(A4, b4, x15, "Cholesky", 1e-6, 1000);
    cout << "Solution Cholesky: " << x15 << "\n";

    Vector<double> x16(0, size1);
    Solve(A4, b4, x16, "ConjugateGradient", 1e-6, 1000);
    cout << "Solution ConjugateGradient: " << x16 << "\n";
    //////////////////////////////////////




    // Test avec matrice lu à partir d'un fichier [double]
    cout << endl << "Matrice et vecteur de type double lu à partir d'un fichier"<< endl;

    Matrix<double> A5;
    Vector<double> b5;
    A5.readFromFile("../data/matrice_reelle.txt");
    b5.readFromFile("../data/vecteur_b_reel.txt");

    cout << "A5:\n" << A5 << "\n";
    cout << "b5:\n" << b5 << "\n";

    int size2 = A5.Size();

    Vector<double> x17(1, size2);
    Solve(A5, b5, x17, "Gauss", 1e-6, 1000);
    cout << "Solution Gauss: " << x17 << "\n";

    Vector<double> x18(1, size2);
    Solve(A5, b5, x18, "LU", 1e-6, 1000);
    cout << "Solution LU: " << x18 << "\n";

    Vector<double> x19(1, size2);
    Solve(A5, b5, x19, "Cholesky", 1e-6, 1000);
    cout << "Solution Cholesky: " << x19 << "\n";

    Vector<double> x20(1, size2);
    Solve(A5, b5, x20, "ConjugateGradient", 1e-6, 1000);
    cout << "Solution ConjugateGradient: " << x20 << "\n";
    //////////////////////////////////////




    // Test avec matrice lu à partir d'un fichier [Complex]
    cout << endl << "Matrice et vecteur de type Complex lu à partir d'un fichier"<< endl;

    Matrix<Complex> A6;
    Vector<Complex> b6;
    A6.readFromFile("../data/matrice_complexe.txt");
    b6.readFromFile("../data/vecteur_b_complexe.txt");

    cout << "A6:\n" << A6 << "\n";
    cout << "b6:\n" << b6 << "\n";

    int size3 = A6.Size();

    Vector<Complex> x21(2, size3);
    Solve(A6, b6, x21, "Gauss", 1e-6, 1000);
    cout << "Solution Gauss: " << x21 << "\n";

    Vector<Complex> x22(2, size3);
    Solve(A6, b6, x22, "LU", 1e-6, 1000);
    cout << "Solution LU: " << x22 << "\n";

    Vector<Complex> x23(2, size3);
    // Solve(A6, b6, x23, "Cholesky", 1e-6, 1000); // elle va pas marcher puisque la matrice n'est pas hermitienne donc pas définie positive
    cout << "Solution Cholesky: " << x23 << "\n";

    Vector<Complex> x24(2, size3);
    // Solve(A6, b6, x24, "ConjugateGradient", 1e-6, 1000); // elle va pas marcher puisque la matrice n'est pas hermitienne donc pas définie positive
    cout << "Solution ConjugateGradient: " << x24 << "\n";
    //////////////////////////////////////



    
    // Test avec matrice complexe de grande taille
    cout << endl << "Matrice et vecteur de type Complex de grande taille"<< endl;

    Matrix<Complex> A7;
    Vector<Complex> b7;
    A7.readFromFile("../data/matrice_complexe_grande.txt");
    b7.readFromFile("../data/vecteur_b_complexe_grande.txt");

    cout << "A7:\n" << A7 << "\n";
    cout << "b7:\n" << b7 << "\n";

    int size4 = A7.Size();

    Vector<Complex> x25(2, size4);
    Solve(A7, b7, x25, "Gauss", 1e-6, 1000);
    cout << "Solution Gauss: " << x25 << "\n";

    Vector<Complex> x26(2, size4);
    Solve(A7, b7, x26, "LU", 1e-6, 1000);
    cout << "Solution LU: " << x26 << "\n";

    Vector<Complex> x27(2, size4);
    Solve(A7, b7, x27, "Cholesky", 1e-6, 1000);
    cout << "Solution Cholesky: " << x27 << "\n";

    Vector<Complex> x28(2, size4);
    Solve(A7, b7, x28, "ConjugateGradient", 1e-6, 1000);
    cout << "Solution ConjugateGradient: " << x28 << "\n";
    //////////////////////////////////////



    return 0;
}
