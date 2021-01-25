// Rohith Vishwajith
// CIS22B
// Chapter 2
// XCode - Lab6.cpp
// 9/29/20
// Zybooks Lab 2.6 - 2D Arrays and Functions

#include <iostream>

using namespace std;

const int ROWS = 10;         // maximum number of rows
const int COLS = 12;         // maximum number of columns

void DisplayTable(double table[][COLS], int rows, int cols);
// --------------------------^^^^^ this is a must with 2D arrays
int main() {

    double table[ROWS][COLS] = {   //Array with 3 ROWS and 4 COLumnS
        {1, 9, 5, 3},
        {2, 4, 6, 8},
        {3, 5, 8, 7}
    };  // initializing the array
   int rows = 3; // the actual number of rows
   int cols = 5; // the actual number of columns
   
   // A more general approach is to pass three parameters to the display function
   DisplayTable(table, rows, cols);
   DisplayTable(table, ROWS, COLS);
   DisplayTable(table, 2, 3);
   
   return 0;
}

/* Write the function definition here */
void DisplayTable(double table[][COLS], int rows, int cols) {
    cout << rows << "x" << cols << endl;
    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
}
