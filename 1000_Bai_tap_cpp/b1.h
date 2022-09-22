#pragma once
#include <iostream>

namespace b1 {

    long long int S(long long int n) {
        long long int sum = 0;

        for (long long int i = 1; i <= n; i++) {
            sum += i;
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