/*
 Student is a struct
 
 This program demonstrates the insertNode, deleteNode, getCount(), and displayList member functions.
 It builds and displays a sorted list
 The list is sorted by name
 
 Write a function that displays students with gpa >= a given gpa as show below
 
 list.displayList(2.8);  //<===== see line# 49
  
 Run the program once and save the output as a comment at the end of this source file.
 
 Modified by: Rohith Vishwajith
 IDE: XCode
 
 */

#include <iostream>
#include "StudentList.h"
using namespace std;

int main()
{
    // Define a StudentList object.
    StudentList list;
    Student s[] = {{2.5, "Paul"}, {3.9, "Katie"}, {3.6, "Bill"}, {2.7, "Ann"}, {3.9, "Tina"}, {3.2, "Andy"}, {0, ""}};
    
    //******************************
    cout << "TESTING INSERT\n\n";
    // Build List from array (for demonstration purposes only)
    for (int i = 0; s[i].name != ""; i++)
    {
        cout << "\tInsert " << s[i].gpa << " " << s[i].name << endl;
        list.insertNode(s[i]);
        // Display the values in the list.
        list.displayList();
        cout << "\t\tThis list has " << list.getCount() << " student[s]\n\n";
    }
    
    //******************************
    cout << "TESTING DISPLAY\n\n";
    list.displayList();
    
    double gpa;
    cout << "Enter gpa: ";
    cin >> gpa;
    cout << "List of students with gpa >= " << gpa << endl;
    list.displayList(gpa);  //<====================================
    
    //******************************
    cout << "TESTING DELETE\n\n";
    string target[] = { "Andy", "Tina", "Katie", "Tim", ""}; // names to test deleteNode with
    for (int i = 0; target[i] != ""; i++)
    {
        if( list.deleteNode(target[i]) )
            cout << target[i] << " - Deleted!\n";
        else
            cout << target[i] << " - Not found\n";
    }
    list.displayList();
    
    cout << "\t\tThis list has " << list.getCount() << " student[s]\n\n";
    
    return 0;
}
/*
 Save the OUTPUT below
 
 
 */
