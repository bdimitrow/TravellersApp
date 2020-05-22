//
// Created by bozhidar on 4/28/20.
//
#include "destination.h"
#include "date.h"

Destination::Destination(const Destination &other) {
    destination = other.destination;
    grade = other.grade;
    comment = other.comment;
    numPhotos = other.numPhotos;
    for (int i = 0; i < other.numPhotos; ++i) {
        photos[i] = other.photos[i];
    }
}

Destination &Destination::operator=(const Destination &other) {
    if (this != &other) {
        destination = other.destination;
        grade = other.grade;
        comment = other.comment;
        numPhotos = other.numPhotos;
        for (int i = 0; i < other.numPhotos; ++i) {
            photos[i] = other.photos[i];
        }
    }
    return *this;
}

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

ostream &operator<<(ostream &out, const Destination &dest) {
    out << "Destination: " << dest.destination << endl << "Period: " <<
        dest.from << " - " << dest.to << endl << "Grade: " << dest.grade
        << endl << "Comment: " << dest.comment << endl << "Photos: ";
    for (int i = 0; i < dest.getNumPhotos(); ++i) {
        out << dest.photos.at(i) << " ";
    }
    out << endl;
    return out;
}

