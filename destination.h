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
//    Destination(string dest, Data edno, Date dve, unsigned gr, string com, int numph) {
//        destination = dest;
//        edno = startDate;
//        dve = endDate;
//        gr = grade;
//        com = comment;
//        numph = numPhotos;
//    }
    Destination(const Destination &other);
    Destination &operator=(const Destination& other);

    void setDestination(string);
    void setGrade(unsigned);
    void setComment(string);
//    void setStartDate(int, int, int);
//    void setEndDate(int,int,int);
    void addPhoto(const string&);
    void print() const;

    string getDestination() const { return destination; }
//    Date getStartDate() const { return startDate; }
//    Date getEndDate() const { return endDate; }
    unsigned getGrade() const { return grade; }
    string getComment() const { return comment; }
    int getNumPhotos() const { return numPhotos; }
    vector<string> getPhotos() const { return photos; }

    friend ostream &operator<<(ostream &out, const Destination &dest);

private:
    string destination;
//    Date startDate;
//    Date endDate = Date(0, 0, 0);
    unsigned grade;
    string comment;
    vector<string> photos;
    int numPhotos;
};

//friend validDate(Const Date )

#endif //PROJECT7_DESTINATION_H
