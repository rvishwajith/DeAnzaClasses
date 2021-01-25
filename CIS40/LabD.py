'''
Author: Rohith Vishwajith
Course: CIS40
Assignment: Unit D In-class Assignment
Date: 10/13/20
Description: The in-class assignment for Unit D.
'''

'''
Takes user input for a name and prints a response
'''
def welcome():
  name = input("Please enter your name -> ")
  print("Hello", name, "let's have some geometry fun!")

'''
side - the sidelength of the square

Calculates the area of a square given a sidelength and prints it
'''
def printSquareArea(side):
  print("The area of the square with side length", side, "is", side * side)

'''
length - the length of the rectangle
width - the width of a rectangle

Calculates and returns the area of a rectangle given the dimensions
'''
def calcRectangleArea(length, width):
  return length * width

'''
length - the length of the box
width - the width of the box
height - the height of the box	

Calculates the volume of a box from the given dimensions and prints it
'''
def printRectangleVolume(length, width, height):
  print("The volume of the box is", length * width * height)

welcome()
printSquareArea(3)
print("The area of the rectangle is", calcRectangleArea(4, 5))
printRectangleVolume(4, 5, 6)

'''
OUTPUT:

Part 1 Output:
Please enter your name -> Rohith
Hello Rohith let's have some geometry fun!

Part 2 Output:
The area of the square with side length 3 is 9

Part 3 Output:
The area of the rectangle is 20

Part 4 Output:
The volume of the box is 120

Complete Run Sequence:
Please enter your name -> Rohith
Hello Rohith let's have some geometry fun!
The area of the square with side length 3 is 9
The area of the rectangle is 20
The volume of the box is 120
'''