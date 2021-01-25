#include "OfferedCourse.h"

// TODO: Define mutator functions -
//      SetInstructorName(), SetTerm(), SetClassTime()


// TODO: Define accessor functions -
//      GetInstructorName(), GetTerm(), GetClassTime()

string GetInstructorName() const {return instructorName;}
string GetTerm() const {return term;}
string GetClassTime() const {return classTime;}

void SetInstructorName(string n) {instructorName = n;}
void SetTerm(string n) {term = n;}
void SetClassTime(string n) {classTime = n;}
