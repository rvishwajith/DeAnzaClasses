/*
 Test Driver for the Patient class using an array of Patient objects
*/

#include <iostream>
#include <string>
#include <iomanip>
#include "Patient.h"
using namespace std;

/* Write your code here: declare the printList function */
void printList(Patient list[], int size);

int main()
{
    // Create the first array
    Patient listA[3] =
    {
        Patient("Jane North", 25, 66, 120),
        Patient("Tim South", 64, 72, 251),
        Patient("Linda East", 52, 69, 175)
    };
    
    printList(listA, 3);
  
    return 0;
}

/* Write your code here: define the printList function */
void printList(Patient list[], int size) {
    for(int i = 0; i < size; i++) {
        list[i].display();
    }
}
