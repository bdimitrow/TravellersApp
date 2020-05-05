//
// Created by bozhidar on 4/28/20.
//

#ifndef PROJECT7_DATE_H
#define PROJECT7_DATE_H

#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date() {}
    Date(int , int  , int );
    [[nodiscard]] int Day() const;
    [[nodiscard]] int Month() const;
    [[nodiscard]] int Year() const;

    void print() const;

    bool operator<(const Date&);
    friend ostream& operator<<(ostream& fout, const Date& dt);
};


#endif //PROJECT7_DATE_H
