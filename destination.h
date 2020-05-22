//
// Created by bozhidar on 4/27/20.
//

#ifndef PROJECT7_DESTINATION_H
#define PROJECT7_DESTINATION_H

#include <iostream>
#include <cstring>
#include <vector>
#include "user.h"
#include "date.h"

using namespace std;

class Destination {
public:
    Destination() {}

    void setDestination(string);

    void setGrade(unsigned);

    void setComment(string);

    void setFromDate(Date fr);

    void setToDate(Date t);

    void addPhoto(const string &);

    string getDestination() const { return destination; }

    unsigned getGrade() const { return grade; }

    string getComment() const { return comment; }

    vector<string> getPhotos() const { return photos; }

    Date getFromDate() const { return from; }

    Date getToDate() const { return to; }

private:
    string destination;
    unsigned grade;
    string comment;
    vector<string> photos;
    Date from;
    Date to;
};

#endif //PROJECT7_DESTINATION_H
