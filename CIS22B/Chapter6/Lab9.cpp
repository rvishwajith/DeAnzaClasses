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
    Rectangle(){ width = 0; length = 0;} // default constructor
    
    Rectangle(double w, double l) {
       width = w;
       length = l;
    }
    
    // setters
    void setWidth(double w) { width = w; }
    void setLength(double len) {length = len; }
      
    // getters
    double getWidth() const { return width; }
    double getLength() const { return length; }
    
    // other functions
    double calculateArea() const { return width * length; }
    /* Write your code here */
    double calculatePerimeter() const { return 2* width + 2 * length; }
};


int main()
{
    // Demonstrate the default constructor
    // Create a Rectangle object and use the default constructor to assign values to its data members
    Rectangle house1;
   
    // Display the house's width, length, and area.
    cout << setprecision(2) << fixed;
    cout << endl;
    cout << "The house is " << house1.getWidth()
         << " feet wide.\n";
    cout << "The house is " << house1.getLength()
         << " feet long.\n";
   
    // Demonstrate the overloaded constructor
    double houseWidth;   // To hold the room width
    double houseLength;  // To hold the room length

    // Get the width of the house.
    cout << "In feet, how wide is your house? ";
    cin >> houseWidth;

    // Get the length of the house.
    cout << "In feet, how long is your house? ";
    cin >> houseLength;
   
    
   
    // Create a Rectangle object and use the overloaded constructor to assign values to its data members
    Rectangle house = Rectangle(houseWidth, houseLength);/* Write your code here */;
                            // Do not call the setters

    // Display the house's width, length, and area.
    cout << setprecision(2) << fixed << endl;
    cout << "The house is " << house.getWidth()
         << " feet wide.\n";
    cout << "The house is " << house.getLength()
         << " feet long.\n";
    cout << "The house has " << house.calculateArea()
         << " square feet of area.\n";
    
    cout << "The house has " << house.calculatePerimeter() << " feet of perimeter.\n";
    
   
    return 0;
}
/*
 Save the OUTPUT below
 
 
*/

