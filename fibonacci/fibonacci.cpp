//
// Created by fanli Lin on 31.01.18.
//

unsigned long fibonacci(unsigned n) {
    if(n==0) return 0;
    if(n==1) return 1;

    return fibonacci(n-1) + fibonacci(n-2);
}