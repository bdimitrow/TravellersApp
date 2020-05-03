//
// Created by bozhidar on 4/28/20.
//
#include "destination.h"
#include "date.h"

//Destination::Destination(string _dest, Date d1, Date d2, unsigned _gr, string _comm, int nphotos)
//        : destination(_dest), startDate(d1), endDate(d2), grade(_gr), comment(_comm), numPhotos(nphotos) {
////    photos = new vector<string>(nphotos,"");
//}


Destination::Destination(const Destination &other) {
    destination = other.destination;
//    startDate = other.startDate;
//    endDate = other.endDate;
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
//        startDate = other.startDate;
//        endDate = other.endDate;
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

void Destination::print() const {
    cout << "Destination: " << destination << endl << "Period: ";
//    startDate.print();
    cout << " - ";
//    endDate.print();
    cout << endl;
    cout << "Grade: " << grade << endl << "Comment: " << comment << endl << "Photos: ";
    for (int i = 0; i < getNumPhotos(); ++i) {
        cout << photos.at(i);
    }
    cout << endl;
}

ostream &operator<<(ostream &out, const Destination &dest) {
    out << "Destination: " << dest.destination << endl << "Period: ";
//    dest.startDate.print();
    out << " - ";
//    dest.endDate.print();
    out << "Grade: " << dest.grade << endl << "Comment: " << dest.comment << endl << "Photos: ";

    for (int i = 0; i << dest.getNumPhotos(); ++i) {
        out << dest.photos.at(i);
    }
    out << endl;
    return out;
}

//void Destination::setStartDate(int x, int y, int z) {
//    Date(x, y, z);
//}
//
//void Destination::setEndDate(int day, int month, int year) {
//    Date(day, month, year);
//}

