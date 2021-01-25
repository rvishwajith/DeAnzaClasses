// Rohith Vishwajith
// CIS22B
// Chapter 3
// XCode - Lab5.cpp
// 10/9/20
// Zybooks Lab 3.5 - Array of Structures

#include <iostream>
#include <string>
using namespace std;

struct Friend{
    string name;
    string phone;
    int year;
};

/*
 list[] - the list of Friend structs
 size - the number of structs to print/the number of initialized structs
 
 Prints out the contents of each Friend struct in the array
 */
void printList(Friend list[], int size);
   
int main() {
    Friend list[10] =
    {
        { "John", "4081112345", 2015 },
        { "Mary", "4089992222", 2011 },
        { "Mira", "4086789888", 2012 },
        { "Alex", "4089992321", 2013 },
        { "Amir", "4081239876", 2014 },
    };
   int noFriends = 5;
    
   printList(list, noFriends);
   
   return 0;
}

void printList(Friend list[], int size) {
    for(int i = 0; i < size; i++) {
        cout << list[i].name << " " << list[i].phone << " " << list[i].year << endl;
    }
}
