// Rohith Vishwajith
// CIS22B
// Chapter 7
// XCode - Lab13.cpp
// 11/8/20
// Zybooks Lab 7.13 - TimeHrMn Class 2: overloaded ++ and --

// This program demonstrates the TimeHrMn class's overloaded
// prefix and postfix ++ operators.
#include <iostream>
#include "TimeHrMn.h"
using namespace std;

int main()
{
   // Define a TimeHrMn object with the default
   // value of 0 hours, 0 minutes.
   TimeHrMn first;
    
   // Define a TimeHrMn object with 1 hour 57 minutes.
   TimeHrMn second;

   int hours, minutes;  // To hold input for hours and minutes
   // Get a time from the user.
   cout << "Enter time in hours and minutes: ";
   cin >> hours >> minutes;

   // Store the time in the second object.
   second.setHours(hours);
   second.setMinutes(minutes);

   // Use the prefix ++ operator.
   cout << "\nDemonstrating prefix ++ operator.\n";
   cout << "first            second\n";
   cout << first.getHours() << " hrs, ";
   cout << first.getMinutes() << " min.    ";
   cout << second.getHours()<< " hrs, ";
   cout << second.getMinutes() << " min. (initial values)\n";
   for (int count = 0; count < 4; count++)
   {
      first = ++second;
      cout << first.getHours() << " hrs, ";
      cout << first.getMinutes() << " min.   ";
      cout << second.getHours()<< " hrs, ";
      cout << second.getMinutes() << " min.\n";
   }

   // Use the postfix ++ operator.
   first.setHours(0);
   first.setMinutes(0);
   second.setHours(hours);
   second.setMinutes(minutes);
   cout << "\nDemonstrating postfix ++ operator.\n";
   cout << "first            second\n";
   cout << first.getHours() << " hrs, ";
   cout << first.getMinutes() << " min.    ";
   cout << second.getHours()<< " hrs, ";
   cout << second.getMinutes() << " min. (initial values)\n";
   for (int count = 0; count < 4; count++)
   {
       first = second++;
       cout << first.getHours() << " hrs, ";
       cout << first.getMinutes() << " min.   ";
       cout << second.getHours()<< " hrs, ";
       cout << second.getMinutes() << " min.\n";
   }
    
    // Use the prefix -- operator.
    first.setHours(0);
    first.setMinutes(0);
    second.setHours(hours);
    second.setMinutes(minutes);
    cout << "\nDemonstrating prefix -- operator.\n";
    cout << "first            second\n";
    cout << first.getHours() << " hrs, ";
    cout << first.getMinutes() << " min.    ";
    cout << second.getHours()<< " hrs, ";
    cout << second.getMinutes() << " min. (initial values)\n";
    for (int count = 0; count < 4; count++)
    {
        first = --second;
         cout << first.getHours() << " hrs, ";
         cout << first.getMinutes() << " min.   ";
         cout << second.getHours()<< " hrs, ";
         cout << second.getMinutes() << " min.\n";
    }

    // Use the postfix -- operator.
    first.setHours(0);
    first.setMinutes(0);
    second.setHours(hours);
    second.setMinutes(minutes);
    cout << "\nDemonstrating postfix -- operator.\n";
    cout << "first            second\n";
    cout << first.getHours() << " hrs, ";
    cout << first.getMinutes() << " min.    ";
    cout << second.getHours()<< " hrs, ";
    cout << second.getMinutes() << " min. (initial values)\n";
    for (int count = 0; count < 4; count++)
    {
        first = second--;
        cout << first.getHours() << " hrs, ";
        cout << first.getMinutes() << " min.   ";
        cout << second.getHours()<< " hrs, ";
        cout << second.getMinutes() << " min.\n";
    }
   return 0;
}
