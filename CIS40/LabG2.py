import random
secretNum = random.randint(1, 100)
guess = int(input("Enter a guess: "))
while secretNum != "guess":
  print
  if guess < secretNum:
    print ("Guess is low")
    guess = int(input("Enter a guess: "))
  elif guess > secretNum:
    print ("Guess is high")
    guess = int(input("Enter a guess: "))
  else:
    print ("Correct")
    break
"""
============ RESTART: F:/FALL 2020 CLASSES/INTRO TO PYTHON/UnitG2.py ===========
Enter a guess: 50
Guess is high
Enter a guess: 25
Guess is high
Enter a guess: 15
Guess is low
Enter a guess: 20
Guess is low
Enter a guess: 21
Correct
"""
