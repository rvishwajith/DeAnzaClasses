// Rohith Vishwajith
// CIS22B
// Chapter 1
// XCode - Lab6.cpp
// 9/26/20
// Zybooks Lab 1.6 - Insertion Sort (shift data)

#include <iostream>
using namespace std;

void insertionSort(int numbers[], int numbersSize);

int main() {
   int numbers[100] = { 10, 2, 78, 4, 45, 32, 7, 11, 25 };
   int length = 9;
   int i;
   
   cout << "UNSORTED: ";
   for(i = 0; i < length; ++i) {
      cout << numbers[i] << " ";
   }
   cout << endl;
   
   insertionSort(numbers, length);
   
   cout << "  SORTED: ";
   for(i = 0; i < length; ++i) {
      cout << numbers[i] << " ";
   }
   cout << endl;
   
   return 0;
}

/* *************************
  Insertion Sort: shift data
*/
void insertionSort(int numbers[], int numbersSize) {
    
    int j;
    int temp;
    
   for (int i = 1; i < numbersSize; ++i) {
       
       temp = numbers[i];
       j = i - 1;
       while(j >= 0 && numbers[j] > temp) {
           // shift elements to the right by one index
           numbers[j + 1] = numbers[j];
           j = j - 1;
       }
       numbers[j + 1] = temp;
   }
}
