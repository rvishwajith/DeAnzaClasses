from turtle import *
hideturtle()
up()
size = 70
upperLeftX = -4 * size
upperLeftY = 0
speed(0)

def drawSquare(x,y,color):
    goto(x,y)
    fillcolor(color)
    begin_fill()
    for i in range(4):
        fd(size)
        rt(90)
    end_fill()

color = "black"

for column in range(8):
    if color == "black":
        color = "red"
    else:
        color = "black"
    drawSquare(upperLeftX, upperLeftY, color)
    upperLeftX = upperLeftX + size
