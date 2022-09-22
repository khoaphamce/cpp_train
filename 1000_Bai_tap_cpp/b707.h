#pragma once

#include <iostream>
#include <cmath>

namespace b707 {
    long long int fibo(long long int n) {
        if (n == 0) return 1;
        if (n == 1) return 1;

        long long int result = fibo(n - 1) + fibo(n - 2);

        return result;
    }

    void execute() {
        long long int n;

        std::cout << "Type in n to calculate nth fibonaci: ";
        std::cin >> n;

        std::cout << "Fibonaci(n) = " << fibo(n) << std::endl;
    }
}