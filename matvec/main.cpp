#include <iostream>
#include <chrono>
#include <vector>
#include <random>


using std::cout;
using std::cin;
using namespace std::chrono;

typedef long double extended;
typedef std::vector<extended> Vector;

auto generator = std::mt19937(std::random_device()());
auto normal= std::uniform_real_distribution<extended>(0,1);
auto normalGenerator = std::bind(normal, generator);


void matVec(const Vector& mat, const Vector& vec, Vector& result, unsigned N);
void initOperands(Vector& mat, Vector& vec, unsigned N);

int main(int nArgs, char** args) {

    unsigned N=1000, k=200;
    if(nArgs>1) N= unsigned(abs(atoi(args[1])));
    if(nArgs>2) k= unsigned(abs(atoi(args[2])));

//    cout << "Please enter the matrix size N: ";
//    cin >> N;
//
//    cout << "Please enter the number of iterations: ";
//    cin >> k;

    Vector mat(N*N);
    Vector vec(N);
    Vector result(N);

    initOperands(mat, vec, N);

    auto start = high_resolution_clock::now();
    for(unsigned i=0; i<k; ++i) {
        matVec(mat, vec, result,N);
    }
    auto stop = high_resolution_clock::now();

    extended duration = duration_cast<nanoseconds>(stop-start).count()*1e-9;

    cout << "duration for N = " << N << " with "<< k << " repetations is " << duration << "s. \n";

    return 0;
}


void initOperands(Vector& mat, Vector& vec, unsigned N) {

    for(unsigned i=0; i<N; ++i) {
        for(unsigned j=0; j<N; ++j) {
            mat[i*N+j] = normalGenerator();
        }
        vec[i]= normalGenerator();
    }

}


void matVec(const Vector& mat, const Vector& vec, Vector& result, const unsigned N) {

    for(unsigned i=0; i<N; ++i) {
        extended sum =0;
        for(unsigned j=0; j<N; ++j) {
            sum = mat[i*N+j]*vec[j];
        }

        result[i] = sum;
    }
}