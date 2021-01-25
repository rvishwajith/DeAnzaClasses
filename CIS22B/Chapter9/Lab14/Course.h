#ifndef COURSEH
#define COURSEH

#include <iostream>
#include <string>

using namespace std;

class Course {
    // TODO: Declare private data members - courseNumber, courseTitle
private:
    string courseNumber;
    string courseTitle;
    
public:
    
    // TODO: Define mutator functions -
    //       SetCourseNumber(), SetCourseTitle()
    void SetCourseTitle(string n) {courseTitle = n;}
    void SetCourseNumber(string n) {courseNumber = n;}

    // TODO: Define accessor functions -
    //       GetCourseNumber(), GetCourseTitle()
    string GetCourseTitle() const {return courseTitle;}
    string GetCourseNumber() const {return courseNumber;}


    // TODO: Define PrintInfo()
    void PrintInfo() const;
};

#endif

