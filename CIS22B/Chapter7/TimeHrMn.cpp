// Implementation file for the TimeHrMn class
#include <cstdlib>       // Needed for abs()
#include "TimeHrMn.h"

//*~*~*
// Definition of member function update. This function
// checks for values in the minutes member greater than
// 60 or less than zero. If such a value is found,
// the numbers in hours and minutes are adjusted to conform
// to a standard hours & minutes expression. For example,
// 2 hours 64 minutes would be adjusted to 3 hours 4 minutes and
// 5 hours -15 minutes would be adjusted to 4 hours 45 minutes.
//*~*~*

void TimeHrMn::update()
{
    if (minutes >= 60)
    {
        hours += (minutes / 60);
        minutes = minutes % 60;
    }
    else if (minutes < 0)
    {
        int hold = abs(minutes);
        hours -= hold / 60 + 1;
        minutes = 60 - hold % 60;
    }
}

//*~*~*
// Overloaded binary + operator.
//*~*~*
TimeHrMn TimeHrMn::operator+ (const TimeHrMn &right)
{
   TimeHrMn temp;

   temp.minutes = minutes + right.minutes;
   temp.hours = hours + right.hours;
   temp.update();
   return temp;
}

//*~*~*
// Overloaded binary - operator.
//*~*~*

TimeHrMn TimeHrMn::operator- (const TimeHrMn &right)
{
   TimeHrMn temp;

   temp.minutes = minutes - right.minutes;
   temp.hours = hours - right.hours;
   temp.update();
   return temp;
}


//*~*~*
// Overloaded prefix ++ operator.
// Causes the inches member to be incremented.
// Returns the incremented object.
//*~*~*
TimeHrMn TimeHrMn::operator++()
{
    ++minutes;
    update();
    return *this;
}
//*~*~*
// Overloaded postfix ++ operator.
// Causes the inches member to be incremented.
// Returns the value of the object before the increment.
//*~*~*
TimeHrMn TimeHrMn::operator++(int)
{                          // ^^^ this is a dummy parameter (nameless)
                           // used to identify the postfix operator function
    TimeHrMn temp(hours, minutes);

    minutes++;
    update();
    return temp;
}

//*~*~*
// Overloaded prefix -- operator.
// Causes the inches member to be decremented.
// Returns the decremented object.
//*~*~*
/* Write your code here */
TimeHrMn TimeHrMn::operator--()
{
    --minutes;
    update();
    return *this;
}

//*~*~*
// Overloaded postfix -- operator.
// Causes the inches member to be decremented.
// Returns the value of the object before the decrement.
//*~*~*

/* Write your code here */
TimeHrMn TimeHrMn::operator--(int)
{                          // ^^^ this is a dummy parameter (nameless)
                           // used to identify the postfix operator function
    TimeHrMn temp(hours, minutes);

    minutes--;
    update();
    return temp;
}


//*~*~*
// Overloaded > operator. Returns true if the current object
// is set to a value greater than that of right.
//*~*~*
bool TimeHrMn::operator> (const TimeHrMn &right)
{
    bool status = false;

    if (hours > right.hours)
        status = true;
    else if (hours == right.hours && minutes > right.minutes)
        status = true;

    return status;
}

//*~*~*
// Overloaded < operator. Returns true if the current object
// is set to a value less than that of right.
//*~*~*
/* Write your code here */
bool TimeHrMn::operator< (const TimeHrMn &right)
{
    bool status = false;

    if (hours < right.hours)
        status = true;
    else if (hours == right.hours && minutes < right.minutes)
        status = true;

    return status;
}


//*~*~*
// Overloaded == operator. Returns true if the current object
// is set to a value equal to that of right.
//*~*~*
/* Write your code here */
bool TimeHrMn::operator== (const TimeHrMn &right)
{
    bool status = false;
    if (hours == right.hours && minutes == right.minutes)
        status = true;

    return status;
}

//*~*~*
// Overloaded << operator. Gives cout the ability to
// directly display TimeHrMn objects.
//*~*~*
std::ostream& operator<<(ostream& strm, TimeHrMn& obj)
{
    strm << obj.getHours() << " hrs, " << obj.getMinutes() << " min.";
    return strm;
}

//*~*~*
// Overloaded >> operator. Gives cin the ability to
// store user input directly into TimeHrMn objects.
//*~*~*

std::istream &operator>> (istream &strm, TimeHrMn &obj)
{
    std::cout << "Hours: ";
    strm >> obj.hours;
    std::cout << "Minutes: ";
    strm >> obj.minutes;
    
    obj.update();
    return strm;
}
