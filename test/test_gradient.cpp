#include "../hpp/Matrix.hpp"
#include "../hpp/Vector.hpp"
#include "../hpp/Solvers.hpp"
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
	cout << "double" <<endl;
	Matrix<double> H(1, 80);
    Vector<double> i(1, 80);
    Vector<double> x_ex_d(1, 80);
    H.readFromFile("matrice.txt");
    i.readFromFile("b.txt");
    x_ex_d.readFromFile("x.txt");
    Vector<double> x15(1, H.Size());
    
    
    //x15=H.productVector(x_ex_d);
   
	//cout << "Vector i: " <<  x15<< endl;
    //cout << "Matrix H: " << i << endl;
    //cout << "vect: " << x15 << endl;
    //cout << "Matrix H: " << H << endl;
    //cout << "Vector i: " << i << endl;
    
    Solve(H, i, x15, x_ex_d,  "ConjugateGradient", 1e-15, 10, "erreurs_double.csv");
    
    cout << "Solution CG: " << setprecision(15) <<x15 << endl;
    //x15.writeToFile("../datagradient/b.txt");
    //Vector<double> rd(1, 100);
    //rd=i-H.productVector(x15);
    //cout << "Check: " << rd << endl;
    //cout << "Check: " << H.productVector(x15) << endl;
    
    //cout << "float" <<endl;
	//Matrix<float> M(0, 80);
    //Vector<float> N(0, 80);
    //Vector<float> x_ex_f(0, 80);
    //M.readFromFile("matrice2.txt");
    //N.readFromFile("b2.txt");
    //x_ex_f.readFromFile("x2.txt");
    //Vector<float> x16(0, M.Size());
    ////////x16=M.productVector(x_ex_f);
    ////////x16.writeToFile("../datagradient/b_float.txt");
    ////////cout << "Vector i: " <<  M << endl;
    //Solve(M, N, x16, x_ex_f,  "ConjugateGradient", 1e-10, 10, "erreurs_float.csv");
    //cout << "Solution float: " <<  x16 << endl;
    ////cout << "Check: " << M.productVector(x16) << endl;
    return 0;
}
