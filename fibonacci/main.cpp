#include <iostream>
#include "fibonacci.h"
#include <chrono>

using namespace std::chrono;
using std::cout;

int main() {

    cout<<"Fibonacci recursive   linear   constant memory\n";
    for(unsigned n:{0,1,2,3,4,5,6,7,8,9,10}) {

        auto result_rec = fibonacci(n);
        auto result_lin = fibonacciLinear(n);
        auto result_const= fibonacciConst(n);

        cout << "f(" << n << ") =           " << result_rec << "         " << result_lin <<"         "<<result_const << "\n";
    }

    const unsigned N = 40;
    cout << "\nCompare the efficiency of three implementations for N=" << N << "\n\n";

    auto start = high_resolution_clock::now();
    auto result_rec = fibonacci(N);
    auto stop = high_resolution_clock::now();
    auto duration_rec = duration_cast<nanoseconds>(stop-start).count()*1e-9;

    cout << "recursive implementation: " << result_rec << "         ,time used: " << duration_rec << "s\n";

    start = high_resolution_clock::now();
    auto result_lin = fibonacciLinear(N);
    stop = high_resolution_clock::now();
    auto duration_lin = duration_cast<nanoseconds>(stop-start).count()*1e-9;

    cout << "linear memory implementation: " << result_lin << "         ,time used: " << duration_lin << "s\n";

    start = high_resolution_clock::now();
    auto result_const = fibonacciConst(N);
    stop = high_resolution_clock::now();
    auto duration_const = duration_cast<nanoseconds>(stop-start).count()*1e-9;

    cout << "const memory implementation: " << result_const << "         ,time used: " << duration_const << "s\n";


    return 0;
}