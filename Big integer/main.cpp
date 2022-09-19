// Standard library
#include <iostream>
#include <fstream>

// User library
#include "Big_integer.h"

int main() {
    /*Big_integer bigInt;
    Big_integer bigInt2;

    std::cin >> bigInt;
    std::cin >> bigInt2;

    std::cout << bigInt / bigInt2 << std::endl;*/

    /*Big_integer bigInt;

    std::cin >> bigInt;

    char * data = bigInt.littleEndian();

    std::fstream binFile("test.bin", std::ios::out | std::ios::binary);

    binFile.write(data, 16);*/

    /*Big_integer a(10000, 1);
    Big_integer b(10000, 1);

    std::cout << (a > b) << std::endl;
    std::cout << (a < b) << std::endl;
    std::cout << (a == b) << std::endl;
    std::cout << (a != b) << std::endl;*/

    std::string exp = "23 45 +";
    Big_integer num = Big_integer::calculate(exp);
    std::cout << num << std::endl;

    return 0;
}