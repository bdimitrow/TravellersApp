//
// Created by bozhidar on 4/28/20.
//
#include "destination.h"
#include "date.h"

void Destination::setDestination(string dest) {
    destination = dest;
}

void Destination::setGrade(unsigned gr) {
    grade = gr;
}

void Destination::setComment(string comm) {
    comment = comm;
}

void Destination::addPhoto(const string &newPhotos) {
    photos.push_back(newPhotos);
}

void Destination::setFromDate(Date fr) {
    from = fr;
}

void Destination::setToDate(Date t) {
    to = t;
}
