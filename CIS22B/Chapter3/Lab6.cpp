// Rohith Vishwajith
// CIS22B
// Chapter 3
// XCode - Lab6.cpp
// 10/9/20
// Zybooks Lab 3.6 - Sort an Array of Structures

#include <iostream>
#include <string>
using namespace std;

struct Friend{
    string name;
    string phone;
    int year;
};

void printList(const Friend list[], int noFriends, string description);
void sortByName(Friend list[], int noFriends);
void sortByYear(Friend list[], int noFriends);

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
   
   sortByName(list, noFriends);
   printList(list, noFriends, "Ascending order by Name: ");
   
   sortByYear(list, noFriends);
   printList(list, noFriends, "Descending order by Year: ");
   
   return 0;
}

// sort an array of structs by year in descending order
// using insertion sort
void sortByYear(Friend list[], int noFriends) {
    
    for(int i = 1; i < noFriends; i++) {
        Friend sortVal = list[i];
        
        int j = i;
        while(j > 0 && list[j - 1].year < sortVal.year) {
            list[j] = list[j - 1];
            j--;
        }
        list[j] = sortVal;
    }
}

// sort an array of structs by name in ascending order
// using insertion sort
void sortByName(Friend list[], int noFriends) {
    
   for(int cur = 0; cur < noFriends; cur++) {
      Friend hold = list[cur];
      int back = cur - 1;
       
      while (back >= 0 && hold.name < list[back].name) {
         list[back + 1] = list[back];
         back--;
      }
      list[back + 1] = hold;
   }
}
   

// print a list of structures
void printList(const Friend list[], int noFriends, string description) {
    
   cout << description << endl;
    
   for (int i = 0; i < noFriends; i++) {
      cout << list[i].name << " "
      << list[i].phone << " "
      << list[i]. year << endl;
   }
   cout << endl;
}
