//
// Created by 홍준근 on 2022/11/21.
//
#include <stdexcept>
#include <utility>

enum MonthType {
    D_31, D_30, D_29, D_28
};

class Date {
private:
    int year;
    int month;
    int day;
    int monthAmount[4] = {31, 30, 29, 28};

    bool isOdd() {
        return this->month % 2 == 1;
    }

    bool isAfterSummer() {
        return this->month >= 8;
    }

    bool isLeapYear() {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }

    MonthType getMonthType() {
        if (this->month == 2) {
            if (isLeapYear()) {
                return D_29;
            }
            return D_28;
        }
        if ((isAfterSummer() && isOdd()) || (!isAfterSummer() && !isOdd())) {
            return D_30;
        }
        return D_31;
    }

    int getMonthDayLimit() {
        return this->monthAmount[this->getMonthType()];
    }

    bool validateOverDay() {
        return this->getMonthDayLimit() < this->day;
    }

    void dayCalculate(int amount) {
        int year = amount / 365;
        int otherDays1 = amount % 365;
        otherDays1 += countLeapYear(year);
        int otherMonth = otherDays1 / 12;
        int otherDays2 = otherDays1 % 12;
        this->day +=otherDays2;
        this->month += otherMonth;
        this->year += year;
    }

    void monthCalculate(int amount) {
        int year = amount / 12;
        int month = amount % 12;
        this->day += countLeapYear(year);
        this->month += month;
        this->year += year;
    }

    int countLeapYear(int targetYear) {
        int count = 0;
        int temp = this->year;
        for (int i = 0; i < targetYear; targetYear++) {
            if ((temp % 4 == 0 && temp % 100 != 0) || temp % 400 == 0) {
                count++;
            }
            temp++;
        }
        return count;
    }


    void roundUpDate() {
        if (validateOverDay()) {
            int diff = this->day - this->getMonthDayLimit();
            this->month++;
            this->day = diff;
        }
    }

    void validate(int value) {
        if (value <= 0) {
            throw std::invalid_argument("This value is not allowed");
        }
    }


public:
    void setDate(int year, int month, int day) {
        this->year = year;
        this->month = month;
        this->day = day;
    }

    void addDay(int volume) {
        validate(volume);
        this->dayCalculate(volume);
        roundUpDate();
    };

    void addMonth(int volume) {
        validate(volume);
        this->monthCalculate(volume);
        roundUpDate();
    };

    void addYear(int volume) {
        validate(volume);
        this->year += volume;
        roundUpDate();
    };

    int getYear() {
        return this->year;
    }

    int getMonth() {
        return this->month;
    }

    int getDay() {
        return this->day;
    }
};