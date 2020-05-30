#include <iostream>
#include "application.h"
#include "user.h"
#include "date.h"
#include "readFile.h"
#include "menus.h"
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
 *  \subsection Github
 *  https://github.com/bdimitrow/TravellersApp
 *
 *  \section Second Happy path
 *   *  The "create a profile" scenario happens just in case the username and the email are not already taken. <br>
 *   *  The "logging in" scenario happens only when existing username and matching it password are entered. <br>
 *   *  The "adding a location" scenario happens when the user has successfully logged in and has choose option 1 from the menu.<br>
 *  \subsection running Run the program
 *  Output: Welcome to Traveller's Аpp!
            1. Register
            2. Login
            3. Exit <br>
            Choose an action:
 *  \subsection create Create a profile
   Input: 1<br>
   Output: Enter a username:<br>
   Input: testusername<br>
   Output: Enter a password:<br>
   Input: parolae43<br>
   Output: Enter an email:<br>
   Input: testde.bg<br>
   Output: You have been successfully registered!

   \subsection login Logging in
   Input: 2<br>
   Output: Enter a username: <br>
   Input: testusername<br>
   Output: Enter a password: <br>
   Input: parolatae43 <br>
   Output: Successfully logged in! <br>
   <br> The menuLogged is displayed now! <br>

    \subsection locadd Adding a location
    Output: Insert destination's location:<br>
    Input: Gorna Malina<br>
    Output: When did it start? Insert YY/MM/DD:<br>
    Input: 2020 2 3<br>
    Output: When did it end? Insert YY/MM/DD:<br>
    Input: 2020 2 5<br>
    Ouput: Insert rating between 1 and 5:<br>
    Input: 3<br>
    Ouput: Give a recommendation:<br>
    Input: Everything was perfect! However on the way back home we had an accident.<br>
    Output: Enter the number of photos you'd like to upload: <br>
    Input: 2<br>
    Output: Press (1) for JPEG photos and press (2) for PNG photos. <br>
    Input: 2<br>
    Output: Enter the photoName of photo number 1: <br>
    Input: hotel<br>
    Output: Enter the photoName of photo number 2: <br>
    Input: bikes<br>
    Output: Successfully added the entered destination!<br>

    The following has been added to the logged in user's database: <br>
    Gorna Malina;2020-2-3;2020-2-5;3;Everything was perfect! However on the way back home we had an accident.;hotel.png bikes.png <br>

 */
