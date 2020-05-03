//
// Created by bozhidar on 4/28/20.
//

#include "user.h"

User::User(const string& un, const string& pass, const string& em, int numDes, int numFr)
        : username(un), password(pass), email(em), numDestinations(numDes), numFriends(numFr) {
//    vector<Destination> tempDest(numDes, 0);
//    destinations = tempDest;
//    friends = new vector<User>(numFr);
}

User::User(const User &other) {
    username = other.username;
    password = other.password;
    email = other.email;
    for(int i = 0; i < other.numDestinations; ++i) {
        destinations[i] = other. destinations[i];
    }
    for(int i = 0; i < other.numFriends; ++i) {
        friends[i] = other.friends[i];
    }
}

User &User::operator=(const User &other) {
    if(this != &other) {
        username = other.username;
        password = other.password;
        email = other.email;
        for (int i = 0; i < other.numDestinations; ++i) {
            destinations[i] = other.destinations[i];
        }
        for (int i = 0; i < other.numFriends; ++i) {
            friends[i] = other.friends[i];
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

void User::addDestination(const Destination& newDest) {
    destinations.push_back(newDest);
}

void User::addFriend(const User &newFriend) {
    friends.push_back(newFriend);
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




