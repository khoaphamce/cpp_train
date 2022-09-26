#include "b593_606.h"

/**
 * Constructor
 * Detail: non param constructor initiate all one, param constructor turn string (day/month/year) to number value.
 */
Date::Date() {
    this->day = 1;
    this->month = 1;
    this->year = 1;
}

Date::Date(int day, int month, int year) {
    try {
        // check valid day
        if (day > 31)
            throw(std::invalid_argument(std::string("Day in a month can not bigger than 31")));
        else
            this->day = day;

        // check valid month
        if (month > 12)
            throw(std::invalid_argument(std::string("Month in a year can not bigger than 12")));
        else
            this->month = month;

        // check valid day in month
        if (this->day > dayInMonth[this->month]) {
            std::string errMsg = "Day out of range";
            throw(std::invalid_argument(errMsg));
        }
    }
    catch (std::invalid_argument msg) {
        std::cout << std::string("Error: ") + msg.what() << std::endl;
        std::terminate();
    }

    this->year = year;
}

Date::Date(std::string inputDate) {
    char patternCount = 1;
    try {
        // Remove all space next to seperator
        for (int i = 0; i < inputDate.length(); i++) {
            if (inputDate[i] != '/')
                continue;

            while (i > 0 && inputDate[i - 1] == ' ') {
                inputDate.erase(inputDate.begin() + i - 1, inputDate.begin() + i);
                i--;
            }

            while (i < inputDate.length()-1 && inputDate[i + 1] == ' ')
                inputDate.erase(inputDate.begin() + i + 1, inputDate.begin() + i + 2);
        }

        // Extract number
        for (int i = 0; i < inputDate.length(); i++) {
            std::string foundNumber = "";
            bool validChar = 0;

            // Scan for number
            while (i < inputDate.length() && inputDate[i] >= '0' && inputDate[i] <= '9') {
                foundNumber = foundNumber + inputDate[i];
                i++;
            }

            // Found number
            if (foundNumber.length() > 0) {
                validChar = 1;
                i--;
                
                int numberValue = std::stoi(foundNumber);

                // check valid day
                if (patternCount == 1 && numberValue > 31)
                    throw(std::invalid_argument(std::string("Day in a month can not bigger than 31")));
                else if (patternCount == 1)
                    day = numberValue;

                // check valid month
                if (patternCount == 2 && numberValue > 12)
                    throw(std::invalid_argument(std::string("Month in a year can not bigger than 12")));
                else if (patternCount == 2) {
                    month = numberValue;

                    // check valid day in month
                    if (this->day > dayInMonth[this->month]) {
                        std::string errMsg = "Day out of range";
                        throw(std::invalid_argument(errMsg));
                    }
                }

                // check if year
                if (patternCount == 3)
                    year = numberValue;
            }

            // Found seperator
            if (inputDate[i] == '/') {
                patternCount++;
                validChar = 1;
            }

            // Invalid character
            if (!validChar) {
                std::string initMsg = " is an invalid character, Date must be in form of (day/month/year)";
                std::string errMsg = std::string(1,inputDate[i]) + initMsg;
                throw(std::invalid_argument(errMsg));
            }
        }
    }
    catch (std::invalid_argument msg) {
        std::cout << std::string("Error: ") + msg.what() << std::endl;
        std::terminate();
    }
}

/**
 * toString
 * Detail: Turn date into string (date/month/year) format
 */
std::string Date::toString() {
    std::string dateStr(std::to_string(this->day) + std::string(1, '/') + std::to_string(this->month) + std::string(1, '/') + std::to_string(this->year));
    return dateStr;
}

/**
 * Check if date is leap year
 */
bool Date::isLeapYear() {
    int sbc = 4;

    if (this->year % 100 == 0)
        sbc = 400;

    if (this->year % sbc == 0)
        return 1;
    else
        return 0;
}

bool Date::isLeapYear(int inputYear) {
    int sbc = 4;

    if (inputYear % 100 == 0)
        sbc = 400;

    if (inputYear % sbc == 0)
        return 1;
    else
        return 0;
}


/**
 * Calculate what day of the year (day 1, 2, 3, 4...)
 */
int Date::dayCount() {
    int daySum = 0;

    for (int i = 1; i < this->month; i++) {
        daySum += dayInMonth[i];
    }

    daySum += this->day;

    if (isLeapYear() && this->month > 2)
        daySum++;

    return daySum;
}

int Date::dayCount(Date inputDate) {
    int daySum = 0;

    for (int i = 1; i < inputDate.month; i++) {
        daySum += dayInMonth[i];
    }

    daySum += inputDate.day;

    if (isLeapYear() && inputDate.month > 2)
        daySum++;

    return daySum;
}


/**
 * Calculate how many day since 1/1/1
 */
int Date::dayCountAllOne() {
    int daySum = 0;

    // year loop
    for (int i = 1; i < this->year; i++) {
        Date newDate(31, 12, i);
        daySum += newDate.dayCount();
    }
    daySum += this->dayCount();

    return daySum;
}

/**
 * Calculate next day
 */
Date Date::nextDay() {
    int newDay = this->day + 1;
    int newMonth = this->month;
    int newYear = this->year;

    if (newDay > dayInMonth[this->month]) {
        if (isLeapYear(newYear) && newMonth == 2) {
            if (newDay > 29)
                newDay = 1;
                newMonth++;
        }
        else {
            newDay = 1;
            newMonth++;
        }
    }

    if (newMonth > 12) {
        newMonth = 1;
        newYear++;
    }

    return Date(newDay, newMonth, newYear);
}

/**
 * Calculate yesterday
 */
Date Date::previousDay() {
    int newDay = this->day - 1;
    int newMonth = this->month;
    int newYear = this->year;

    if (newDay < 1) {
        newMonth--;
        if (newMonth < 1) {
            newMonth = 12;
            newYear--;
        }
        if (isLeapYear(newYear) && newMonth == 2)
            newDay = 29;
        else
            newDay = dayInMonth[newMonth];
    }

    return Date(newDay, newMonth, newYear);
}

/**
 * Calculate n next day
 */
Date Date::nextDay(int n) {
    int newDay = this->day + n;
    int newMonth = this->month;
    int newYear = this->year;

    while (newDay > dayInMonth[newMonth]) {
        if (isLeapYear(newYear) && newMonth == 2)
            newDay = newDay - 29;
        else
            newDay = newDay - dayInMonth[newMonth];

        newMonth++;

        if (newMonth > 12) {
            newMonth = 1;
            newYear++;
        }
    }

    return Date(newDay, newMonth, newYear);
}

/**
 * Calculate n previous day
 */
Date Date::previousDay(int n) {
    int newDay = this->day - n;
    int newMonth = this->month;
    int newYear = this->year;

    while (newDay < 1) {
        newMonth--;

        if (newMonth < 1) {
            newMonth = 12;
            newYear--;
        }

        if (isLeapYear(newYear) && newMonth == 2)
            newDay = newDay + 29;
        else
            newDay = newDay + dayInMonth[newMonth];

    }

    return Date(newDay, newMonth, newYear);
}

/**
 * Calculate day gap from input day
 */
int Date::dayGap(Date inputDate) {
    int firstSub = this->dayCountAllOne();
    int secSub = inputDate.dayCountAllOne();

    return std::abs(firstSub - secSub);

}

/**
 * Compare date
 */
bool Date::operator > (Date const& obj) {
    if (this->year > obj.year)
        return true;
    else if (this->year < obj.year)
        return false;
    else if (this->month > obj.month)
        return true;
    else if (this->month < obj.month)
        return false;
    else if (this->day > obj.day)
        return true;
    else
        return false;


}

bool Date::operator < (Date const& obj) {
    if (*this > obj)
        return false;
    else if (this->year < obj.year)
        return true;
    else if (this->month < obj.month)
        return true;
    else if (this->day < obj.day)
        return true;
    else
        return false;
}

bool Date::operator == (Date const& obj) {
    if (*this > obj || *this < obj)
        return false;
    else
        return true;
}

bool Date::operator >= (Date const& obj) {
    if (*this > obj || *this == obj)
        return true;
    else
        return false;
}

bool Date::operator <= (Date const& obj) {
    if (*this < obj || *this == obj)
        return true;
    else
        return false;
}