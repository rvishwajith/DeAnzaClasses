// Rohith Vishwajith
// CIS22B
// Chapter 4
// XCode - Lab3.cpp
// 10/19/20
// Zybooks Lab 4.3 - Array of Pointers

#include <iostream>
#include <string>
using namespace std;

struct Stu{
   string name;
   double gpa;
};

int main() {

    Stu list[4] = {{"Tom", 3.5}, {"Bob", 2.9}, {"Ann", 3.2}, {"Dan", 3.1}};
    Stu *ptrList[4]; // Declare an array of 4 pointers to Stu

    ptrList[0] = &list[1]; // Assign a value to the first pointer in ptrList
    ptrList[1] = &list[3];
    ptrList[2] = &list[2];
    ptrList[3] = &list[0];
   
    for (int i = 0; i < 4; i++)
    {
      cout << (*ptrList[i]).name << " ";
      // -----^^^ ( ) are mandatory here
      // ptrList[i] is a pointer: to get to name, the pointer must be dereferenced first
     
        cout << (*ptrList[i]).gpa << endl;
    }
    
    ptrList[0] = list + 2;  // points to "Ann"
            // ^^^^^^^^^^ list + 2 is the same as &list[2]
    ptrList[1] = list + 1; // points to "Bob"
    ptrList[2] = list + 3;/* Write your code here */ ; // points to "Dan"
    ptrList[3] = list; // points to "Tom"
   
   cout << endl;
   for (int i = 0; i < 4; i++) {
      cout << ptrList[i]->name << " ";
      // --------------^^^ The arrow operator is prefered with pointers and structures
      cout << ptrList[i]->gpa << endl;
   }
   return 0;
}

