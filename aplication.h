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

bool isRegistered(string, string);

void menu();
bool isDateValid(const Date&);

void registration() {
    string usernameRegister;
    string passwordRegister;
    string emailRegister;
    User beingReg;

    cout << "Enter a username: ";
    cin >> usernameRegister;
    beingReg.setUsername(usernameRegister);
    while (isRegistered(beingReg.getUsername(), "usernames.txt")) {
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
    while (isRegistered(beingReg.getEmail(), "emails.txt")) {
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

    fstream fnames;
    fnames.open("usernames.txt", ios::out | ios::app);
    fnames << beingReg.getUsername() << " ";

    fstream femail;
    femail.open("emails.txt", ios::out | ios::app);
    femail << beingReg.getEmail() << " ";

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
        cout << "Successfully logged in!" << endl;

        cout << "Press 1 to add a trip!" << endl;
        cout << "Press 2 to see all destinations with grades and comments!" << endl;
        int menuCh; cin >> menuCh;

        switch(menuCh) {
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

                // setting period          validation da si dobavq
                cout << "When did it start? Insert YY/MM/DD: ";
                int dayF, monthF, yearF;
                cin >> yearF >> monthF >> dayF;
                Date from(yearF, monthF, dayF);
                cout << "When did it end? Insert YY/MM/DD ";
                int dayT, monthT, yearT;
                cin >> yearT >> monthT >> dayT;
                Date to(yearT, monthT, dayT);
                // validation
                while((isDateValid(from) == 0) || (isDateValid(to) == 0) || (from < to) ) {
                    cout << "Invalid period, please reenter YY/MM/DD: ";
                    cin >> yearF >> monthF >> dayF;
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
                int num;
                cin >> num;
                string nameOfPhoto, name;
                cout << "Press (1) for JPEG photos and press (2) for PNG photos. ";
                int choice;
                cin >> choice;
                switch (choice) {
                    case 1:
                        for (int i = 0; i < num; ++i) {
                            cout << "Enter the name of photo number " << i + 1 << ": ";
                            cin >> name;
                            nameOfPhoto = name + ".jpeg";
                            photos.push_back(nameOfPhoto);
                            beingAdded.addPhoto(nameOfPhoto);
                        }
                        break;
                    case 2:
                        for (int i = 0; i < num; ++i) {
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
                for (int i = 0; i < num; ++i) {
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
            }break;
            case 2:
                matrix destinations = fileToMatrix("destinations.csv");
                printMatrix(destinations);
            break;
        }
    }
}

bool isDateValid(const Date& date) {
    if (! (1<= date.Month() && date.Month()<=12) )
        return false;
    if (! (1<= date.Day() && date.Day()<=31) )
        return false;
    if ( (date.Day() ==31) && (date.Month()==2 || date.Month()==4 || date.Month()==6 || date.Month()==9 || date.Month()==11) )
        return false;
    if ( (date.Day()==30) && (date.Month()==2) )
        return false;
    if ( (date.Month()==2) && (date.Day()==29) && (date.Year()%4!=0) )
        return false;
    if ( (date.Month()==2) && (date.Day()==29) && (date.Year()%400==0) )
        return true;
    if ( (date.Month()==2) && (date.Day()==29) && (date.Year()%100==0) )
        return false;
    if ( (date.Month()==2) && (date.Day()==29) && (date.Year()%4==0)  )
        return true;

    return true;
}

bool isRegistered(string word, string filename) {
    fstream fin;
    fin.open(filename, ios::in);
    string temp;
    while (fin >> temp) {
        if (word == temp) {
            return true;
        }
    }
    return false;
}

void menu() {
    // choice of action
    cout << "Traveller's app" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
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
        default:
            cout << "Invalid choice!";
            menu();
            break;
    } // end of choice
}


#endif //TRAVELLERS_APLICATION_H
