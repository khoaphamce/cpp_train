#include <iostream>
#include <math.h>
#include <string>

std::string decToBin(unsigned char inputNumber) {
    unsigned char quotinent = inputNumber;
    bool mod;
    std::string binResult = "";

    while (quotinent != 0) {
        mod = quotinent % 2;
        quotinent = quotinent / 2;

        binResult = char((mod)+48) + binResult;
    }

    while (binResult.length() < 8)
        binResult = '0' + binResult;

    return binResult;
}

unsigned char oneComplement(unsigned char inputNumber) {
    for (int i = 0; i < 8; i++)
        inputNumber = (inputNumber ^ (1 << i));
    
    return inputNumber;
}


unsigned char twoComplement(unsigned char inputNumber) {
    unsigned char oneComp = oneComplement(inputNumber);
    return oneComp + 1;
}


std::string* listTwoComplement(unsigned char* numberList, unsigned char listLength) {
    std::string* result = new std::string[listLength];

    for (int i = 0; i < listLength; i++) {
        result[i] = decToBin(twoComplement(numberList[i]));
    }

    return result;
}


int main() {
    unsigned char arr[] = { 0, 1, 2, 126, 127, 128, 129, 130, 254, 255 };

    std::string* result = listTwoComplement(arr, 10);

    for (int i = 0; i < 10; i++)
        std::cout << result[i] << std::endl;

    return 0;
}