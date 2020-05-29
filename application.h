//
// Created by bozhidar on 5/1/20.
//

#ifndef TRAVELLERS_APPLICATION_H
#define TRAVELLERS_APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "user.h"
#include "destination.h"
#include "date.h"
#include "readFile.h"

using namespace std;

/**
 * @file
 * @fn void addDestination(const User &)
 * This function is accepting an object of type User and is used to add a trip(destination) to the User's database.
 * Firstly, the function initialize an "empty" destination and uses other functions and the setters of class Destination
 * to set location, period, grade, comment and photos to the location.
 * @param const User& loggedInUser
 */
// adding destination(trip)
void addDestination(const User &);

/**
 * @fn void addFriend(const User &)
 * The function accepts an object of type User and is adding another User's username in the friend list of the
 * accepted object. Some vertifications are made. Firstly, whether such a username exists in the database. Secondly,
 * ensuring that the user is not trying to add himself as friend. Then checking whether the inputted username is
 * already in the friend list.
 * @param const User& loggedInUser
 */
void addFriend(const User &);

/**
 * @fn void destinationToFile(const User &, const Destination &, int)
 *  The function accepts two object one ot type Destination and one of type User. Afterwards is using the getters
 *  of class Destinaiton to save the destination to the accepted User's databse and to a file called "destinations.csv"
 *  which is used to get information about a destination.
 *  @param const User& logedInUser
 *  @param const Destination& beingAdded
 */
// creating username.db file and saving destination to it and destinations.csv file
void destinationToFile(const User &, const Destination &, int);

/**
 * @fn void userToFile(const User &beingReg)
 * The function accepts User and though the getter's method is saving the user's username, password and email
 * to users.db file and creates his own database file.
 * @param const User& beingReg
 */
// saving the user's data to users.db and creating his own db
void userToFile(const User &beingReg);

/**
 * @fn string addLocation()
 * This function is asking the user for the location of the trip.
 * @return string(location)
 */
// adding location(destination) of the trip
string addLocation();

/**
 * @fn Date addStartDate()
 * This function is asking the user to input the start date and is initializing an object of type Date.
 * @return Date(start date)
 */
// adding starting date of the trip
Date addStartDate();

/**
 * @fn Date addEndDate()
 * This function is asking the user to input the end date and is initializing an object of type Date.
 * @return Date(end date)
 */
// adding ending date of the trip
Date addEndDate();

/**
 * @fn unsigned addGrade()
 * This function is asking the user to input a grade between 1-5 and has a validation.
 * @return unsigned(grade)
 */
// adding grade for the tirp
unsigned addGrade();

/**
 * @fn stirng addComment()
 * This fucntion is asking the user to input a comment about the trip.
 * @return string(comment)
 */
// adding comment about the trip
string addComment();

/**
 * @fn vector<string> addPhotos(int)
 * This function is asking the user to input the name of the photos that he'd like to add to the database.
 * Beforewards the user has to choose what the extenstions of the photos are going to be.
 * @return vector<string>(photos)
 * @param int numPhotos
 */
// adding photos from the trip
vector<string> addPhotos(int);

void addDestination(const User &loggedInUser) {
    // declaration of destination
    Destination beingAdded;
    // setting location
    beingAdded.setDestination(addLocation());
    // setting period
    Date from = addStartDate();
    Date to = addEndDate();
    // validation of period
    while ((from.isDateValid(from) == 0) || (to.isDateValid(to) == 0) || (!(from < (to)))) {
        cout << "Invalid data or period! Please reenter!\n";
        from = addStartDate();
        to = addEndDate();
    }
    beingAdded.setFromDate(from);
    beingAdded.setToDate(to);
    // setting grade
    beingAdded.setGrade(addGrade());
    // setting comment
    beingAdded.setComment(addComment());
    // setting photos
    cout << "Enter the number of photos you'd like to upload: ";
    int numPhotos;
    cin >> numPhotos;
    if (numPhotos != 0) {
        vector<string> snimki = addPhotos(numPhotos);
        for (auto &i : snimki) {
            beingAdded.addPhoto(i);
        }
    }
    destinationToFile(loggedInUser, beingAdded, numPhotos);
}

string addLocation() {
    // setting destination's location
    string destinationName;
    cout << "Insert destination's location: ";
    cin.ignore();
    getline(cin, destinationName);
    return destinationName;
}

Date addStartDate() {
    Date fr;
    cout << "When did it start? Insert YY/MM/DD: ";
    int dayF, monthF, yearF;
    cin >> yearF >> monthF >> dayF;
    fr(yearF, monthF, dayF);
    return fr;
}

Date addEndDate() {
    Date t;
    cout << "When did it end? Insert YY/MM/DD: ";
    int dayT, monthT, yearT;
    cin >> yearT >> monthT >> dayT;
    t(yearT, monthT, dayT);
    return t;
}

unsigned addGrade() {
    cout << "Insert rating between 1 and 5: ";
    unsigned grade;
    cin >> grade;
    while (grade < 1 || grade > 5) {
        cout << "Invalid grade. Please reenter: ";
        cin >> grade;
    }
    return grade;
}

string addComment() {
    // setting comment
    cout << "Give day recommendation: ";
    string comment;
    cin.ignore();
    getline(cin, comment);
    return comment;
}

vector<string> addPhotos(int numPhotos) {
    vector<string> photos;
    string photoNameWithExtension, photoName;
    int choice;
    do {
        cout << "Press (1) for JPEG photos and press (2) for PNG photos. ";
        if (!(cin >> choice)) {
            cout << "Invalid choice! Please enter an integer! " << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        } else if (choice == 1 || choice == 2) {
            switch (choice) {
                case 1: {
                    for (int i = 0; i < numPhotos; ++i) {
                        cout << "Enter the photoName of photo number " << i + 1 << ": ";
                        cin >> photoName;
                        photoNameWithExtension = photoName + ".jpeg";
                        photos.push_back(photoNameWithExtension);
                    }
                }
                    break;
                case 2: {
                    for (int i = 0; i < numPhotos; ++i) {
                        cout << "Enter the photoName of photo number " << i + 1 << ": ";
                        cin >> photoName;
                        photoNameWithExtension = photoName + ".png";
                        photos.push_back(photoNameWithExtension);
                    }
                }
                    break;
            }
        } else {
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 1 && choice != 2);
    return photos;
}

void destinationToFile(const User &loggedInUser, const Destination &beingAdded, int numPhotos) {
    // adding the destination to the file of the loggedInUser
    fstream fout;
    string fileUser = loggedInUser.getUsername() + ".db";
    char *fileUserChar = const_cast<char *>(fileUser.c_str());
    fout.open(fileUserChar, ios::out | ios::app);
    if (!fout.is_open()) {
        cerr << "Unable to open file!\n";
    }
    if (fout.is_open()) {
        fout << beingAdded.getDestination() << ";"
             << beingAdded.getFromDate() << ";"
             << beingAdded.getToDate() << ";"
             << beingAdded.getGrade() << ";"
             << beingAdded.getComment() << ";";
        for (int i = 0; i < numPhotos; ++i) {
            fout << beingAdded.getPhotos().at(i) << " ";
        }
        fout << "\n";
        fout.close();
    } else {
        cerr << "Unable to open the file!" << endl;
    }
    // adding the destination to destinations.csv file
    fstream destOut;
    destOut.open("destinations.csv", ios::out | ios::app);
    if (!destOut.is_open()) {
        cerr << "Unable to open file!\n";
    }
    if (destOut.is_open()) {
        destOut << beingAdded.getDestination() << ";"
                << loggedInUser.getUsername() << ";"
                << beingAdded.getGrade() << ";"
                << beingAdded.getComment()
                << "\n";
        destOut.close();
    } else {
        cerr << "Unable to open the file!" << endl;
    }
    cout << "Successfully added the entered destination!";
    cout << endl << endl;
}

void userToFile(const User &beingReg) {
    fstream fout;
    fout.open("users.db", ios::out | ios::app);
    if (!fout.is_open()) {
        cerr << "Unable to open file!\n";
    }
    fout << beingReg.getUsername() << ";"
         << beingReg.getPassword() << ";"
         << beingReg.getEmail() << ";"
         << "Friends: " << "\n";
    fout.close();
    // creating .db file for every new profile
    fstream fuser;
    string fname = beingReg.getUsername() + ".db";
    char *fnameChar = const_cast<char *>(fname.c_str());
    fuser.open(fnameChar, ios::out | ios::app);
    if (!fuser.is_open()) {
        cerr << "Unable to open file!\n";
    }
    cout << "You have been successfully registered!" << endl << endl;
    fuser.close();
}

void copyFileToAnotherFile() {
    // coping temp.txt. to users.db
    ifstream in;
    ofstream out;
    in.open("temp.txt", ios::in);
    if (!in.is_open()) {
        cerr << "Unable to open file!\n";
    }
    out.open("users.db", ios::out | ios::trunc);
    if (!out.is_open()) {
        cerr << "Unable to open file!\n";
    }
    char next;
    in.get(next);
    while (in.eof() == 0) {
        out.put(next);
        in.get(next);
    }
}

void stringToUsersDB(const matrix &usersFile, const User &loggedInUser, const string &friendToBeAdded) {
    fstream file;
    file.open("users.db", ios::in | ios::out | ios::app);
    if (!file.is_open()) {
        cerr << "Unable to open file!\n";
    }
    fstream temp;
    temp.open("temp.txt", ios::in | ios::out | ios::trunc);
    if (!temp.is_open()) {
        cerr << "Unable to open file!\n";
    }
    string line;
    for (int row = 1; getline(file, line) && row < numberOfRowsInFile(usersFile) + 1; ++row) {
        if (row == rowOfUsername(usersFile, loggedInUser.getUsername())) {
            line = line + friendToBeAdded + " ";
            temp << line << "\n";
        } else {
            temp << line << "\n";
        }
    }
    file.close();
    temp.close();
}

void addFriend(const User &loggedInUser) {
    string friendToBeAdded;
    cout << "Enter the username of the user you'd like to add as a friend: ";
    cin.ignore();
    getline(cin, friendToBeAdded);
    matrix usersFile = fileToMatrix("users.db");
    // checking whether such a username exists
    if (isExisting(usersFile, friendToBeAdded, 0)) {
        // ensuring you can not add yourself as friend
        if (friendToBeAdded != loggedInUser.getUsername()) {
            // checking whether you are already friends
            if (!(isAlreadyFriend(usersFile, friendToBeAdded, loggedInUser.getUsername()))) {
                stringToUsersDB(usersFile, loggedInUser, friendToBeAdded);
                // coping temp.txt. to users.db
                copyFileToAnotherFile();
                cout << friendToBeAdded << " has been successfully added as friend! " << endl << endl;
            } else {
                cout << "You are already friends!" << endl << endl;
            }
        } else {
            cout << "You can not add yourself as a friend!" << endl << endl;
        }
    } else {
        cout << "Such a user does not exist!" << endl << endl;
    }
}


#endif //TRAVELLERS_APPLICATION_H
