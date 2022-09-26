#pragma once

#include <iostream>

namespace b777 {
    void swapByPointer(int * p1, int * p2) {
        *p1 = *p1 + *p2;
        *p2 = *p1 - *p2;
        *p1 = *p1 - *p2;
    }

    void execute() {
        int a;
        int b;

        std::cout << "Type a: ";
        std::cin >> a;
        std::cout << "Type b: ";
        std::cin >> b;

        swapByPointer(&a, &b);

        std::cout << "Value of a, b: " << a << ", " << b << std::endl;
    }
}