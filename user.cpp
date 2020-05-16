//
// Created by bozhidar on 4/28/20.
//

#include "user.h"

User::User(const string &un, const string &pass, const string &em, int numDes, int numFr)
        : username(un), password(pass), email(em), numDestinations(numDes), numFriends(numFr) {
    vector<string> friends = vector<string>(numFr);
}

User::User(const User &other) {
    username = other.username;
    password = other.password;
    email = other.email;
    numDestinations = other.numDestinations;
    numFriends = other.numFriends;
    for (unsigned i = 0; i < other.destinations.size(); ++i) {
        destinations[i] = other.destinations[i];
    }
}

User &User::operator=(const User &other) {
    if (this != &other) {
        username = other.username;
        password = other.password;
        email = other.email;
        numDestinations = other.numDestinations;
        numFriends = other.numFriends;
        for (int i = 0; i < other.destinations.size(); ++i) {
            destinations[i] = other.destinations[i];
        }
    }
    return *this;
}

void User::setUsername(string un) {
    username = un;
}

void User::setPassword(string pass) {
    password = pass;
}

void User::setEmail(string em) {
    email = em;
}

ostream &operator<<(ostream &out, const User &user) {
    out << "Username: " << user.username << endl << "Password: " << user.password << "Email:"
        << user.email << endl;
    return out;
}

istream &operator>>(istream &in, User &user) {
    in >> user.username >> user.password >> user.email;
    return in;
}




