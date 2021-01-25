// Rohith Vishwajith
// CIS22B
// Chapter 2
// XCode - Lab4.cpp
// 9/29/20
// Zybooks Lab 2.4 - Display a 2D Array Row by Row

#include <iostream>

using namespace std;

const int ROWS = 3;         // maximum number of rows
const int COLS = 4;         // maximum number of columns

int main() {

    double table[ROWS][COLS] = {   //Array with 3 ROWS and 4 COLumnS
        {10, 90, 50, 30},
        {20, 40, 60, 80},
        {35, 55, 85, 75}
    };  // initializing the array

    // Display the entire table one row per line, with one space after each element.
    /* Write your answer here */
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
