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

    MonthType getMonthType();
    int getMonthDayLimit();

    void dayCalculate(int amount);
    void monthCalculate(int amount);

    int countLeapYear(int targetYear);
    void roundUpDate();
    void validate(int value);
    bool validateOverDay();
    bool isOdd();
    bool isAfterSummer();
    bool isLeapYear();

public:
    Date(){
        this->year = 1997;
        this->month = 11;
        this->day = 29;
    }
    Date(int year, int month, int day){
        this->year = year;
        this->month = month;
        this->day = day;
    }
    void setDate(int year, int month, int day) {
        this->year = year;
        this->month = month;
        this->day = day;
    }

    void addDay(int volume);
    void addMonth(int volume);
    void addYear(int volume);

    int getYear();
    int getMonth();
    int getDay();
};

void Date::addYear(int volume) {
    validate(volume);
    this->year += volume;
    roundUpDate();
};

void Date::addMonth(int volume) {
    validate(volume);
    this->monthCalculate(volume);
    roundUpDate();
}

void Date::addDay(int volume) {
    validate(volume);
    this->dayCalculate(volume);
    roundUpDate();
};

int Date::getYear() {
    return this->year;
}

int Date::getMonth(){
    return this->month;
}

int Date::getDay() {
    return this->day;
}

int Date::countLeapYear(int targetYear) {
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

void Date::roundUpDate() {
    if (validateOverDay()) {
        int diff = this->day - this->getMonthDayLimit();
        this->month++;
        this->day = diff;
    }
}

bool Date::isOdd() {
    return this->month % 2 == 1;
}

bool Date::isAfterSummer() {
    return this->month >= 8;
}

bool Date::isLeapYear() {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

void Date::validate(int value) {
    if (value <= 0) {
        throw std::invalid_argument("This value is not allowed");
    }
}

bool Date::validateOverDay() {
    return this->getMonthDayLimit() < this->day;
}

void Date::monthCalculate(int amount) {
    int year = amount / 12;
    int month = amount % 12;
    this->day += countLeapYear(year);
    this->month += month;
    this->year += year;
}

void Date::dayCalculate(int amount) {
    int year = amount / 365;
    int otherDays1 = amount % 365;
    otherDays1 += countLeapYear(year);
    int otherMonth = otherDays1 / 12;
    int otherDays2 = otherDays1 % 12;
    this->day +=otherDays2;
    this->month += otherMonth;
    this->year += year;
}



MonthType Date::getMonthType() {
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

int Date::getMonthDayLimit() {
    return this->monthAmount[this->getMonthType()];
}