#include <iostream>

// Basic programming
#include "b1.h"
#include "b39.h"

// Function and code structure
#include "b115.h"
#include "b117.h"

// Recursion
#include "b703.h"
#include "b707.h"

// Array
#include "b158.h"
#include "b166.h"

// Pointer
#include "b776.h"
#include "b777.h"

// String and OOP
#include "b593_606.h"

int main() {
    Date myDate("1/1/2021");
    Date compareDate("1/1/2021");

    std::cout << myDate.toString() << std::endl;
    std::cout << myDate.isLeapYear() << std::endl;
    std::cout << myDate.dayCount() << std::endl;
    std::cout << myDate.dayCountAllOne() << std::endl;
    std::cout << myDate.nextDay().toString() << std::endl;
    std::cout << myDate.previousDay().toString() << std::endl;
    std::cout << myDate.nextDay(35).toString() << std::endl;
    std::cout << myDate.previousDay(5).toString() << std::endl;
    std::cout << (myDate > compareDate) << std::endl;
    std::cout << (myDate >= compareDate) << std::endl;
    std::cout << (myDate < compareDate) << std::endl;
    std::cout << (myDate <= compareDate) << std::endl;
    std::cout << (myDate == compareDate) << std::endl;

    return 0;
}