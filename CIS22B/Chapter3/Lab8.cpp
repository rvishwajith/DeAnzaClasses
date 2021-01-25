// Rohith Vishwajith
// CIS22B
// Chapter 3
// XCode - Lab8.cpp
// 10/9/20
// Zybooks Lab 3.8 - Nested Structures

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
    double avgScore;
    char grade;
};

/*
 s - The Student struct containing information about a student
 
 Prints all the information in the Student struct and its nested struct Date.
 */
void showStu(const Stu &s);
// ----------^^^^^-----^^
// To save memory (avoid making a copy), pass structures as reference parameters
// Make it const if you do not intend to change the struct
   
int main() {
   Stu s = { "Lee", { 10, 14, 2001 }, 88.3, 'B' };

   showStu(s);
   return 0;
}

void showStu(const Stu &s) {
    cout << "Name: " << s.name << endl;
    Date d = s.bdate;
    cout << "Date of Birth: " << d.month << "/" << d.day << "/" << d.year << endl;
    cout << "Average Score: " << s.avgScore << endl;
    cout << "Grade: " << s.grade << endl;
}
