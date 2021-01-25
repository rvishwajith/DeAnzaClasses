// Rohith Vishwajith
// CIS22B
// Chapter 7
// XCode - Lab15.cpp
// 11/8/20
// Zybooks Lab 7.15 - TimeHrMn Class 4*: overloaded >> and <<

// This program demonstrates the TimeHrMn class's overloaded
// stream insertion and extraction operators
#include <iostream>
#include "TimeHrMn.h"
using namespace std;

int main()
{
   TimeHrMn first, second;  // Define two objects.

   // Get input for the first object.
   cout << "Enter a time in hours and minutes.\n";
   cin >> first;

   // Get input for the second object.
   cout << "Enter another time in hours and minutes.\n";
   cin >> second;

   // Display the values in the objects.
   cout << "The values you entered are:\n";
   cout << first << " and " << second << endl;
   
   return 0;
}
