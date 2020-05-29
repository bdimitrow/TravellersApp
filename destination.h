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
/*! \class Destination
    \brief A destination class.

    This class is used to initialize trips. They are part of every user's database.
    Every trip consists of location, start date, end date, user's grade, user's comment and photos.
    Class date is used to maintain the dates in class Destination.
 */

/**
 * @param destination is type string keeping the location.
 * @param from is type Date keeping the start date.
 * @param to is type Date keeping the end date.
 * @param grade is type unsigned.
 * @param comment is type string.
 * @param photos is a vector of strings.
 */
class Destination {
public:
/**
 * A default constructor.
 */
    Destination() {}

/**
 * Methood setting the destination(location).
 */
    void setDestination(string);

/**
 * Method setting the grade.
 */
    void setGrade(unsigned);

/**
 * Method setting the comment.
 */
    void setComment(string);

/**
 * Method setting the start date.
 */
    void setFromDate(Date fr);

/**
 * Method setting the end date.
 */
    void setToDate(Date t);

/**
 *  Method adding a phone.
 */
    void addPhoto(const string &);

/**
 * Getter for destination.
 * @return string destination
 */
    string getDestination() const { return destination; }

/**
 * Getter for grade.
 * @return unsigned grade
 */
    unsigned getGrade() const { return grade; }

/**
 * Getter for comment.
 * @return string comment
 */
    string getComment() const { return comment; }

/**
 * Getter for photos.
 * @return vector<string> photos
 */
    vector<string> getPhotos() const { return photos; }

/**
 * Getter for start date.
 * @return Date from
 */
    Date getFromDate() const { return from; }

/**
 * Getter for end date.
 * @return Date to
 */
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
