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

std::string oneComplement(unsigned char inputNumber) {
    std::string oneComp = decToBin(inputNumber);

    for (int i = 0; i < oneComp.length(); i++) {
        if (oneComp[i] == '0')
            oneComp[i] = '1';
        else
            oneComp[i] = '0';
    }

    return oneComp;
}

std::string twoComplement(unsigned char inputNumber) {
    std::string oneComp = oneComplement(inputNumber);
    std::string twoComp = oneComp;

    bool carry = 1;

    for (int i = twoComp.length() - 1; (i >= 0) && (carry == 1); i--) {

        if (twoComp[i] == '1')
            twoComp[i] = '0';
        else {
            twoComp[i] = '1';
            carry = 0;
        }
    }
    return twoComp;
}


std::string* listTwoComplement(unsigned char* numberList, unsigned char listLength) {
    std::string* result = new std::string[listLength];

    for (int i = 0; i < listLength; i++) {
        result[i] = twoComplement(numberList[i]);
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