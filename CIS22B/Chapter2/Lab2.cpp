// Rohith Vishwajith
// CIS22B
// Chapter 2
// XCode - Lab2.cpp
// 9/29/20
// Zybooks Lab 2.2 - Access 2D Array Elements

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


    // Display the first element in the first row
    /* Write your answer here */
    cout << table[0][0] << endl;
    
    // Display the last element in the last row
    /* Write your answer here */
    cout << table[ROWS-1][COLS-1] << endl;
    
    // Display the second element in the first row
    /* Write your answer here */
    cout << table[0][1] << endl;

    return 0;
}

