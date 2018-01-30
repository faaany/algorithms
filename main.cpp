#include <iostream>
#include <chrono>
#include <vector>
#include <random>

using std::mt19937;
using std::normal_distribution;
using std::bind;
using std::ostream;
using std::cout;

typedef long double extended;
typedef std::vector<extended> Vector;

mt19937 generator = mt19937(std::random_device()());
normal_distribution<extended> normal;
auto normalGenerator = bind(normal, generator);


void matVec(Vector& mat, Vector& vec, Vector& result, const unsigned N);

void initMat(Vector& mat, Vector& vec, const unsigned N);

int main() {

    unsigned N, k;

    Vector mat(N*N);
    Vector vec(N);
    Vector result(N);

    initMat(mat, vec,N);

    for(unsigned i=0; i<k; ++i) {
        matVec(mat, vec, result,N);
    }


    return 0;
}


void initMat(Vector& mat, Vector& vec, const unsigned N) {

    for(unsigned i=0; i<N; ++i) {
        for(unsigned j=0; j<N; ++j) {
            mat[i*N+j] = normalGenerator();
        }
        vec[i]= normalGenerator();
    }

}


void matVec(Vector& mat, Vector& vec, Vector& result, const unsigned N) {

    for(unsigned i=0; i<N; ++i) {
        extended sum =0;
        for(unsigned j=0; j<N; ++j) {
            sum = mat[i*N+j]*vec[j];
        }

        result[i] = sum;
    }
}