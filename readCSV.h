//
// Created by bozhidar on 5/1/20.
//

#ifndef TRAVELLERS_READCSV_H
#define TRAVELLERS_READCSV_H

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
matrix readCSV( string filename ) {
    char delim = ',';
    matrix result;
    string row, item;

    ifstream in( filename );
    while( getline( in, row ) )
    {
        vec R;
        stringstream ss( row );
        while ( getline (ss, item, delim ) ) R.push_back(item );
        result.push_back( R );
    }
    in.close();
    return result;
}

// checks whether username and password match
bool usernameMatchesPassword(const matrix mat, string username, string password){
    for(vec row : mat) {
        for (string s : row){
            if(s == username) {
                for(string p : row) {
                    if(p == password) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}


#endif //TRAVELLERS_READCSV_H
