#pragma once

#include <iostream>
#include <cmath>

namespace b703 {
    long long int factorial(long long int n) {
        if (n == 0) return 1;

        long long int result = n * factorial(n - 1);

        return result;
    }

    void execute() {
        long long int n;

        std::cout << "Type in n to calculate Factorial(n): ";
        std::cin >> n;

        std::cout << "S(n) = " << factorial(n) << std::endl;
    }

}