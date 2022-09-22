#pragma once

#include <iostream>
#include <cmath>

namespace b39 {

    long long int factorial(long long int n) {
        long long int result = 1;

        for (long long  int i = 1; i <= n; i++) {
            result = result * i;
        }

        return result;
    }


    double S(int n) {
        double sum = 0;

        for (long long int i = 1; i <= n; i++) {
            sum = std::pow(factorial(i) + sum, (1.0 / (i + 1)));
        }

        return sum;
    }

    void execute() {
        long long int n;

        std::cout << "Type in n to calculate S(n): ";
        std::cin >> n;

        std::cout << "S(n) = " << S(n) << std::endl;
    }

}