'''
Author: Rohith Vishwajith
Course: CIS40
Assignment: Unit C In-class Assignment
Date: 9/28/20
Description: The in-class assignment for Unit C.
'''

# Part 1
yourName = input("Please enter your name -> ")
print("Hello", yourName) # a space is autmoatically added

# Part 2
whatAmI = 10
print() # new line without space separation
print(type(whatAmI))

whatAmI = 1.5
print(type(whatAmI))

whatAmI = "Hi"
print(type(whatAmI), "\n")

# Part 3
num1 = int(input("Plase enter a number -> "))
num2 = int(input("Please enter a second number -> "))
print(num1, '-', num2, '=', num1 - num2)
print(num2, '/', num1, '=', num2/num1)
print(num1, '**', num2, '=', num1**num2)
print(num1, '*', num2, '**', num2, num1 * num2 ** num2)
print(num1, '%', num2, '=', num1%num2)

'''
OUTPUT:

Part 1 Output:
>> Please enter your name -> Rohith
>> Hello Rohith

Part 2 Output:
>> <class 'int'>
>> <class 'float'>
>> <class 'str'>

Part 3 Output:
>> Plase enter a number -> 5
>> Please enter a second number -> 3
>> 5 - 3 = 2
>> 3 / 5 = 0.6
>> 5 ** 3 = 125
>> 5 * 3 ** 3 135
>> 5 % 3 = 2
'''