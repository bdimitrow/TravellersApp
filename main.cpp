#include <iostream>
#include "application.h"
#include "user.h"
#include "date.h"
#include "readFile.h"
#include <fstream>

int main() {
    cout << "Welcome to Traveller's Аpp! " << endl;
    menu();
    return 0;
}


/** \mainpage About Project
 *
 *   \section First Project's aim
 *    The air of this project is to create an application to save information for different trips.
 *   In order to use the application every user should create his own profile by registering[saving his
 *   personal data(username, password and email) to a database]. After registering a personal database
 *   must be created where all trips of the user will be saved. Every trip should have a destination(location),
 *   time period, grade(between 1-5), comment and photos. Also every user can have friends with whom he can share
 *   information. Moreover he can see where his friends have been and what was their impression of the trip(grade and
 *   comment).
 *
 *
 */
