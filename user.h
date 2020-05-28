//
// Created by bozhidar on 4/27/20.
//

#ifndef PROJECT7_USER_H
#define PROJECT7_USER_H

#include <cstring>
#include <vector>
#include <iostream>
#include "destination.h"

using namespace std;
/*! \class User
    \brief A user class.

    This class is used to initialize a user. The user is the main structure part of the project.
    Every creation of a profile is initializing a new User. In order to log in you need to access a User.
 */

/**
 * @param username is type string.
 * @param password is type string.
 * @param email is type string.
 */

class Destination;

class User {
public:
    /**
    *  A parametrized constructor with default vlaues.
    */
    User(const string & = "", const string & = "", const string & = "", int = 0);

/**
 *  A copy constructor.
 */
    User(const User &other);

/**
 * Operator=.
 */
    User &operator=(const User &other);

/**
 * Method setting the username.
 */
    void setUsername(string);

/**
 * Method setting the password.
 */
    void setPassword(string);

/**
 * Method setting the email.
 */
    void setEmail(string);

/**
 * Getter for username.
 */
    string getUsername() const { return username; };

/**
 * Getter for password.
 */
    string getPassword() const { return password; };

/**
 * Getter for email.
 */
    string getEmail() const { return email; };

/**
 * Overloaded operator<<.
 */
    friend ostream &operator<<(ostream &out, const User &user);

/**
 * Overloaded operator>>.
 */
    friend istream &operator>>(istream &in, User &user);

private:
    string username;
    string password;
    string email;
    vector<Destination> destinations{};
    int numDestinations;
};

#endif //PROJECT7_USER_H
