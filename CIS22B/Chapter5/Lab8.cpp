// Rohith Vishwajith
// CIS22B
// Chapter 5
// XCode - Lab8.cpp
// 10/26/20
// Zybooks Lab 5.8 - Iterating through a C string without using strlen

#include <iostream>
#include <cstring>
using namespace std;

int main() {
   char userName[15] = "Alan Turing";
   int i;
   
   cout << "Before: " << userName << endl;
   
   //for (i = 0; i < strlen(userName); ++i) {
    
    // checks for a null character
    for (i = 0; userName[i] != '\0' ; ++i) {
        if (userName[i] == ' ') {
            userName[i] = '_';
        }
    }
    cout << "After:  " << userName << endl;
    return 0;
}
