#include "Big_integer.h"


/**
 * Overload cin >> for Big_integer 
 */
std::istream & operator >> (std::istream & stream, Big_integer & bigIntValue) {
    stream >> bigIntValue.digits;

    if (bigIntValue.digits[0] == '-') {
        bigIntValue.posVal = 0;
        bigIntValue.digits.erase(bigIntValue.digits.begin(), bigIntValue.digits.begin()+1);
    }
    else
        bigIntValue.posVal = 1;

    bigIntValue.value = std::stoull(bigIntValue.digits);

    return stream;
}


/**
 * Overload cout << for Big_integer
 */
std::ostream & operator << (std::ostream & stream, Big_integer & bigIntValue) {
    stream << bigIntValue.digits;
    return stream;
}


/**
 * turn value to string
 */
std::string Big_integer::valueToString(unsigned long long value, bool posVal)
{
    std::string result = "";
    unsigned long long quotinent = value;
    char mod;

    while (quotinent != 0) {
        mod = quotinent % 10;
        quotinent = quotinent / 10;

        result = char(mod + 48) + result;
    }

    if (posVal == 0 && value != 0)
        result = '-' + result;
    
    return result;
}


/**
 * Overload operator for Big_integer
 */
Big_integer& Big_integer::operator+(Big_integer const& obj)
{
    Big_integer * result;

    if (this->posVal == 0 && obj.posVal == 0) {
        result = new Big_integer(obj.value + this->value, 0);
    }
    else if (this->posVal == 1 && obj.posVal == 0) {
        if (this->value > obj.value)
            result = new Big_integer(this->value - obj.value, 1);
        else
            result = new Big_integer(obj.value - this->value, 0);
    }
    else if (this->posVal == 0 && obj.posVal == 1) {
        if (this->value > obj.value)
            result = new Big_integer(this->value - obj.value, 0);
        else
            result = new Big_integer(obj.value - this->value, 1);
    }
    else {
        result = new Big_integer(obj.value + this->value, 1);
    }

    return *result;
}

Big_integer& Big_integer::operator-(Big_integer const& obj)
{
    Big_integer* result;

    if (this->posVal == 0 && obj.posVal == 0) {
        if (obj.value > this->value)
            result = new Big_integer(obj.value - this->value, 1);
        else
            result = new Big_integer(this->value - obj.value, 0);
    }
    else if (this->posVal == 1 && obj.posVal == 0) {
        result = new Big_integer(this->value + obj.value, 1);
    }
    else if (this->posVal == 0 && obj.posVal == 1) {
        result = new Big_integer(this->value + obj.value, 0);
    }
    else {
        if (obj.value > this->value)
            result = new Big_integer(obj.value - this->value, 0);
        else
            result = new Big_integer(this->value - obj.value, 1);
    }

    return *result;
}

Big_integer& Big_integer::operator * (Big_integer const& obj)
{
    Big_integer* result;
    if ((this->posVal == 0 && obj.posVal == 0) || (this->posVal == 1 && obj.posVal == 1)) {
        result = new Big_integer(obj.value * this->value, 1);
    }
    else{
        result = new Big_integer(obj.value * this->value, 0);
    }
    return *result;
}

Big_integer& Big_integer::operator / (Big_integer const& obj)
{
    Big_integer* result;
    try {
        if (obj.value == 0)
            throw("Can not divide by 0");

        if ((this->posVal == 0 && obj.posVal == 0) || (this->posVal == 1 && obj.posVal == 1)) {
            result = new Big_integer(this->value / obj.value, 1);
        }
        else {
            result = new Big_integer(this->value / obj.value, 0);
        }
        return *result;
    }
    catch(std::string msg) {
        std::cout << msg << std::endl;
    }

    return *(new Big_integer(0,1));
}

/**
 *  Bit functionality
 * DetaiL: return one complement and two complement
 */
char* Big_integer::oneComplement(char* inputPtr) {
    for (char i = 0; i < 16; i++)
        for (char j = 0; j < 8; j++)
            inputPtr[i] = (inputPtr[i] ^ ((char)1 << j));

    return inputPtr;
}

char* Big_integer::twoComplement(char* inputPtr) {
    char* oneComp = oneComplement(inputPtr);
    char* twoComp = oneComp;

    char carry = 1;

    for (char i = 15; i >= 0 && carry == 1; i--) {
        char curByte = inputPtr[i];

        for (char j = 7; j >= 0 && carry == 1; j--) {
            char curBit = (1 == ((curByte >> j) & 1));

            if (curBit == 0)
                carry = 0;
            else
                carry = 1;

            inputPtr[i] = (inputPtr[i] ^ ((char)1 << j));
        }
    }

    return twoComp;
}


/**
 * Return big endian and little endian
 * DetaiL: return pointer
 */
char* Big_integer::littleEndian()
{
    char* bigIntPtr = new char[16];

    /**
     * Reset memory blocks 
     */
    for (char i = 0; i < 16; i++)
        bigIntPtr[i] = 0;

    /**
     * Loop for positive number
     * Detail: Shift and add bit to memory blocks
     */
    for (char i = 0; i < 8; i++) {
        char toInsertByte = ((this->value) >> (64 - ((i+1) * 8)));
        bigIntPtr[i] = toInsertByte;
    }

    /**
     * Loop for negative number
     */
    if (posVal == 0)
        twoComplement(bigIntPtr);
    return bigIntPtr;
}