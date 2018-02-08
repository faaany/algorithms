//
// Created by fanli Lin on 08.02.18.
//
#include "matmat.h"


void matmat(double alpha, bool trans, double const* a, int m, int n,
            double const* b, int k, double beta, double* c) {

    if(trans== true) {

        for(unsigned i=0; i<m; ++i) {
            for(unsigned j=0; j<k; ++j) {
                double sum =0;
                for(unsigned p=0; p<n; ++p) {
                    sum += a[i*m+p]*b[n*p+j];
                }
                c[i*m+j]=alpha*sum+beta*c[i*m+j];
            }
        }
    }else {

        for(unsigned i=0; i<m; ++i) {
            for(unsigned j=0; j<k; ++j) {
                double sum=0;
                for(unsigned p=0; p<n; ++p) {
                    sum += a[n*p+i]*b[n*p+j];
                }
                c[i*m+j] = alpha*sum + beta*c[i*m+j];
            }

        }

    }

}
