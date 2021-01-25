// Rohith Vishwajith
// CIS22B
// Chapter 4
// XCode - Lab2.cpp
// 10/19/20
// Zybooks Lab 4.2 - 'new' and 'delete'

#include <iostream>
#include <string>
using namespace std;

struct Stu{
   string name;
   double gpa;
};

Stu *copyList(Stu list[], int n);
void printList(Stu *list, int n, string desc);

int main() {

   Stu list[10] = {{"Tom", 3.5}, {"Bob", 2.9}, {"Ann", 3.2}, {"Dan", 3.1}, {"Zoe", 2.9}};
   Stu *backup;
   int n = 5;
   
   printList(list, n, "Original");
   backup = copyList(list, 5);
   printList(list, n, "Backup");
   
   // Release memory
   delete [] backup;
   
   return 0;
}
// This function dynamically allocates an array of n STU structures,
// copies data from list to the new array, one element at a time,
// and returns a pointer to the new array
Stu *copyList(Stu list[], int n)
{
   Stu *backup;
   
   /* write your code here */
    backup = new Stu[n];
    
    for(int i = 0; i < n; i++) {
        backup[i] = list[i];
    }
   
   return backup;
}

// This functions displays an array of structures
// Note: it doesn't matter if the array is
// statically allocated or dynamically allocated
void printList(Stu *anyList, int n, string desc)
{
   cout << endl << desc << endl;
   for (int i = 0; i < n; i++)
   {
      cout << anyList[i].name << " " << anyList[i].gpa << endl;
   }
}
