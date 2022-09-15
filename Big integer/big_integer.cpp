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
}