#ifndef TRAVELLERS_MENUS_H
#define TRAVELLERS_MENUS_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "user.h"
#include "destination.h"
#include "date.h"
#include "readFile.h"
#include "application.h"

using namespace std;

/**
 * \file
 * @fn void registration()
 * This function is used to create a profile. Firstly, an object of type User is created with default
 * values(empty strings for username, password and email). Then asking the user to input these values and
 * through the setters of class User the inserted values are assigned to the object. There is a validation to prevent
 * registering two profiles with the same username or email. Moreover two files
 * are being opened and through the getters of class User all the data of the object is saved into the files.
 */
// making registration
void registration();

/**
 * @fn void login()
 * This function is used when you try to log in. The user inserts two strings(username and password).
 * Firstly, the username is checked whether such a user exists and if it exists, then the function checkes whether
 * the inserted password matches the inserted username.
 */
// login when such a profile exists
void login();

/**
 * @fn void menu()
 * The functions prints REGISTER, LOGIN OR EXIT and awaits value to be inputted in order to know
 * action to execute.
 */
// welcoming menu
void menu();

/**
 * @fn void menuLogged(const User&)
 * The function is called when the process of logging in is successful. It prints all possible
 * functionalities of the program(adding a trip, adding a friend, displaying infromation and etc...). It also awaits
 * input in order to know which finction to call.
 * @param const User& loggedInUser
 */
// menu when you have logged in
void menuLogged(const User &loggedInUser);


void registration() {
    string usernameRegister, passwordRegister, emailRegister;
    User beingReg;

    cout << "Enter a username: ";
    cin >> usernameRegister;
    beingReg.setUsername(usernameRegister);
    matrix users = fileToMatrix("users.db");
    // if username is already taken, enter another
    while (isExisting(users, beingReg.getUsername(), 0)) {
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
    while (isExisting(users, beingReg.getEmail(), 2)) {
        cout << "Email is already registered. ";
        cout << "Enter another one: ";
        cin >> emailRegister;
        beingReg.setEmail(emailRegister);
    }
    userToFile(beingReg);
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

    matrix users = fileToMatrix("users.db");
    if (isExisting(users, userBeingLogged.getUsername(), 0)) {
        // checking whether username and password matches
        if (!(usernameMatchesPassword(users, userBeingLogged.getUsername(), userBeingLogged.getPassword()))) {
            cout << "Incorrect data! Please try again! " << endl;
            menu();
        } else {
            cout << "Successfully logged in!" << endl << endl;
            menuLogged(userBeingLogged);
        }
    } else {
        cout << "Such a user does not exist in our database! Please try again! " << endl << endl;
        menu();
    }
}

void menu() {
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "3. Exit" << endl;
    int choice;
    do {
        cout << "Choose an action: ";
        if (!(cin >> choice)) {
            cout << "Invalid choice! Please enter an integer! " << endl;
            cin.clear();                            // reset any error flags
            cin.ignore(10000, '\n');       // ignore any characters in the input buffer
        } else if (choice == 1 || choice == 2 || choice == 3) {
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
        } else {
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 3);
}

void menuLogged(const User &loggedInUser) {
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
    do {
        cout << "Enter your choice: ";
        if (!(cin >> menuCh)) {
            cout << "Invalid choice! Please enter an integer!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        } else if (menuCh >= 1 && menuCh <= 9) {
            switch (menuCh) {
                case 1: {
                    addDestination(loggedInUser);
                    menuLogged(loggedInUser);
                }
                    break;
                case 2: {
                    // displays all destinations/users/grades/comments
                    cout << "These are all recorded destinations in the format location/user/grade/comment: \n";
                    matrix destinations = fileToMatrix("destinations.csv");
                    displayMatrix(destinations);
                    cout << endl << endl;
                    menuLogged(loggedInUser);
                }
                    break;
                case 3: {
                    cout << "End of program!\nThanks for using Traveller's App!" << endl;
                    return exit(EXIT_SUCCESS);
                }
                case 4: {
                    // displays average grade for particular destination
                    cout << "Enter the destination: ";
                    string destination;
                    cin.ignore();
                    getline(cin, destination);
                    matrix dests = fileToMatrix("destinations.csv");
                    averageGradeDestination(dests, destination);
                    menuLogged(loggedInUser);
                }
                    break;
                case 5: {
                    addFriend(loggedInUser);
                    menuLogged(loggedInUser);
                }
                    break;
                case 6: {
                    matrix usersFile = fileToMatrix("users.db");
                    displayFriends(usersFile, loggedInUser.getUsername());
                    menuLogged(loggedInUser);
                }
                    break;
                case 7: {
                    cout << "These are the destinations visited by your friends and their comment about the trip: \n";
                    displayFriendsDestionations(loggedInUser.getUsername());
                    cout << endl << endl;
                    menuLogged(loggedInUser);
                }
                    break;
                case 8: {
                    cout << "You have logged out!" << endl << endl;
                    menu();
                }
                    break;
                case 9: {
                    // display the users and their grades for the entered destination
                    displayInfoForParticularDestination();
                    cout << endl << endl;
                    menuLogged(loggedInUser);
                }
                    break;
            }
        } else {
            cout << "Invalid choice!" << endl;
        }
    } while (menuCh != 3);
}


#endif //TRAVELLERS_MENUS_H
