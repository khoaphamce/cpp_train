// Standard library
#include <iostream>
#include <fstream>

// User library
#include "Big_integer.h"

int main() {
    Big_integer bigInt;
    Big_integer bigInt2;

    std::cin >> bigInt;
    std::cin >> bigInt2;

    std::cout << bigInt - bigInt2 << std::endl;

    return 0;
}