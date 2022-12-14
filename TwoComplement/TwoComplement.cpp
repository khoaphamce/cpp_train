#include <iostream>
#include <math.h>
#include <string>
#include <vector>

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

int binToDec(std::string binStr) {
    int result = 0;

    for (int i = binStr.length() - 1; i >= 0; i--) {
        result += std::pow(binStr[i]-48, binStr.length() - 1 - i);
    }

    return result;
}

unsigned char oneComplement(unsigned char inputNumber) {
    for (int i = 0; i < 8; i++)
        inputNumber = (inputNumber ^ (1 << i));
    
    return inputNumber;
}


unsigned char twoComplement(unsigned char inputNumber, bool binaryToDec = false) {
    unsigned char oneComp = oneComplement(inputNumber);

    if (binaryToDec) {

    }

    return oneComp + 1;
}


std::vector<std::string> listTwoComplement(unsigned char* numberList, unsigned char listLength) {
    std::vector<std::string> result;

    for (int i = 0; i < listLength; i++) {
        result.push_back(decToBin(twoComplement(numberList[i])));
    }

    return result;
}


int main() {
    unsigned char arr[] = { 0, 1, 2, 126, 127, 128, 129, 130, 254, 255 };

    std::vector<std::string> result = listTwoComplement(arr, 10);

    for (int i = 0; i < 10; i++)
        std::cout << result[i] << std::endl;

    return 0;
}