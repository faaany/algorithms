#include <iostream>
#include <vector>
#include "matmat.h"
#include <chrono>

using namespace std::chrono;
using std::cout;

typedef std::vector<double> Vector;

void init_mat(const unsigned m, const unsigned n, const unsigned k, Vector& A, Vector& B, Vector& C);


void printMatrix(unsigned m, unsigned k, const Vector& mat_C);

int main() {

    const unsigned m=10;
    const unsigned n=8;
    const unsigned k=6;
    const double alpha = 5;
    const double beta = 2;
    const unsigned iteration =100;

    Vector mat_A(m*n);
    Vector mat_B(n*k);
    Vector mat_C(m*k);

    init_mat(m,n,k,mat_A,mat_B,mat_C);
    //printMatrix(m,k,mat_C);

    auto start = high_resolution_clock::now();
    for(unsigned i=0; i<iteration; ++i) {
        matmat(alpha, false, mat_A.data(), m,n,mat_B.data(),k,beta,mat_C.data(),n,k,k);
    }
    auto stop = high_resolution_clock::now();

    double duration = duration_cast<nanoseconds>(stop-start).count()*1e-9/iteration;

    printMatrix(m, k, mat_C);

    cout << "\n" << "The execution time is " << duration<<"s. \n";

    return 0;
}

void printMatrix(unsigned m, unsigned k, const Vector& mat_C) {
    for(unsigned i=0; i < m; ++i) {
        for(unsigned j=0; j<k; ++j) {
            cout << mat_C[i*k + j] << ", ";
        }

        cout << std::__1::endl;
    }
}


void init_mat(const unsigned m, const unsigned n, const unsigned k, Vector& A, Vector& B, Vector& C) {
    unsigned d = std::min(m,n);
    for (unsigned i = 0; i < d; ++i) {
        A[i*(n+1)] = 1;
    }
    d = std::min(n,k);
    for (unsigned i = 0; i < d; ++i) {
        B[i*(k + 1)] = 2;
    }
    d= std::min(m,k);
    for (unsigned i=0; i<d; ++i) {
        C[i*(k+1)]= 1;
    }
}
