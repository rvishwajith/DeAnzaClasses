/*
 Test Driver for the Patient class
 
*/

#include <iostream>
#include <string>
#include <iomanip>
#include "Patient.h"
using namespace std;

int main()
{
    // Create the first object
    Patient one;
    
    // Call setters to assign values to one's data members
    one.setName("Jane North");
    one.setAge(25);
    one.setHeight(66);
    one.setWeight(120);
    
    // Display one's data members calling getters
    cout << "Testing the first object:" << endl;
    cout << "         Name: " << one.getName() << endl;
    cout << "          Age: " << one.getAge() << endl;
    cout << "       Height: " << one.getHeight() << " inches" << endl;
    cout << "       Weight: " << one.getWeight() << " pounds" << endl;
    cout << "Weight Status: " << one.weightStatus() << endl;
    
    // Create the second object using the default constructor
    Patient two;
    
    // Display two's data members calling the display() function
    cout << "Testing the second object:" << endl;
    two.display();
    
    // Create the third object using the overloaded constructor
    Patient three("Tim South", 64, 72, 251);
    
    // Display three's data members calling the display() function
    cout << "Testing the third object:" << endl;
    three.display();
    
    return 0;
}
