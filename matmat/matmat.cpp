//
// Created by fanli Lin on 08.02.18.
//
#include "matmat.h"


void matmat(double alpha, bool trans, double const* a, int m, int n,
            double const* b, int k, double beta, double* c, int ida, int idb, int idc) {

    if(trans== false) {
        for(unsigned i=0; i<m; ++i) {
            for(unsigned j=0; j<k; ++j) {
                double sum =0;
                for(unsigned p=0; p<n; ++p) {
                    sum += a[i*ida+p]*b[p*idb+j];
                }
                c[i*idc+j]=alpha*sum+beta*c[i*idc+j];
            }
        }
    }else {
        for(unsigned i=0; i<m; ++i) {
            for(unsigned j=0; j<k; ++j) {
                double sum=0;
                for(unsigned p=0; p<n; ++p) {
                    sum += a[ida*p+i]*b[p*idb+j];
                }
                c[i*idc+j] = alpha*sum + beta*c[i*idc+j];
            }
        }
    }

}
