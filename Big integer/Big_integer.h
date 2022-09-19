#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>

#pragma once
/**
 * Big_integer class
 * Detail: 128 bit, signed integer
 */
class Big_integer
{
private:
    std::string digits = "0";
    // posVal = 0 => negative value vice-versa
    bool posVal = 0;
    // Save value
    unsigned long long value = 0;

    // Big int to string
    std::string valueToString(unsigned long long value, bool posVal);
    
    /**
     * std::cin >> and std::cout << big integer
     * Write with text file
     */
    friend std::istream & operator >> (std::istream & stream, Big_integer& bigIntValue);
    friend std::ostream & operator << (std::ostream & stream, Big_integer& bigIntValue);

    char* oneComplement(char* inputPtr);
    char* twoComplement(char* inputPtr);


    /**
     * Check if the input is arithmetic 
     */
    static int isArith(char inputChar);


    /**
     * Turn polish reverse notation string to vector
     */
    static std::vector <std::string> strToPost(std::string inFix);

public:
    /**
     * Constructor 
     */
    Big_integer(){}
    Big_integer(unsigned long long number, bool posVal) {
        this->value = number;
        this->posVal = posVal;
        this->digits = this->valueToString(number, posVal);
    }
    Big_integer(std::string inpStr) {
        this->posVal = 1;
        if (inpStr[0] == '-') {
            this->posVal = 0;
            inpStr.erase(inpStr[0], inpStr[1]);
        }

        this->value = std::stoull(inpStr);
    }

    /**
     * Overload operator
     */
    Big_integer& operator + (Big_integer const& obj);
    Big_integer& operator - (Big_integer const& obj);
    Big_integer& operator * (Big_integer const& obj);
    Big_integer& operator / (Big_integer const& obj);
    bool operator > (Big_integer const& obj);
    bool operator < (Big_integer const& obj);
    bool operator == (Big_integer const& obj);
    bool operator != (Big_integer const& obj);


    /**
     * Functions return pointer that point to 128 bit number that in little-endian and big-endian 
     */
    char* littleEndian();
    char* bigEndian();

    /**
     * Calculate using input notation
     */

    static Big_integer calculate(std::string expression);
};

