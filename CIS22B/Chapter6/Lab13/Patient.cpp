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
void Patient::display() const
{
    cout << "         Name: " << name << endl;
    cout << "          Age: " << age << endl;
    cout << "       Height: " << height << " inches" << endl;
    cout << "       Weight: " << weight << " pounds" << endl;
    cout << "Weight Status: " << weightStatus() << endl;
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
