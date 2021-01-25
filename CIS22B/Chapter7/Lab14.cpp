// Rohith Vishwajith
// CIS22B
// Chapter 7
// XCode - Lab14.cpp
// 11/8/20
// Zybooks Lab 7.14 - TimeHrMn Class 3: overloaded ==, > and <

// This program demonstrates the TimeHrMn class's overloaded
// relational operators
#include <iostream>
#include "TimeHrMn.h"
using namespace std;

void displayTime(const TimeHrMn &obj);

int main()
{
   int hours, minutes;

   // Create two TimeHrMn objects. The default arguments
   // for the constructor will be used.
   TimeHrMn first, second;

   // Get a time from the user.
   cout << "Enter a time in hours and minutes: ";
   cin >> hours >> minutes;

   // Store the time in first.
   first.setHours(hours);
   first.setMinutes(minutes);

   // Get more input.
   cout << "Enter a time in hours and minutes: ";
   cin >> hours >> minutes;

   // Store the time in second.
   second.setHours(hours);
   second.setMinutes(minutes);

   // Compare the two objects.
   if (first == second)
   {
       displayTime(first);
       cout << " is equal to ";
       displayTime(second);
       cout << endl;
   }
    
   if (first > second)
   {
       displayTime(first);
       cout << " is greater than ";
       displayTime(second);
       cout << endl;
   }
   
   if (first < second)
   {
       displayTime(first);
       cout << " is less than ";
       displayTime(second);
       cout << endl;
   }
   return 0;
}

void displayTime(const TimeHrMn &obj)
{
    cout << obj.getHours() << "." << obj.getMinutes();
}
