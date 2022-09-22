#pragma once
#include <iostream>

namespace b117 {
    long long int pow(long long int x, long long int y) {
        if (y == 0) return 1;

        long long int mul = 1;

        for (int i = 1; i <= y; i++)
            mul *= x;

        return mul;
    }

    long long int S(long long int x, long long int n) {
        long long int sum = 0;

        for (long long int i = 1; i <= n; i++) {
            sum += pow(x, i);
        }

        return sum;
    }

    void execute() {
        long long int n;
        long long int x;

        std::cout << "Type in x to calculate S(x, n): ";
        std::cin >> x;
        std::cout << "Type in n to calculate S(x, n): ";
        std::cin >> n;

        std::cout << "S(n) = " << S(x, n) << std::endl;
    }

}

