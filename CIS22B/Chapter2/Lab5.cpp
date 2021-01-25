// Rohith Vishwajith
// CIS22B
// Chapter 2
// XCode - Lab5.cpp
// 9/29/20
// Zybooks Lab 2.5 - Display a 2D Array Column by Column

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

    // Display the entire table one column per line, with one space after each element.
    /* Write your answer here */
    
    for(int i = 0; i < COLS; i++) {
        for(int j = 0; j < ROWS; j++) {
            cout << table[j][i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
