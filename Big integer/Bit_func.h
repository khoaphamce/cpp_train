#include <math.h>
#include <string>

#ifndef BIT_FUNC
#pragma once

char * oneComplement(char * inputPtr) {
    for (char i = 0; i < 16; i++)
        for (char j = 0; j < 8; j++)
            inputPtr[i] = (inputPtr[i] ^ ((char)1 << j));
    
    return inputPtr;
}


char * twoComplement(char * inputPtr) {
    char * oneComp = oneComplement(inputPtr);
    char* twoComp = oneComp;

    char carry = 1;

    for (char i = 15; i >= 0 && carry != 1; i--) {
        for (char j = 7; j >= 0 && carry != 1; j--) {
            char curBit = (1 == ((inputPtr[i] >> j) & 1));

            if (curBit == 0)
                carry = 0;
            else
                carry = 1;

            inputPtr[i] = (inputPtr[i] ^ ((char)1 << j));
        }
    }

    return twoComp;
}

#endif // !BIT_FUNC