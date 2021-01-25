/*
 This program creates a Rectangle object, then displays the rectangle's
 - length,
 - width, and
 - area
 
 Change this program to calculate and display the rectangle's
 - perimeter.
 
*/

#include <iostream>
#include <iomanip>
using namespace std;

class Rectangle
{
   private:
    double width;
    double length;
   public:
    // setters
    void setWidth(double w) { width = w; }
    void setLength(double len) {length = len; }
      
    // getters
    double getWidth() const { return width; }
    double getLength() const { return length; }
    
    // other functions
    double calculateArea() const { return width * length; }
    double calculatePerimeter() const { return 2 * width + 2 * length; }
};


int main()
{
    double houseWidth;   // To hold the room width
    double houseLength;  // To hold the room length

   // Get the width of the house.
   cout << "In feet, how wide is your house? ";
   cin >> houseWidth;

   // Get the length of the house.
   cout << "In feet, how long is your house? ";
   cin >> houseLength;
   
   // Create a Rectangle object and use setters to assign values to its data members
    Rectangle house;
    
    house.setWidth(houseWidth);
    house.setLength(houseLength);
    
   // Display the house's width, length, and area.
   cout << setprecision(2) << fixed;
   cout << endl;
   cout << "The house is " << house.getWidth()
        << " feet wide.\n";
   cout << "The house is " << house.getLength()
        << " feet long.\n";
   cout << "The house has " << house.calculateArea()
        << " square feet of area.\n";
   
   // Display the perimeter below
   /* Write your code here */
   cout << "The house has " << house.calculatePerimeter() << " feet of perimeter.\n";
    
   return 0;
}
/*
 Save the OUTPUT below
 
 
*/

