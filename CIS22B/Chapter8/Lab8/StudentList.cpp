// Implementation file for the Student List class
// Modified by: Rohith Vishwajith
// IDE: XCode

#include <iostream>         // For cout  and NULL
#include "StudentList.h"
using namespace std;

//**************************************************
// Constructor
// This function allocates and initializes a sentinel node
//      A sentinel (or dummy) node is an extra node added before the first data record.
//      This convention simplifies and accelerates some list-manipulation algorithms,
//      by making sure that all links can be safely dereferenced and that every list
//      (even one that contains no data elements) always has a "first" node.
//**************************************************
StudentList::StudentList()
{
    head = new ListNode; // head points to the sentinel node.
    
    head->stu.gpa = -1;
    head->stu.name = "";
    head->next = NULL;
    count = 0;
}

//**************************************************
// displayList shows the value
// stored in each node of the linked list
// pointed to by head.
//**************************************************
void StudentList::displayList() const
{
    ListNode *pCur;  // To move through the list.

    // Position pCur: skip the head of the list.
    pCur = head->next;

    // While pCur points to a node, traverse the list.
    while (pCur)
    {
        // Display the value in this node.
        cout << pCur->stu.gpa << " " << pCur->stu.name << endl;

        // Move to the next node.
        pCur = pCur->next;
    }
    cout << endl;
}

void StudentList::displayList(double gpa) const {
    ListNode *pCur;  // To move through the list.

    // Position pCur: skip the head of the list.
    pCur = head->next;
    int count = 0;

    // While pCur points to a node, traverse the list.
    while (pCur)
    {
        if(pCur->stu.gpa >= gpa) {
            // Display the value in this node.
            
            cout << pCur->stu.gpa << " " << pCur->stu.name << endl;
            count++;
            // Move to the next node.
        }
        pCur = pCur->next;
    }
    if(count == 0) {
        cout << "None!";
    }
    cout << endl;
}

//**************************************************
// The insertNode function inserts a node with
// stu copied to its value member.
//**************************************************
void StudentList::insertNode(Student dataIn)
{
    ListNode *newNode;  // A new node
    ListNode *pCur;     // To traverse the list
    ListNode *pPre;     // The previous node
    
    // Allocate a new node and store dataIn there.
    newNode = new ListNode;
    newNode->stu = dataIn;

    // Initialize pointers
    pPre = head;
    pCur = head->next;
   
    // Find location: skip all nodes whose name is less than dataIn's gpa
    while (pCur != NULL && pCur->stu.name < dataIn.name)
    {
        pPre = pCur;
        pCur = pCur->next;
    }

    // Insert the new node between pPre and pCur
    pPre->next = newNode;
    newNode->next = pCur;
    
    // Update the counter
    count++;
}

//**************************************************
// The deleteNode function searches for a node
// with target as its name value. The node, if found, is
// deleted from the list and from memory.
//**************************************************
bool StudentList::deleteNode(string target)
{
    ListNode *pCur;       // To traverse the list
    ListNode *pPre;       // To point to the previous node
    bool deleted = false;
    
    // Initialize pointers
    pPre = head;
    pCur = head->next;

    // Find node containing the target: Skip all nodes whose name is less than the target
    while (pCur != NULL && pCur->stu.name < target)
    {
        pPre = pCur;
        pCur = pCur->next;
    }
    
    // If found, delte the node
    if (pCur != NULL && pCur->stu.name == target)
    {
        pPre->next = pCur->next;
        delete pCur;
        deleted = true;
        count--;
    }
    return deleted;
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************
StudentList::~StudentList()
{
    ListNode *pCur;   // To traverse the list
    ListNode *pNext;  // To point to the next node

    // Position nodePtr at the head of the list.
    pCur = head->next;

    // While pCur is not at the end of the list...
    while (pCur != NULL)
    {
        // Save a pointer to the next node.
        pNext = pCur->next;

        // Delete the current node.
        cout << "DEBUG - Destructor: Now deleting " << pCur->stu.name << endl;
        delete pCur;

        // Position pCur at the next node.
        pCur = pNext;
    }
    cout << "DEBUG - Destructor: Now deleting the sentinel node gpa = " << head->stu.gpa << endl;
    delete head; // delete the sentinel node
}
