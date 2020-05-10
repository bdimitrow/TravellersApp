//
// Created by bozhidar on 5/1/20.
//

#ifndef TRAVELLERS_READFILE_H
#define TRAVELLERS_READFILE_H

// Used to validate login operation!
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
    char delimiter = ',';
    matrix result;
    string row, item;

    ifstream in( filename );
    while( getline( in, row ) )
    {
        vec Row;
        stringstream ss( row );
        while ( getline (ss, item, delimiter ) ) Row.push_back(item );
        result.push_back(Row );
    }
    in.close();
    return result;
}

void printMatrix(const matrix &mat) {
    for (vec row : mat) {
        for(string s : row)
            cout << setw( 12 ) << left << s << " ";    // need a variable format really
            cout << '\n';
    }
}

void deleteRow(matrix &mat, int row) {
    if(row < mat.size()){
        mat.erase(mat.begin() + row);
    }
}

void matrixToFile(const matrix mat){
    fstream file;
    file.open("temporary.txt", ios::in | ios::out | ios::app);
    for (vec row : mat) {
        for(string s : row) {
            file << s << ',';
        }
        file << "\n";
    }
    file.close();
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
            stringstream ss(p);
            int x = 0;
            ss >> x;
            sum += x;
            timesDest++;
        }
    }
    return sum/timesDest;
}


bool isExisting(const matrix mat, string check, int col) {
    for( vec row : mat) {
        string s = row.at(col);
        if(s == check) {
            return true;
        }
    }
    return false;
}

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


#endif //TRAVELLERS_READFILE_H
