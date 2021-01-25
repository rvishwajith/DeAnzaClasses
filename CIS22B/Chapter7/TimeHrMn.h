// Specification file for the TimeHrMn class
// The TimeHrMn class holds time
// expressed in hours and minutes.

#ifndef TIMEHRMN_H
#define TIMEHRMN_H

#include <iostream>

using std::ostream;
using std::istream;

class TimeHrMn
{
private:
   int hours;
   int minutes;
   void update(); // Defined in TimeHrMn.cpp
public:
    // Constructor
    TimeHrMn(int h = 0, int m = 0) {
       hours = h;
       minutes = m;
       update();
    }

    // Setters
    void setHours(int h) { hours = h; }
    void setMinutes(int m) {
       minutes = m;
       update();
    }

    // Getters
    int getHours() const { return hours; }
    int getMinutes() const { return minutes; }

    // Overloaded operator functions
    TimeHrMn operator+ (const TimeHrMn &); // Overloaded +
    /* Write your code here */ // Overloaded -
     TimeHrMn operator- (const TimeHrMn &);
     
    TimeHrMn operator++ ();       // Prefix ++
    TimeHrMn operator++ (int);    // Postfix ++
     /* Write your code here */       // Prefix --
      /* Write your code here */    // Postfix --
     TimeHrMn operator-- ();       // Prefix --
     TimeHrMn operator-- (int);
     
    bool operator > (const TimeHrMn &);        // Overloaded >
    /* Write your code here */                 // Overloaded <
    bool operator < (const TimeHrMn &);
    /* Write your code here */                 // Overloaded ==
    bool operator == (const TimeHrMn &);

    friend std::istream &operator >> (std::istream &, TimeHrMn &);
    friend std::ostream &operator << (std::ostream &, TimeHrMn &);
};

#endif

