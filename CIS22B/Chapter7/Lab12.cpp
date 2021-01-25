// Rohith Vishwajith
// CIS22B
// Chapter 7
// XCode - Lab12.cpp
// 11/8/20
// Zybooks Lab 7.12 - TimeHrMn Class 1: overload + and -

#include <iostream>
#include "TimeHrMn.h"
using namespace std;

int main()
{
    int hours, minutes;  // To hold input for hours and minutes and seconds

    // Create four TimeHrMn objects. The default arguments
    // for the constructor will be used.
    TimeHrMn first, second, third, fourth;

    // Get a time from the user.
    cout << "Enter time in hours and minutes: ";
    cin >> hours >> minutes;

    // Store the time in the first object.
    first.setHours(hours);
    first.setMinutes(minutes);

    // Get another time from the user.
    cout << "Enter another time in hours and minutes: ";
    cin >> hours >> minutes;
    cout << endl;
    // Store the time in second.
    second.setHours(hours);
    second.setMinutes(minutes);

    // Assign first + second to third.
    third = first + second;

    // Display the result.
    cout << "first + second = ";
    cout << third.getHours() << " hrs, ";
    cout << third.getMinutes() << " min.\n";

    // Assign first - second to third.
    third = first - second;

    // Display the result.
    cout << "first - second = ";
    cout << third.getHours() << " hrs, ";
    cout << third.getMinutes() << " min.\n";

    // Assign first + second to fourth
    // The overloaded operator function can be called like a regular function
    fourth = first.operator+(second);

    // Display the result.
    cout << "first + second = ";
    cout << fourth.getHours() << " hrs, ";
    cout << fourth.getMinutes() << " min.\n";

    return 0;
}
