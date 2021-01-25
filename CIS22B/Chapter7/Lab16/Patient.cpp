/*
  Implementation file for the Patient class.
*/

#include "Patient.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/*
 This is the default constructor; it sets everything to 0 or "".
 */
Patient::Patient()
{
    name = "";
    weight = 0;
    age = 0;
    height = 0;
}

/*
This is an overloaded constructor.
 It sets the variables according to the parameters.
*/
Patient::Patient(string n, int a, double h, int w)
{
    name = n;
    age = a;
    weight = w;
    height = h;
}

/*
This function displays the member variables
 in a neat format.
*/
// NOTE: Use this function for testing your code
// Use the same format for overloading the stream insertion operator
// When done, you will not need this function anymore but you could
// keep it in your program
void Patient::display() const
{
   cout << setprecision(2) << fixed;
   cout << left << setw(20) << name << " " << right
         << setw(3) << age << " years  "
         << setw(5) << height << " inches  "
         << setw(3) << weight << " pounds "
         << weightStatus() << endl;
}

/*
This function calculates the BMI using the following formula:
 BMI = (weight in pounds * 703) / (height in inches)^2
 Then, it returns a string reflecting the weight status according to the BMI:
 <18.5 = underweight
 18.5 - 24.9 = normal
 25 - 29.9 = overweight
 >=30 = obese
 */
string Patient::weightStatus() const
{
    double bmi = (weight * 703) / (height * height);
    string stat = "";
    
    if (height > 0)
    {
        if(bmi <= 18.5) {
            stat = "Underweight";
        }
        else if(bmi > 18.5 && bmi < 25) {
            stat = "Normal";
        }
        else if(bmi >= 25 && bmi < 30) {
            stat = "Overweight";
        }
        else if(bmi >= 30) {
            stat = "Obese";
        }
    }
    return stat;
}

/* override the < operator */
bool Patient::operator< (const Patient &right)
{
    bool status = false;

    if (age < right.age)
        status = true;

    return status;
}

/* overload cout's << */
std::ostream& operator<<(ostream& strm, Patient& pat)
{
    strm << fixed;
    strm << setprecision(2);
    
    strm << left << setw(22) << pat.getName()
    << pat.getAge() << " years  "
    << pat.getHeight() << " inches  ";
    
    strm << setprecision(0);
    strm << pat.getWeight() << " pounds "
    << pat.weightStatus() << endl;
    return strm;
}
