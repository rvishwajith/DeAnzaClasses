// Rohith Vishwajith
// CIS22B
// Chapter 1
// XCode - Lab9.cpp
// 9/26/20
// Zybooks Lab 1.9 - Airports 1

#include <iostream>
#include <string>

using namespace std;

/*
 binarySearch - provided by zyBooks, section 1.1
 */
int binarySearch(string codes[], int size, string key);

int main() {
    //constants definitions
    const int AIRPORTS = 50;     // maximum size of arrays
    
    // arrays definitions
    string city[AIRPORTS] = {"Burbank", "Fresno", "Los Angeles", "Oakland", "Redding", "San Jose", "Santa Ana"};
    string code[AIRPORTS] = {"BUR", "FAT", "LAX", "OAK", "RDD", "SJC", "SNA"};
    int numOfEnpl[AIRPORTS] = {100433, 761298, 39636042, 5934639, 43414, 5321603, 5217242};
    
    // other variables
    int size = 7;               // actual size of arrays
    string target;
    
    cin >> target;              // the airport code to search for
    int result = binarySearch(code, size, target);
    
    if(result == -1) {
        cout << target << " not found!\n";
    }
    else {
        cout << code[result] << " found! See related data below:\n";
        cout << "        Code: " << code[result] << endl;
        cout << "        City: " << city[result] << endl;
        cout << "Enplanements: " << numOfEnpl[result] << endl;
    }
    
   return 0;
}

/* *******************************************
 Definition of binary search
 This function performs the binary search on a string array. The array has
 the size of elements. A value stored in this array will be searched. It will
 return the array subscript if found. Otherwise, -1 will be returned.
 */

/* Write your code here */
int binarySearch(string codes[], int size, string key) {
   int mid;
   int low;
   int high;
   
   low = 0;
   high = size - 1;
   
   while (high >= low) {
      mid = (high + low) / 2;
      if (codes[mid] < key) {
         low = mid + 1;
      }
      else if (codes[mid] > key) {
         high = mid - 1;
      }
      else {
         return mid;
      }
   }
   
   return -1; // not found
}
