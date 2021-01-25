from turtle import *
import random
shape("triangle")
hideturtle()
aScore = 0
bScore = 0
aMinDist = 300
bMinDist = 300
aColor = ("Lime")
bColor = ("Silver")

def drawCircle(color,radius):
    penup()
    goto(0,-radius)
    pendown()
    fillcolor(color)
    begin_fill()
    circle(radius)
    end_fill()
def arrowShot(color):
    penup()
    fillcolor(color)
    goto(0,0)
    distance = random.randint(0,300)
    setheading(random.randint(0,359))
    forward(distance)
    pendown()
    setheading(90)
    stamp()
    return distance
def getScore(distance):
    if distance>= 0 and distance<= 100:
        score = 10
    elif distance>= 101 and distance<= 201:
        score = 7
    else:
        score = 5
    return score
drawCircle("Blue",300)
drawCircle("Red",200)
drawCircle("Yellow",100)

dist = arrowShot(aColor)
aScore = aScore + getScore(dist)
if dist < aMinDist:
    aMinDist = dist

dist = arrowShot(aColor)
aScore = aScore + getScore(dist)
if dist < aMinDist:
    aMinDist = dist

dist = arrowShot(aColor)
aScore = aScore + getScore(dist)
if dist < aMinDist:
    aMinDist = dist

dist = arrowShot(bColor)
bScore = bScore + getScore(dist)
if dist < bMinDist:
    bMinDist = dist

dist = arrowShot(bColor)
bScore = bScore + getScore(dist)
if dist < bMinDist:
    bMinDist = dist

dist = arrowShot(bColor)
bScore = bScore + getScore(dist)
if dist < bMinDist:
    bMinDist = dist
    
print("Archer A:", aScore)
print("Archer B:", bScore)

if aScore > bScore: 
    print("Archer A has won with", aScore, "points.")
elif bScore > aScore:
    print("Archer B has won with", bScore, "points.")
else:
    if aMinDist > bMinDist:
        print("Archer A is the winner.")
    elif bMinDist > aMinDist:
        print("Archer B is the winner.")
    else:
        print("The match is a tie.")
        
