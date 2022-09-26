#pragma once

#include <iostream>

namespace b776 {
    void pointerPrac() {
        int* p = new int [100];

        std::cout << "Initiated new pointer that have 100 integer slot" << std::endl;
        std::cout << "Initial address and its value: " << p << ", " << p[0] << std::endl;
        std::cout << "Final address and its value: " << p+99 << ", " << p[99] << std::endl;

        delete[] p;

        std::cout << "Deleted pointer p\n";
    }

    void execute() {
        pointerPrac();
    }
}