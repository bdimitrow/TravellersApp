//
// Created by bozhidar on 5/1/20.
//

#ifndef TRAVELLERS_READFILE_H
#define TRAVELLERS_READFILE_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

using vec = vector<string>;
using matrix = vector<vec>;

// saving the data from CSV file to a matrix of vecs
matrix fileToMatrix(string filename ) {
    char delimiter = ';';
    matrix result;
    string row, item;

    ifstream in(filename);
    while(getline(in, row)) {
        vec Row;
        stringstream ss(row);
        while (getline(ss, item, delimiter)) {
            Row.push_back(item );
        }
        result.push_back(Row );
    }
    in.close();
    return result;
}

void displayMatrix(const matrix &mat) {
    for (vec row : mat) {
        for(string s : row)
            cout << setw( 20 ) << left << s << " ";    // need a variable format really
            cout << '\n';
    }
}

// checks whether username and password match
bool usernameMatchesPassword(const matrix mat, string username, string password){
    for(vec row : mat) {
        string s = row.at(0);
        if(s == username) {
            string p = row.at(1);
            if(p == password) {
                return true;
            }
        }
    }
    return false;
}

// average grade for a destination
double averageGradeDestination(const matrix mat, string destination) {
    double sum = 0, timesDest = 0;
    for(vec row : mat) {
        string s = row.at(0);
        if(s == destination) {
            string p = row.at(2);
            // converting string to int ("5" = 5)
            stringstream ss(p);
            int x = 0;
            ss >> x;
            sum += x;
            timesDest++;
        }
    }
    return sum/timesDest;
}

// checks the file whether an item is already there
bool isExisting(const matrix mat, string check, int col) {
    for(vec row : mat) {
        string s = row.at(col);
        if(s == check) {
            return true;
        }
    }
    return false;
}

// returns the row where the given username is
int rowOfUsername(const matrix mat, string username) {
    int rowCounter = 0;
    for(vec row : mat) {
        string s = row.at(0);
        ++rowCounter;
        if(s == username) {
            return rowCounter;
        }
    }
}

int numberOfRowsInFile(const matrix mat){
    int numOfRows = 0;
    for(vec row : mat){
        ++numOfRows;
    }
    return numOfRows;
}

// displays all friends of the loggedInUser
void displayFriends(const matrix mat, string username) {
    for(vec row : mat){
        string s = row.at(0);
        if(s == username) {
            cout << row.at(3) << endl << endl;
        }
    }
}

// check whether friendToBeAdded is already a friend
bool isAlreadyFriend(const matrix mat, string friendToBeAdded, string username) {
    for(vec row : mat){
        string s = row.at(0);
        if(s == username) {
            string p = row.at(3);
            if(p.find(friendToBeAdded) != string::npos){
                return true;
            }
        }
    }
    return false;
}

// displays which friends where have been and his comment of the trip
void displayFriendsDestionations(string loggedInUserName) {
    matrix usersFile = fileToMatrix("users.csv");
    // getting the friends of the loggedInUser
    for(vec row : usersFile) {
        string username = row.at(0);
        if(username == loggedInUserName) {
            string friends = row.at(3);
            // open all destinations and print those of friends
            matrix destinationsFile = fileToMatrix("destinations.csv");
            for(vec Row : destinationsFile) {
                string user = Row.at(1);
                if(friends.find(user)){
                    cout << Row.at(1) << " | " << Row.at(0) << " | " << Row.at(3) << "\n";
                }
            }
        }
    }
}

void displayInfoForParticularDestination(){
    string searchedDestination;
    cout << "Enter the destination you'd like to inform yourself: ";
    cin.ignore(); getline(cin, searchedDestination);
    matrix destinationsFile = fileToMatrix("destinations.csv");
    for(vec row : destinationsFile) {
        string destination = row.at(0);
        if(searchedDestination == destination) {
            cout << row.at(0) << " | " << row.at(1) << " | " << row.at(2) << endl;
        }
    }
}

#endif //TRAVELLERS_READFILE_H
