//
// Created by fanli Lin on 08.02.18.
//

#ifndef MATMAT_MATMAT_H
#define MATMAT_MATMAT_H

void matmat(double alpha, bool trans, double const* a, int m, int n,
            double const* b, int k, double beta, double* c, int ida, int idb, int idc);

#endif //MATMAT_MATMAT_H
