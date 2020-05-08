//
// Created by bozhidar on 5/1/20.
//

#ifndef TRAVELLERS_APLICATION_H
#define TRAVELLERS_APLICATION_H

#include <iostream>
#include <fstream>
#include <string>
#include "user.h"
#include "date.h"
#include "readFile.h"

using namespace std;
void registration();
void login();
void menu();
bool isDateValid(const Date&);
void menuLogged(User);

void registration() {
    string usernameRegister;
    string passwordRegister;
    string emailRegister;
    User beingReg;

    cout << "Enter a username: ";
    cin >> usernameRegister;
    beingReg.setUsername(usernameRegister);
    matrix users = fileToMatrix("users.csv");
    while(isRegisteredIn(users, beingReg.getUsername(), 0)){
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
    while(isRegisteredIn(users, beingReg.getEmail(), 2)){
        cout << "Email is already registered. ";
        cout << "Enter another one: ";
        cin >> emailRegister;
        beingReg.setEmail(emailRegister);
    }

    fstream fout;
    fout.open("users.csv", ios::out | ios::app);
    fout << beingReg.getUsername() << ","
         << beingReg.getPassword() << ","
         << beingReg.getEmail()
         << "\n";
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
    User beingLogged;

    cout << "Enter your username: ";
    cin >> usernameLogin;
    beingLogged.setUsername(usernameLogin);
    cout << "Enter your password: ";
    cin >> passwordLogin;
    beingLogged.setPassword(passwordLogin);

    matrix users = fileToMatrix("users.csv");
    if (!(usernameMatchesPassword(users, beingLogged.getUsername(), beingLogged.getPassword()))) {
        cout << "Incorrect data! Please try again: " << endl;
        login();
    } else {
        cout << "Successfully logged in!" << endl << endl;

        menuLogged(beingLogged);
    }
}


bool isDateValid(const Date& date) {
    if(!(1 <= date.Month() && date.Month() <= 12)) {
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

void menu() {
    // choice of action
    cout << "Traveller's app" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "3. Exit" << endl;
    cout << "Choose an action: ";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            registration();
            break;
        case 2:
            login();
            break;
        case 3:
            cout << "Thank you for using Traveller's App!" << endl;
        default:
            cout << "Invalid choice!";
            menu();
            break;
    } // end of choice
}

void menuLogged(User beingLogged) {
    cout << "Press 1 to add a trip!" << endl;
    cout << "Press 2 to display all destinations, user's grades and comments!" << endl;
    cout << "Press 3 to exit!" << endl;
    cout << "Press 4 to see the average grade for a destination!" << endl;
    cout << "Press 5 to add a friend!" << endl;
    cout << "Press 6 to display all your friends!" << endl;
    int menuCh; cin >> menuCh;

    switch (menuCh) {
            // adds destination
        case 1: {
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
                cout << "Invalid period! Please reenter starting date as YY/MM/DD: ";
                cin >> yearF >> monthF >> dayF;
                cout << "Please reenter ending date as YY/MM/DD: ";
                cin >> yearT >> monthT >> dayT;
                Date from(yearF,monthF,dayF);
                Date to(yearT, monthT, dayT);
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
                cout << "Press (1) for JPEG photos and press (2) for PNG photos. ";
                int choice;
                cin >> choice;
                switch (choice) {
                    case 1:
                        for (int i = 0; i < numPhotos; ++i) {
                            cout << "Enter the name of photo number " << i + 1 << ": ";
                            cin >> name;
                            nameOfPhoto = name + ".jpeg";
                            photos.push_back(nameOfPhoto);
                            beingAdded.addPhoto(nameOfPhoto);
                        }
                        break;
                    case 2:
                        for (int i = 0; i < numPhotos; ++i) {
                            cout << "Enter the name of photo number " << i + 1 << ": ";
                            cin >> name;
                            nameOfPhoto = name + ".png";
                            photos.push_back(nameOfPhoto);
                            beingAdded.addPhoto(nameOfPhoto);
                        }
                        break;
                    default:
                        cout << "Invalid format of photos." << endl;
                }
            }

            // creating username.db file and saving info to it
            fstream fout;
            string fileUser = beingLogged.getUsername() + ".db";
            char *fileUserChar = const_cast<char *>(fileUser.c_str());
            fout.open(fileUserChar, ios::out | ios::in | ios::app);

            fout << beingAdded.getDestination() << ","
                 << from << ","
                 << to << ","
                 << beingAdded.getGrade() << ","
                 << beingAdded.getComment() << ",";
            for (int i = 0; i < numPhotos; ++i) {
                fout << beingAdded.getPhotos().at(i) << " ";
            }
            fout << "\n";
            fout.close();

            fstream destOut;
            destOut.open("destinations.csv", ios::in | ios::out | ios::app);
            destOut << beingAdded.getDestination() << ","
                    << beingLogged.getUsername() << ","
                    << beingAdded.getGrade() << ","
                    << beingAdded.getComment()
                    << "\n";
            destOut.close();
            cout << "Successfully added the entered destination!";
            cout << endl << endl;
            menuLogged(beingLogged);
        }break;
            // displays all destinations/users/grades/comments
        case 2: {
            matrix destinations = fileToMatrix("destinations.csv");
            printMatrix(destinations);
            cout << endl << endl;
            menuLogged(beingLogged);
        }break;
            // ends the program
        case 3:{
            cout << "End of program!" << endl;
        }break;
            // displays average grade for particular destination
        case 4:{
            cout << "Enter the destination: ";
            string destination;
            cin.ignore();
            getline(cin, destination);
            matrix dests = fileToMatrix("destinations.csv");
            cout << "Average grade of " << destination << " is: " << averageGradeDestination(dests, destination);
        }break;
            // adds a friend
        case 5:{
            string friendAdded;
            vector<string> mates;
            cout << "Enter the name of the user you'd like to add as a friend: ";
            cin.ignore(); getline(cin, friendAdded);
            matrix friends = fileToMatrix("users.cvs");
            if(isRegisteredIn(friends, friendAdded, 0)){
                mates.push_back(friendAdded);
            }
        }break;
        // displays all friends of beingLogged
        case 6: {

        }break;
    }
}



#endif //TRAVELLERS_APLICATION_H
