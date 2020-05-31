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

/**
 * \file
 * @fn matrix fileToMatrix(const string & filename)
 * The functions reads the information from the file named "filename" and is storing the information to a
 * matrix(vector<vector<stirng>>).
 * @param filename
 * @return matrix(vector<vector<string>>) with the information from the file "filename"
 */
// saving the data from CSV file to a matrix of vecs
matrix fileToMatrix(const string &filename);

/**
 * @fn void displayMatrix(const matrix &mat)
 * This function is displaying the table(matrix).
 * @param const matrix& mat
 */
// prints the matrix(file)
void displayMatrix(const matrix &mat);

/**
 * @fn bool usernameMatchesPassword(const mastrix& mat, const string& username, const string& password)
 * This function is checking in the user's database whether the inserted username and password match.
 * @param const matrix& mat
 * @param const string& username
 * @param const string& password
 * @return true or fals
 */
// checks whether username and password match
bool usernameMatchesPassword(const matrix &mat, const string &username, const string &password);

/**
 * @fn void averageGradeDestination(const matrix &mat, const string &destination)
 * This function is accepting a string(destination/location) and checking in the database how many
 * times the the location has been visited and returns the average grade from all users.
 * @param const matrix& mat
 * @param const string& destination
 */
// average grade for a destination
void averageGradeDestination(const matrix &mat, const string &destination);

/**
 * @fn bool isExisting(const matrix &mat, const string &check, int col)
 * This functions accepts a string and checks whether it is already in the database. The int col is used
 * to check just a column from the matrix. This functions is used to prevent registering two profiles with
 * the same username or email.
 * @param const matrix& mat
 * @param const string&  check
 * @param int col
 * @return true or false
 */
// checks the file whether an item(check) is already there
bool isExisting(const matrix &mat, const string &check, int col);

/**
 * @fn int rowOfUsername(const matrix &mat, const string &username)
 * The function is accepting a string(username) and iterates through the file until the
 * string is found and returns the number of the row. It is used when adding a friend in
 * order to determine at which row should the new friend(username) be added.
 * @param const matrix& mat
 * @param const string& username
 * @return int(on which row in the file is the username)
 */
// returns the row where the given username is
int rowOfUsername(const matrix &mat, const string &username);

/**
 * @fn int numberOfRowsInFile(const matrix& mat)
 * @param const matrix& mat
 * @return int(number of rows in the file)
 */
// returns the number of rows in a file
int numberOfRowsInFile(const matrix &mat);

/**
 * @fn void displayFriends(const matrix &mat, const string &username)
 * This function is accepting a string(username) and is displaying his friends.
 * @param const matrix& mat
 * @param const string& username
 */
// displays all friends of the loggedInUser
void displayFriends(const matrix &mat, const string &username);

/**
 * @fn bool isAlreadyFriend(const matrix &mat, const string &friendToBeAdded, const string &username)
 * The function is checking whether the inserted string(friendToBeAdded) is already in the friend list.
 * @param const matrix& mat
 * @param const string& friendToBeAdded
 * @param const string&username
 * @return true or false
 */
// check whether friendToBeAdded is already a friend
bool isAlreadyFriend(const matrix &mat, const string &friendToBeAdded, const string &username);

/**
 * @fn void displayFriendsDestionations(const string &loggedInUsername)
 * Displays all places where the friends of the loggedin user have been alonside with their comments
 * about the trip.
 * @param const string& loggedInUsername
 */
// displays which friends where have been and his comment of the trip
void displayFriendsDestionations(const string &loggedInUsername);

/**
 * @fn void displayInfoForParticularDestination()
 * The function is accepting a string(location) and displays all users who have been
 * to this location and their grade.
 */
// displays which users have been to a prticular destination and their grades
void displayInfoForParticularDestination();

matrix fileToMatrix(const string &filename) {
    char delimiter = ';';
    matrix result;
    string row, item;

    ifstream ins(filename);
    while (getline(ins, row)) {
        vec Row;
        stringstream ss(row);
        while (getline(ss, item, delimiter)) {
            Row.push_back(item);
        }
        result.push_back(Row);
    }
    ins.close();
    return result;
}

void displayMatrix(const matrix &mat) {
    for (const vec& row : mat) {
        for (const string& s : row)
            cout << setw(20) << left << s << " ";
        cout << endl;
    }
}

bool usernameMatchesPassword(const matrix &mat, const string &username, const string &password) {
    for (vec row : mat) {
        string s = row.at(0);
        if (s == username) {
            string p = row.at(1);
            if (p == password) {
                return true;
            }
        }
    }
    return false;
}

void averageGradeDestination(const matrix &mat, const string &destination) {
    double sum = 0, timesDest = 0;
    bool found = false;
    for (vec row : mat) {
        string s = row.at(0);
        if (s == destination) {
            found = true;
            string p = row.at(2);
            // converting string to int ("5" to 5)
            stringstream ss(p);
            int x = 0;
            ss >> x;
            sum += x;
            timesDest++;
        }
    }
    if (!found) {
        cout << "Such a destination does not exist in our database!" << endl << endl;
    } else {
        cout << "Average grade for " << destination << " is: " << sum / timesDest << "!" << endl << endl;
    }
}

bool isExisting(const matrix &mat, const string &check, int col) {
    for (vec row : mat) {
        string s = row.at(col);
        if (s == check) {
            return true;
        }
    }
    return false;
}

int rowOfUsername(const matrix &mat, const string &username) {
    int rowCounter = 0;
    for (vec row : mat) {
        string s = row.at(0);
        ++rowCounter;
        if (s == username) {
            return rowCounter;
        }
    }
    return 0;
}

int numberOfRowsInFile(const matrix &mat) {
    int numOfRows = 0;
    for (vec row : mat) {
        ++numOfRows;
    }
    return numOfRows;
}

void displayFriends(const matrix &mat, const string &username) {
    for (vec row : mat) {
        string s = row.at(0);
        if (s == username) {
            if (strcmp(row.at(3).c_str(), "Friends: ") == 0 || strcmp(row.at(3).c_str(), "Friends:") == 0) {
                cout << "You don't have any friends!\n\n";
            } else {
                cout << row.at(3) << endl << endl;
            }
        }
    }
}

bool isAlreadyFriend(const matrix &mat, const string &friendToBeAdded, const string &username) {
    for (vec row : mat) {
        string s = row.at(0);
        if (s == username) {
            string p = row.at(3);
            if (p.find(friendToBeAdded) != string::npos) {
                return true;
            }
        }
    }
    return false;
}

void displayFriendsDestionations(const string &loggedInUsername) {
    bool found = false;
    matrix usersFile = fileToMatrix("users.db");
    // getting the friends of the loggedInUser
    for (vec row : usersFile) {
        string username = row.at(0);
        if (username == loggedInUsername) {
            string friends = row.at(3);
            // open all destinations and print those of friends
            matrix destinationsFile = fileToMatrix("destinations.csv");
            for (vec Row : destinationsFile) {
                string user = Row.at(1);
                if (friends.find(user) != string::npos) {
                    found = true;
                    cout << Row.at(1) << " | " << Row.at(0) << " | " << Row.at(3) << "\n";
                }
            }
        }
    }
    if (!found) {
        cout << "Unfortunately none of your friends have visited any of the destinations in out database!\n";
    }
}

void displayInfoForParticularDestination() {
    string searchedDestination;
    cout << "Enter the destination you'd like to inform yourself about: ";
    cin.ignore();
    getline(cin, searchedDestination);
    matrix destinationsFile = fileToMatrix("destinations.csv");
    if(isExisting(destinationsFile, searchedDestination,0 )) {
        cout << "Users who has been to " << searchedDestination << " and their grade: \n";
        for (vec row : destinationsFile) {
            string destination = row.at(0);
            if (searchedDestination == destination) {
                cout <<  row.at(1) << " | " << row.at(2) << endl;
            }
        }
    }else {
        cout << "Unfortunately, nobody has been to " << searchedDestination << "!";
    }
}

#endif //TRAVELLERS_READFILE_H
