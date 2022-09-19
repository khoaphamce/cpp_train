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

bool Big_integer::operator > (Big_integer const& obj) {
    if ((this->posVal) == 0 && obj.posVal == 1)
        return 0;
    if ((this->posVal) == 1 && obj.posVal == 0)
        return 1;

    if ((this->value) > obj.value) {
        if ((this->posVal) == 1 && obj.posVal == 1)
            return 1;
        else if ((this->posVal) == 0 && obj.posVal == 0)
            return 0;
        
    }
    else {
        if ((this->posVal) == 1 && obj.posVal == 1)
            return 0;
        else if ((this->posVal) == 0 && obj.posVal == 0)
            return 1;
    }
}

bool Big_integer::operator < (Big_integer const& obj) {
    if ((this->posVal) == 0 && obj.posVal == 1)
        return 1;
    if ((this->posVal) == 1 && obj.posVal == 0)
        return 0;

    if ((this->value) < obj.value) {
        if ((this->posVal) == 1 && obj.posVal == 1)
            return 1;
        else if ((this->posVal) == 0 && obj.posVal == 0)
            return 0;
    }
    else {
        if ((this->posVal) == 1 && obj.posVal == 1)
            return 0;
        else if ((this->posVal) == 0 && obj.posVal == 0)
            return 1;
    }
}

bool Big_integer::operator == (Big_integer const& obj) {
    if ((this->value) == obj.value && obj.posVal == (this->posVal))
        return 1;
    else {
        if (obj.posVal != (this->posVal))
            if ((this->value) == obj.value && (this->value) == 0)
                return 1;
            else
                return 0;

        return 0;
    }
}

bool Big_integer::operator != (Big_integer const& obj) {
    if ((this->value) == obj.value && obj.posVal == (this->posVal))
        return 0;
    else {
        if (obj.posVal != (this->posVal))
            if ((this->value) == obj.value && (this->value) == 0)
                return 0;
            else
                return 1;

        return 1;
    }
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

    for (char i = 0; i < 8 && carry == 1; i++) {
        char curByte = twoComp[i];

        for (char j = 7; j >= 0 && carry == 1; j--) {
            /*char curBit = (1 == ((curByte >> (7-j)) & 1));

            if (curBit == 0)
                carry = 0;
            else
                carry = 1;

            twoComp[i] = (twoComp[i] ^ ((char)1 << j));*/
            int tempByte = curByte + 1;
            
            if (tempByte > 255)
                carry = 1;
            else
                carry = 0;

            twoComp[i] = twoComp[i] + 1;
        }
    }

    return twoComp;
}


/**
 * Return big endian and little endian
 * DetaiL: return pointer
 */
char* Big_integer::bigEndian()
{
    char* bigIntPtr = new char[16];

    /**
     * Reset memory blocks 
     */
    for (char i = 0; i < 16; i++)
        bigIntPtr[i] = 0;

    /**
     * Shift and add bit to memory blocks
     * Detail: For big endian
     */
    char j = 0;
    for (char i = 7; i >= 0; i--) {
        char toInsertByte = ((this->value) >> (64 - ((j+1) * 8)));
        bigIntPtr[i] = toInsertByte;
        j++;
    }

    /**
     * Loop for negative number
     */
    if (posVal == 0)
        twoComplement(bigIntPtr);

    return bigIntPtr;
}

char* Big_integer::littleEndian()
{
    char* bigIntPtr = bigEndian();

    for (int i = 0; i < 7; i++) 
        std::swap(bigIntPtr[i], bigIntPtr[15 - i]);
    
    return bigIntPtr;
}


/**
 * Check if the input is arithmetic
 */
int Big_integer::isArith(char inputChar) {
    if (inputChar == '+' || inputChar == '-')
        return 1;
    if (inputChar == '*' || inputChar == '/')
        return 2;
    if (inputChar == '(' || inputChar == ')')
        return -1;
    return 0;
}

std::vector <std::string> Big_integer::strToPost(std::string inFix) {
    std::vector <std::string> postFix;

    /**
     *  Loop to detect and process all expression
     *  Detail: This loop process expression
     */

    for (int i = 0; i < inFix.length(); i++) {
        /**
         *  Extract number
         */
        std::string extractNumber = "";
        int j = i;
        while ((inFix[j] >= '0') && (inFix[j] <= '9') && (j < inFix.length())) {
            extractNumber = extractNumber + inFix[j];
            j++;
        }
        
        /**
         *  add number to postFix
         */
        if (extractNumber.length() != 0) {
            postFix.push_back(extractNumber);
            i = j-1;
        }
        else if (inFix[i] == '(' || inFix[i] == ')' || (isArith(inFix[i]) >= 1))
            postFix.push_back(std::string(1, inFix[i]));

    }
   
    /**
     *  [END] of loop
     */

    return postFix;
}

Big_integer Big_integer::calculate(std::string expression){
    std::vector <std::string> postFix = strToPost(expression);

    std::stack<Big_integer> numStack;

    for (int i = 0; i < postFix.size(); i++) {
        /**
         *  Number check
         */
        std::string extractNumber = "";
        int j = 0;
        while ((postFix[i][j] >= '0') && (postFix[i][j] <= '9') && (j < postFix[i].length())) {
            extractNumber = extractNumber + postFix[i][j];
            j++;
        }
        /**
         *  add number to stack
         */
        if (extractNumber.length() != 0)
            numStack.push(Big_integer(extractNumber));
        /**
         *  Arith check
         */
        else if (isArith(postFix[i][0]) > 0) {
            if (numStack.size() >= 1) {
                Big_integer num1 = numStack.top();
                numStack.pop();

                Big_integer num2 = numStack.top();
                numStack.pop();

                if (postFix[i][0] == '+')
                    numStack.push(num1 + num2);
                else if (postFix[i][0] == '-')
                    numStack.push(num2 - num1);
                else if (postFix[i][0] == '*')
                    numStack.push(num1 * num2);
                else if (postFix[i][0] == '/')
                    numStack.push(num1 / num2);
            }
        }
        // std::cout << numStack.top() << std::endl;
    }
    if (numStack.empty())
        return Big_integer(0, 1);

    return numStack.top();
}
