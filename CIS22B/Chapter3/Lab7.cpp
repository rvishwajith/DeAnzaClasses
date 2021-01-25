// Rohith Vishwajith
// CIS22B
// Chapter 3
// XCode - Lab7.cpp
// 10/9/20
// Zybooks Lab 3.7 - An Array as a Field in a Struct

#include <iostream>
#include <string>
using namespace std;

struct Student{
    string name;
    int quiz[5];
    double avgScore;
};

/*
 list[] - The array of all the Student structs
 size - The number of the initialized students
 
 Finds the average score of each Student struct and stores it in the struct
 */
void avgCalc(Student list[], int size);

/*
 list[] - The array of all the Student structs
 size - The number of the initialized students
 
 Prints out the contents of each student in a given number of iterations
 */
void printList(const Student list[], int size);
   
int main() {
   Student list[10] = {
        { "John", {10, 9, 9, 6, 10} },
        { "Mary", {9, 9, 10, 10, 7} },
        { "Alex", {6, 7, 10, 10, 9} },
        { "Amir", {10, 10, 8, 8, 9} },
        { "Mira", {9, 8, 7, 10, 10} }
    };
   int noStu = 5;
    
   avgCalc(list, noStu);
   printList(list, noStu);
   
   return 0;
}

void avgCalc(Student list[], int size) {
    
    for(int i = 0; i < size; i++) {
        
        double average = 0;
        int numQuiz = 5;
        for(int j = 0; j < numQuiz; j++) {
            average += list[i].quiz[j];
        }
        average /= numQuiz;
        list[i].avgScore = average;
    }
}

void printList(const Student list[], int size) {
    
    for(int i = 0; i < 5; i++) {
        
        cout << list[i].name << " ";
        int numQuiz = 5;
        
        for(int j = 0; j < numQuiz; j++) {
            cout << list[i].quiz[j] << " ";
        }
        cout << "(average: " << list[i].avgScore << ")\n";
    }
}
