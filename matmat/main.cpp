#include <iostream>
#include <vector>
#include "matmat.h"
#include <chrono>

using namespace std::chrono;

typedef std::vector<double> Vector;

void init_mat(const unsigned m, const unsigned n, const unsigned k, Vector& A, Vector& B, Vector& C);


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

    auto start = high_resolution_clock::now();
    for(unsigned i=0; i<iteration; ++i) {
        matmat(alpha, false, mat_A.data(), m,n,mat_B.data(),k,beta,mat_C.data());
    }
    auto stop = high_resolution_clock::now();

    double duration = duration_cast<nanoseconds>(stop-start).count()*1e-9/iteration;

    for(unsigned i=0; i<m; ++i) {
        for(unsigned j=0; j<k; ++j) {
            std::cout << mat_C[i*m+j] << ", ";
        }

        std::cout << std::endl;
    }

    std::cout << "\n" << "The execution time is " << duration<<"s. \n";

    return 0;
}



void init_mat(const unsigned m, const unsigned n, const unsigned k, Vector& A, Vector& B, Vector& C) {
    for (unsigned i = 0; i <m; ++i) {
        for (unsigned j = 0; j < n; ++j) {
            if(j == i){
                A[i*m+j] = 1;
                B[i*m+j] =2;
                C[i*m+j] =1;
            }
        }
    }
}
