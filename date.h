//
// Created by bozhidar on 4/28/20.
//

#ifndef PROJECT7_DATE_H
#define PROJECT7_DATE_H

#include <iostream>

using namespace std;
/*! \class Date
    \brief A date class.

    This class is used to initialize dates. They are required to describe
    the duration of a trip. We initialize a period with two dates: starting date and ending date.
 */

/**
 * @param day is an integer
 * @param month is an integer
 * @param year is an integer
 */
class Date {
private:
    int day;       /**< Variable for day. */
    int month;     /**< Variable for month */
    int year;      /**< Variable for year */

public:
/**
 * A default constructor.
 */
    Date() {}
/**
 * A parametrized constructor.
 */
    Date(int, int, int);

/**
 *  Method setting the day.
 */
    [[nodiscard]] int Day() const;
/**
 *  Method setting the month.
 */
    [[nodiscard]] int Month() const;
/**
 *  Method setting the year.
 */
    [[nodiscard]] int Year() const;
/**
 *  A bool method comparing two dates.
 */
    // compares two dates
    bool operator<(const Date &) const;
/**
 * Overloaded operator(). It is setting new date(used in date validation).
 */
    Date operator()(int y, int m, int d);
/**
 * Overloaded operator<<.
 */
    friend ostream &operator<<(ostream &fout, const Date &dt);
};

#endif //PROJECT7_DATE_H
