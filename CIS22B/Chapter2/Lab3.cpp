// Rohith Vishwajith
// CIS22B
// Chapter 2
// XCode - Lab3.cpp
// 9/29/20
// Zybooks Lab 2.3 - Display Rows and Columns in a 2D Array

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

    // Display the elements in the first row on one line
    /* Write your answer here */
    for(int i = 0; i < COLS; i++) {
        cout << table[0][i] << " ";
    }
    cout << endl;
    
    // Display the elements in the last row on one line
    /* Write your answer here */
    for(int i = 0; i < COLS; i++) {
        cout << table[ROWS - 1][i] << " ";
    }
    cout << endl;
    
    // Display the elements in the last column on one line
    /* Write your answer here */
    for(int i = 0; i < ROWS; i++) {
        cout << table[i][COLS - 1] << " ";
    }
    cout << endl;

    // Display the elements in the second column on one line
    /* Write your answer here */
    for(int i = 0; i < ROWS; i++) {
        cout << table[i][1] << " ";
    }
    cout << endl;
    
    return 0;
}

