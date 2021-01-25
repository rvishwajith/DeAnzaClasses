// Specification file for the Student List class
// Modified by: Rohith Vishwajith
// IDE: XCode

#ifndef STUDENTLIST_H
#define STUDENTLIST_H
#include "Student.h"

class StudentList
{
private:
    // Declare a structure for the list
    struct ListNode
    {
        Student stu;     // The value in this node
        ListNode *next;  // To point to the next node
    };
    
    ListNode *head;      // List head pointer
    int count;           // To keep track of the number of nodes in the list
    

public:
    StudentList();  // Constructor
   ~StudentList();   // Destructor
    
    // Linked list operations
    int getCount() const {return count;}
    void insertNode(Student);
    bool deleteNode(std::string);
    void displayList() const;
    
    // added to display names with n letters in the list
    void displayList(int n) const;
    void displayList(double gpa) const;
    void searchList() const;
};
#endif
