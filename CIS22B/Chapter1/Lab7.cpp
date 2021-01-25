// Rohith Vishwajith
// CIS22B
// Chapter 1
// XCode - Lab7.cpp
// 9/26/20
// Zybooks Lab 1.7 - Binary Search (find errors)

#include <iostream>
#include <cstdlib>

using namespace std;

int binarySearch(const int array[], int numElems, int value);

int main()
{
    // ERROR 1: ARRAY IS NOT IN ASCENDING ORDER.
    int length = 10;
    int list[10] = {5, 5, 8, 8, 8, 8, 8, 9, 9, 10};
    
    for (int i = 0; i < length; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
    
    for (int i = 0; i < 2 * length; i++) // SEARCH 20 times
    {
        int target = rand() % 5 + 5;  // generate a random target within the range 5 to 10
        int location = binarySearch(list, length, target);
        
        // ERROR 2: SHOULD BE "location == -1" NOT "location = -1"
        if (location == -1)
            cout << target << " NOT found!" << endl;
        else
        {
            // print a range: from index A to Z, inclusive!
            int z = location + 1;
            while( z < length && list[z] == list[location] )
                z++;
            z--;
            
            int a = location - 1;
            while( a >= 0 && list[a] == list[location] )
                a--;
            a++;
            
            if ( a != z )
            {
                cout << target << " found from index "
                << a << " to " << z << endl;
            }
            else
                cout << target << " found at location " << location << endl;
        }
        
    }
    
    return 0;
}

/* **************************************************************
 The binarySearch function performs a binary search on an
 integer array with numElems numbers. It searches for the number
 stored in value. If found, its array subscript is returned,
 otherwise, -1 is returned indicating the value was not in the array.
 */
int binarySearch(const int array[], int numElems, int value)
{
    int first = 0,         // First array element
    last = numElems - 1,   // Last array element
    middle,                // Midpoint of search
    position = -1;         // Position of search value
    // Assume not found
    
    // ERROR 3: "-1 = position" SHOULD BE "-1 == position" or "position == -1"
    while (position == -1 && first <= last)
    {
        middle = (first + last) / 2;     // Calculate midpoint
        if (array[middle] == value)      // If value is found at mid
        {
            position = middle;
        }
        else if (array[middle] > value) // If value is in lower half
            last = middle - 1;
        else
            first = middle + 1;            // If value is in upper half
    }
    return position;
}

