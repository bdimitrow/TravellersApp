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
    User(const string& = "", const string& = "", const string& = "", int = 0, int = 0);
    User(const User& other);
    User&operator=(const User& other);

    void setUsername(string);
    void setPassword(string);
    void setEmail(string);
    void addDestination(const Destination&);
    void addFriend(const User&);

    string getUsername() const { return username; };
    string getPassword() const { return password; };
    string getEmail() const { return email; };
    int getNumDestinations() const { return numDestinations; }
    vector<Destination> getDestinations() const { return destinations; }
    int getNumFriends() const { return numFriends; }
    vector<User> getFriends() const { return friends; }


    friend ostream &operator<<(ostream &out, const User &user);
    friend istream &operator>>(istream &in, User &user);
private:
    string username;
    string password;
    string email;
    vector<Destination> destinations{};
    int numDestinations;
    vector<User> friends{};
    int numFriends;
};

#endif //PROJECT7_USER_H
