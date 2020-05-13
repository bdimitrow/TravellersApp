//
// Created by bozhidar on 5/1/20.
//

#ifndef TRAVELLERS_APLICATION_H
#define TRAVELLERS_APLICATION_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "user.h"
#include "destination.h"
#include "date.h"
#include "readFile.h"
using namespace std;

void registration();
void login();
void menu();
bool isDateValid(const Date&);
void menuLogged(const User&);
void addDestination(const User&);
void addFriend(const User&);

void menu() {
    cout << " Welcome to Traveller's app menu! " << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "3. Exit" << endl;
    int choice;
    do {
        cout << "Choose an action: ";
        if(!(cin >> choice)) {
            cout << "Invalid choice! Please enter an integer! " << endl;
            cin.clear();                            // reset any error flags
            cin.ignore(10000, '\n');       // ignore any characters in the input buffer
        } else if(choice == 1 || choice == 2 || choice == 3) {
            switch (choice) {
                case 1:
                    registration();
                    break;
                case 2:
                    login();
                    break;
                case 3:
                    cout << "Thanks for using Travellers App!" << endl;
                    return exit(EXIT_SUCCESS);
            }
        }else {
            cout << "Invalid choice!" << endl;
        }
    } while(choice != 3);
}

void menuLogged(const User& loggedInUser) {
    cout << "Press 1 to add a trip!" << endl;
    cout << "Press 2 to display all destinations in the format location/user/grade/comment!" << endl;
    cout << "Press 3 to exit!" << endl;
    cout << "Press 4 to see the average grade for a destination!" << endl;
    cout << "Press 5 to add a friend!" << endl;
    cout << "Press 6 to display all your friends!" << endl;
    cout << "Press 7 to display where friends have been and their comments!" << endl;
    cout << "Press 8 to log out!" << endl;
    cout << "Press 9 to display information for particular destination!" << endl;
    int menuCh;
    do{
        cout << "Enter your choice: ";
        if(!(cin >> menuCh)){
            cout << "Invalid choice! Please enter an integer!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }else if(menuCh >= 1 && menuCh <= 9) {
            switch (menuCh) {
                case 1: {
                    // adding trip(destination);
                    addDestination(loggedInUser);
                    menuLogged(loggedInUser);
                }break;
                case 2: {
                    // displays all destinations/users/grades/comments
                    cout << "There are all recorded destinations: \n";
                    matrix destinations = fileToMatrix("destinations.csv");
                    displayMatrix(destinations);
                    cout << endl << endl;
                    menuLogged(loggedInUser);
                }break;
                case 3: {
                    // ends the program
                    cout << "End of program!\nThanks for using Traveller's App!" << endl;
                    return exit(EXIT_SUCCESS);
                }break;
                case 4: {
                    // displays average grade for particular destination
                    cout << "Enter the destination: ";
                    string destination;
                    cin.ignore();
                    getline(cin, destination);
                    matrix dests = fileToMatrix("destinations.csv");
                    cout << "Average grade of " << destination << " is: " << averageGradeDestination(dests, destination) << endl <<endl;
                    menuLogged(loggedInUser);
                }break;
                case 5: {
                    // adds a friend
                    addFriend(loggedInUser);
                    menuLogged(loggedInUser);
                }break;
                case 6: {
                    // displays the friends of the logged in user
                    matrix usersFile = fileToMatrix("users.csv");
                    displayFriends(usersFile, loggedInUser.getUsername());
                    menuLogged(loggedInUser);
                }break;
                case 7: {
                    // displays where friends have been and their comments;
                    cout << "There are the destinations visited by your friends and their comment about the trip: \n";
                    displayFriendsDestionations(loggedInUser.getUsername());
                    cout << endl << endl;
                    menuLogged(loggedInUser);
                }break;
                case 8: {
                    // log out
                    cout << "You have logged out!" << endl << endl;
                    menu();
                }break;
                case 9: {
                    // display user and his grade for a destination
                    displayInfoForParticularDestination();
                    cout << endl << endl;
                    menuLogged(loggedInUser);
                }break;
            }
        } else {
            cout << "Invalid choice!" << endl;
        }
    } while(menuCh != 3);
}

void addDestination(const User& loggedInUser) {
// adding trip(destination);
    string destinationName;
    unsigned grade;
    string comment;
    vector<string> photos;
    Destination beingAdded;

    // setting destination's location
    cout << "Insert destination's location: ";
    cin.ignore();
    getline(cin, destinationName);
    beingAdded.setDestination(destinationName);

    // setting period
    cout << "When did it start? Insert YY/MM/DD: ";
    int dayF, monthF, yearF;
    cin >> yearF >> monthF >> dayF;
    Date from(yearF, monthF, dayF);
    cout << "When did it end? Insert YY/MM/DD: ";
    int dayT, monthT, yearT;
    cin >> yearT >> monthT >> dayT;
    Date to(yearT, monthT, dayT);
    // validation
    while((isDateValid(from) == 0) || (isDateValid(to) == 0) || (!(from < (to)))) {
        cout << "Invalid data or period! Please reenter starting date as YY/MM/DD: ";
        int yearF2, monthF2, dayF2;
        cin >> yearF2 >> monthF2 >> dayF2;
        cout << "Please reenter ending date as YY/MM/DD: ";
        int yearT2, monthT2, dayT2;
        cin >> yearT2 >> monthT2 >> dayT2;
        from(yearF2,monthF2,dayF2);
        to(yearT2, monthT2, dayT2);
    }

    // setting grade
    cout << "Insert rating between 1 and 5: ";
    cin >> grade;
    while (grade < 1 || grade > 5) {
        cout << "Invalid grade. Please reenter: ";
        cin >> grade;
    }
    beingAdded.setGrade(grade);

    // setting comment
    cout << "Give day recommendation: ";
    cin.ignore();
    getline(cin, comment);
    beingAdded.setComment(comment);

    // setting photos
    cout << "Enter the number of photos you'd like to upload: ";
    int numPhotos;
    cin >> numPhotos;
    if(numPhotos != 0) {
        string nameOfPhoto, name;
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
                            cout << "Enter the name of photo number " << i + 1 << ": ";
                            cin >> name;
                            nameOfPhoto = name + ".jpeg";
                            photos.push_back(nameOfPhoto);
                            beingAdded.addPhoto(nameOfPhoto);
                        }
                    }break;
                    case 2: {
                        for (int i = 0; i < numPhotos; ++i) {
                            cout << "Enter the name of photo number " << i + 1 << ": ";
                            cin >> name;
                            nameOfPhoto = name + ".png";
                            photos.push_back(nameOfPhoto);
                            beingAdded.addPhoto(nameOfPhoto);
                        }
                    }break;
                }
            } else {
                cout << "Invalid choice!" << endl;
            }
        } while(choice != 1 && choice != 2);
    }

    // creating username.db file and saving info to it
    fstream fout;
    string fileUser = loggedInUser.getUsername() + ".db";
    char *fileUserChar = const_cast<char *>(fileUser.c_str());
    fout.open(fileUserChar, ios::out | ios::in | ios::app);
    if(fout.is_open()) {
        fout << beingAdded.getDestination() << ";"
             << from << ";"
             << to << ";"
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

    fstream destOut;
    destOut.open("destinations.csv", ios::in | ios::out | ios::app);
    if(destOut.is_open()) {
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

void addFriend(const User& loggedInUser) {
    string friendToBeAdded;
    cout << "Enter the username of the user you'd like to add as a friend: ";
    cin.ignore(); getline(cin, friendToBeAdded);
    matrix usersFile = fileToMatrix("users.csv");
    // checking whether such a username exists
    if(isExisting(usersFile, friendToBeAdded, 0)){
        // ensuring you can not add yourself as friend
        if(friendToBeAdded != loggedInUser.getUsername()) {
            // checking whether you are already friends
            if(!(isAlreadyFriend(usersFile, friendToBeAdded, loggedInUser.getUsername()))) {
                fstream file;
                file.open("users.csv", ios::in | ios::out | ios::app);
                fstream temp;
                temp.open("temp.txt", ios::in | ios::out | ios::trunc);
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
                // coping temp.txt. to users.csv
                ifstream in;
                ofstream out;
                in.open("temp.txt", ios::in | ios::out);
                out.open("users.csv", ios::in | ios::out | ios::trunc);
                char next;
                in.get(next);
                while (in.eof() == 0) {
                    out.put(next);
                    in.get(next);
                }
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

void registration() {
    string usernameRegister;
    string passwordRegister;
    string emailRegister;
    User beingReg;

    cout << "Enter a username: ";
    cin >> usernameRegister;
    beingReg.setUsername(usernameRegister);
    matrix users = fileToMatrix("users.csv");
    // if username is already taken, enter another
    while(isExisting(users, beingReg.getUsername(), 0)){
        cout << "Username is already taken. ";
        cout << "Enter a username: ";
        cin >> usernameRegister;
        beingReg.setUsername(usernameRegister);
    }

    cout << "Enter a password: ";
    cin >> passwordRegister;
    beingReg.setPassword(passwordRegister);

    cout << "Enter an email: ";
    cin >> emailRegister;
    beingReg.setEmail(emailRegister);
    // if email is already registered, enter another
    while(isExisting(users, beingReg.getEmail(), 2)){
        cout << "Email is already registered. ";
        cout << "Enter another one: ";
        cin >> emailRegister;
        beingReg.setEmail(emailRegister);
    }

    fstream fout;
    fout.open("users.csv", ios::out | ios::app);
    fout << beingReg.getUsername() << ";"
         << beingReg.getPassword() << ";"
         << beingReg.getEmail() << ";"
         << "Friends: " << "\n";
    fout.close();

    // creating file for each new profile
    fstream fuser;
    string fname = beingReg.getUsername() + ".db";
    char *fnameChar = const_cast<char *>(fname.c_str());
    fuser.open(fnameChar, ios::out | ios::app);
    cout << "You have been successfully registered!" << endl << endl;
    fuser.close();
    menu();
}

void login() {
    string usernameLogin;
    string passwordLogin;
    User userBeingLogged;

    cout << "Enter your username: ";
    cin >> usernameLogin;
    userBeingLogged.setUsername(usernameLogin);
    cout << "Enter your password: ";
    cin >> passwordLogin;
    userBeingLogged.setPassword(passwordLogin);

    matrix users = fileToMatrix("users.csv");
    // checking whether username and password matches
    if (!(usernameMatchesPassword(users, userBeingLogged.getUsername(), userBeingLogged.getPassword()))) {
        cout << "Incorrect data! Please try again: " << endl;
        login();
    } else {
        cout << "Successfully logged in!" << endl << endl;
        menuLogged(userBeingLogged);
    }
}

// checks whether the date is valid
bool isDateValid(const Date& date) {
    if(date.Year() <= 1900 || date.Year() >= 2023) {
        return false;
    }else if(!(1 <= date.Month() && date.Month() <= 12)) {
        return false;
    } else if(!(1 <= date.Day() && date.Day() <= 31)) {
        return false;
    } else if((date.Day() == 31) && (date.Month() == 2 || date.Month() == 4 ||
                date.Month() == 6 || date.Month() == 9 || date.Month() == 11)) {
        return false;
    } else if((date.Day() == 30) && (date.Month() == 2)) {
        return false;
    } else if((date.Month() == 2) && (date.Day() == 29) && (date.Year() % 4 != 0)) {
        return false;
    } else if((date.Month() == 2) && (date.Day() == 29) && (date.Year() % 400 == 0)) {
        return true;
    } else if((date.Month() == 2) && (date.Day() == 29) && (date.Year() % 100 == 0)) {
        return false;
    } else if((date.Month() == 2) && (date.Day() == 29) && (date.Year() % 4 == 0)) {
        return true;
    } else {
        return true;
    }
}





#endif //TRAVELLERS_APLICATION_H


