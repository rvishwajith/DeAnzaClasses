// Rohith Vishwajith
// CIS22B
// Chapter 1
// XCode - Lab8.cpp
// 9/26/20
// Zybooks Lab 1.8 - Insertion Sort (find errors)

#include <iostream>
#include <cstdlib>

using namespace std;

// ERROR 1: Missing ;
void insertionSort(double ary[], int size);

int main()
{
    double list[100] = {50.1, 30.2, 80.3, 10.5, 30.2, 40.9, 90.8, 30.2, 80.8, 30.5};
    int size = 10;
    
    for (int i = 0; i < size; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
    
    // A call for the insertion sort function
    // ERROR 2: Bad function call - Calling "insertionSort" should be done like this: "insertionSort(param, param);
    // ERROR 3: Incorrect parameter - "ary[]" should be "list"
    // ERROR 4: Extra data type - "int size" should just be "size", datat type is not necessary when calling a mthod
    insertionSort(list, size);

    for (int i = 0; i < size; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
    
    return 0;
}

/* **************************************************
 This function sorts an array in descending order
 using the Insertion Sort algorithm
 */

// ERROR 5: Incorrect name - "numbers[]" should be "ary[]"
// ERROR 6: Bad function name "InsertionSort" is capitalized incorrectly, should be "insertionSort"
// ERROR 7: Wrong data type - "ary[]" (previously called "numbers[]" should be a souble, not an int
void insertionSort(double ary[], int size)
{
    for (int curr = 1; curr < size; curr++)
    {
        // make a copy of the current element
        // ERROR 8: "temp" does not have a data type, should be a double
        double temp = ary[curr];
        
        // shift elements in the sorted part of the list to make room
        // ERROR 8: walk does not have a data type, should be an int
        // ERROR 9; Extra operation - "walk - 1" should be "walk"
        // ERROR 10: Incorrect operation - ">" should be "<"
        int walk = curr - 1;
        while(walk >= 0 && ary[walk] < temp)
        {
            ary[walk + 1] = ary[walk];
            // ERROR 10: Incorrect operation, should be "walk--"
            walk--;
        }
        
        // put the copy of the current element back into the list
        // ERROR 11: 1Incorrect variable name - "walk1" should be "walk"
        // ERROR 12: Missing operation - "walk" should be "walk + 1"
        ary[walk + 1] = temp;
    } // end of for: move to the next element to be inserted
}
