//
// Created by bozhidar on 4/29/20.
//

#include "date.h"

Date::Date(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}

int Date::Day() const { return day; }

int Date::Month() const { return month; }

int Date::Year() const { return year; }

void Date::print() const {
    cout << year << "-" << month
         << "-" << day << endl;
}

bool Date::operator<(const Date & other) const {
    return ( year < other.year || (year == other.year && month < other.month) ||
             (year == other.year && month == other.month && day < other.day));
}

ostream& operator<<(ostream &fout, const Date &dt) {
    fout << dt.Year() << "-" << dt.Month() << "-" << dt.Day();
    return fout;
}
