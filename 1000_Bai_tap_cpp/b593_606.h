#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cmath>

class Date {
protected:
    int day = 1;
    int month = 1;
    int year = 1;

    std::vector<char> dayInMonth = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

public:
    /**
     * Constructor
     * Detail: non param constructor initiate all one, param constructor turn string to number value.
     */
    Date();
    Date(int day, int month, int year);
    Date(std::string inputDate);

    /**
     * toString
     * Detail: Turn date into string (date/month/year) format
     */
    std::string toString();

    /**
     * Check if date is leap year
     */
    bool isLeapYear();
    bool isLeapYear(int inputYear);

    /**
     * Calculate what day of the year (day 1, 2, 3, 4...)
     */
    int dayCount();
    int dayCount(Date inputDate);


    /**
     * Calculate how many day since 1/1/1
     */
    int dayCountAllOne();

    /**
     * Calculate next day
     */
    Date nextDay();

    /**
     * Calculate yesterday
     */
    Date previousDay();

    /**
     * Calculate n next day
     */
    Date nextDay(int n);

    /**
     * Calculate n previous day
     */
    Date previousDay(int n);

    /**
     * Calculate day gap from input day
     */
    int dayGap(Date inputDate);

    /**
     * Compare date
     */
    bool operator > (Date const& obj);
    bool operator < (Date const& obj);
    bool operator == (Date const& obj);
    bool operator >= (Date const& obj);
    bool operator <= (Date const& obj);
};