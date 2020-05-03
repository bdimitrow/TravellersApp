//
// Created by bozhidar on 4/29/20.
//

#include "date.h"

Date::Date(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

int Date::Day() const { return day; }

int Date::Month() const { return month; }

int Date::Year() const { return year; }

void Date::print() const {
    cout << day << "." << month
         << "." << year << endl;
}

bool Date::operator<(const Date & other) {
    return ( year < other.year || (year == other.year && month < other.month) ||
             (year == other.year && month == other.month && day < other.day));
}

ostream &operator<<(ostream &fout, const Date &dt) {
    fout << dt.Day() << "." << dt.Month() << "." << dt.Year();
    return fout;
}
