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


class Destination;

class User {
public:
    User(const string & = "", const string & = "", const string & = "", int = 0, int = 0);

    User(const User &other);

    User &operator=(const User &other);

    void setUsername(string);

    void setPassword(string);

    void setEmail(string);

    string getUsername() const { return username; };

    string getPassword() const { return password; };

    string getEmail() const { return email; };

    friend ostream &operator<<(ostream &out, const User &user);

    friend istream &operator>>(istream &in, User &user);

private:
    string username;
    string password;
    string email;
    vector<Destination> destinations{};
    int numDestinations;
    int numFriends;
};

#endif //PROJECT7_USER_H
