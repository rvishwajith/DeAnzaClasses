// Rohith Vishwajith
// CIS22B
// Chapter 3
// XCode - Lab9.cpp
// 10/9/20
// Zybooks Lab 3.9 - An Array of Nested Structures

#include <iostream>
using namespace std;

struct Date {
    int month;
    int day;
    int year;
};

struct Stu {
    string name;
    Date bdate;
    int quizList[5];
};

void showStu(const Stu list[], int noStu);
   
int main() {
   Stu list[10] = {
        {"Rice", { 11, 22, 2002 }, {5, 6, 7, 8, 10} },
        {"Lee",   { 10,  4, 2001 }, {5, 6, 7, 8, 9} },
        {"Tran",  { 12,  7, 1999 }, {5, 6, 7, 8, 10} }
    };

   showStu(list, 3);
   
   return 0;
}

// Display year, name, and the last quiz score
void showStu(const Stu list[], int noStu){

    int numQuiz = 5;
    int numDates = 3;
    
    for(int i = 0; i < noStu; i++) {
        cout << list[i].bdate.year << " ";
        cout << list[i].name << " " << list[i].quizList[numQuiz - 1] << endl;
    }

}
