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

    Destination(const Destination &other);

    Destination &operator=(const Destination &other);

    void setDestination(string);

    void setGrade(unsigned);

    void setComment(string);

    void addPhoto(const string &);

    string getDestination() const { return destination; }

    unsigned getGrade() const { return grade; }

    string getComment() const { return comment; }

    int getNumPhotos() const { return numPhotos; }

    vector<string> getPhotos() const { return photos; }

    friend ostream &operator<<(ostream &out, const Destination &dest);

private:
    string destination;
    unsigned grade;
    string comment;
    vector<string> photos;
    int numPhotos;
};

#endif //PROJECT7_DESTINATION_H
