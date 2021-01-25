"""
Author: Rohith Vishwajith
Course: CIS40
Assignment: Unit B In-class Assignment
Date: 9/23/20
Description: The in-class assignment for Unit B.
"""

print("This is line 1 of the script")
print("This is line 2 of the script")
print("This is line 3 of the script")
x = 1/3

"""
Terminal Input:
>> python Lab1.py

Execution Results (With Error Missing Parentheses):
>>   File "Lab1.py", line 11
>>     print("This is line 3 of the script")
>>         ^
>> SyntaxError: invalid syntax

Execution Results (With Error 1/0):
>> File "Lab1.py", line 12, in <module>
>>     x = 1/0
>> ZeroDivisionError: integer division or modulo by zero

Execution Results (Final):
>> This is line 1 of the script
>> This is line 2 of the script
>> This is line 3 of the script
"""