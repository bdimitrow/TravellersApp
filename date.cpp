//
// Created by bozhidar on 4/29/20.
//

#include "date.h"

Date::Date(int y, int m, int d) {
    year = y;
    month = m;
    day = d;
}

int Date::Day() const { return day; }

int Date::Month() const { return month; }

int Date::Year() const { return year; }

bool Date::operator<(const Date &other) const {
    return (year < other.year || (year == other.year && month < other.month) ||
            (year == other.year && month == other.month && day < other.day));
}

ostream &operator<<(ostream &fout, const Date &dt) {
    fout << dt.Year() << "-" << dt.Month() << "-" << dt.Day();
    return fout;
}

Date Date::operator()(int y, int m, int d) {
    this->year = y;
    this->month = m;
    this->day = d;
    return *this;
}

bool Date::isDateValid(const Date &date) {
    if (date.Year() <= 1900 || date.Year() >= 2023) {
        return false;
    } else if (!(1 <= date.Month() && date.Month() <= 12)) {
        return false;
    } else if (!(1 <= date.Day() && date.Day() <= 31)) {
        return false;
    } else if ((date.Day() == 31) && (date.Month() == 2 || date.Month() == 4 ||
                                      date.Month() == 6 || date.Month() == 9 || date.Month() == 11)) {
        return false;
    } else if ((date.Day() == 30) && (date.Month() == 2)) {
        return false;
    } else if ((date.Month() == 2) && (date.Day() == 29) && (date.Year() % 4 != 0)) {
        return false;
    } else if ((date.Month() == 2) && (date.Day() == 29) && (date.Year() % 400 == 0)) {
        return true;
    } else if ((date.Month() == 2) && (date.Day() == 29) && (date.Year() % 100 == 0)) {
        return false;
    } else if ((date.Month() == 2) && (date.Day() == 29) && (date.Year() % 4 == 0)) {
        return true;
    } else {
        return true;
    }
}