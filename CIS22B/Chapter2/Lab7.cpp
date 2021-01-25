// Rohith Vishwajith
// CIS22B
// Chapter 2
// XCode - Lab7.cpp
// 9/29/20
// Zybooks Lab 2.7 - Square 2D Arrays (functions)

#include <iostream>

using namespace std;

const int TSIZE = 10;         // maximum number of rows & columns

/* Write the function declaration here */
double DiagonalSum(double table[][TSIZE], int TSIZE);

int main() {

    double table[TSIZE][TSIZE] = {   //A square array
        {10, 90, 50, 30, 20},
        {25, 10, 65, 85, 95},
        {33, 53, 10, 73, 83},
        {91, 21, 71, 10, 51},
        {69, 39, 29, 12, 99}
    };  // initializing the array
   int tblSize = 5; // the actual number of rows and columns
   
   double sum = DiagonalSum(table, tblSize);
   cout << sum << endl;
   return 0;
}

/* Write the function definition here */
double DiagonalSum(double table[][TSIZE], int TSIZE) {
    double sum = 0;
    
    for(int i = 0; i < TSIZE; i++) {
        sum += table[i][i];
    }
    return sum;
}

