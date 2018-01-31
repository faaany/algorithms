#include <iostream>
#include "fibonacci.h"


int main() {

    for(unsigned n:{0,1,2,3,4,5,6,7,8,9,10}) {
        auto result = fibonacci(n);
        std::cout << "f(" << n << ") = " << result << std::endl;
    }
    
    return 0;
}