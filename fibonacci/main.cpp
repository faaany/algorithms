#include <iostream>
#include "fibonacci.h"

using std::cout;

int main() {

    cout<<"Fibonacci recursive   linear   constant space\n";
    for(unsigned n:{0,1,2,3,4,5,6,7,8,9,10}) {

        auto result_rec = fibonacci(n);
        auto result_lin = fibonacciLinear(n);
        auto result_const= fibonacciConst(n);

        cout << "f(" << n << ") =           " << result_rec << "         " << result_lin <<"      "<<result_const << "\n";
    }

    return 0;
}