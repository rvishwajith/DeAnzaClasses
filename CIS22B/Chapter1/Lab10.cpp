// Rohith Vishwajith
// CIS22B
// Chapter 1
// XCode - Lab10.cpp
// 9/26/20
// Zybooks Lab 1.10 - Airports 2

#include <iostream>
#include <string>

using namespace std;

/* Write your code here */
void displaySearchHistory(int searchCount[], string code[], string city[], int numOfEnpl[], int size);
int binarySearch(string codes[], int size, string key);

int main() {
    //constants definitions
    const int AIRPORTS = 50;     // maximum size of arrays
    
   // arrays definitions
   string city[AIRPORTS] = {"Burbank", "Fresno", "Los Angeles", "Oakland", "Redding", "San Jose", "Santa Ana"};
   string code[AIRPORTS] = {"BUR", "FAT", "LAX", "OAK", "RDD", "SJC", "SNA"};
   int numOfEnpl[AIRPORTS] = {100433, 761298, 39636042, 5934639, 43414, 5321603, 5217242};
   int searchCount[AIRPORTS]; // to keep track of the search history
    
    // other variables
   int size = 7;                // actual size of arrays
   string targetAirport[] =
   {"SJC", "BUR", "SJC", "LAX", "ACV", "SJC", "LAX", "BUR", "BUR", "SJC", "LAX", "SJC", "BUR", "RDD", ""};
   
   // Make sure all the values are set to 0.
   // This is my best guess as to why values are different in zyBooks, they sometimes showed numbers like "851" or '32"
   for(int i = 0; i < size; i++) {
        searchCount[i] = 0;
   }
    
   for (int i = 0; targetAirport[i] != ""; i++) {
       int position = binarySearch(code, size, targetAirport[i]);
       if(position >= 0) {
           searchCount[position]++;
       }
   }
   
   displaySearchHistory(searchCount, code, city, numOfEnpl, size);
   
   return 0;
}

/* Write your code here */
void displaySearchHistory(int searchCount[], string code[], string city[], int numOfEnpl[], int size)
{
   cout << "~*~ Search History ~*~\n";
   for(int i = 0; i < size; i++) {
        if(searchCount[i] > 0) {
            cout << searchCount[i] << " " << code[i] << " " << city[i] << " (" << numOfEnpl[i] << ")\n";
        }
    }
}

/* Write for the binary search function from the previous lab */
int binarySearch(string codes[], int size, string key) {
   int mid;
   int low;
   int high;
   
   low = 0;
   high = size - 1;
   
   while (high >= low) {
      mid = (high + low) / 2;
      if (codes[mid] < key) {
         low = mid + 1;
      }
      else if (codes[mid] > key) {
         high = mid - 1;
      }
      else {
         return mid;
      }
   }
   
   return -1; // not found
}
