'''
CIS40 - Introductory Python
Final Project
Includes components from Python’s default Turtle and TKinter frameworks, and uses standardized 3D rendering algorithms adapted from the Java Swing 3D rendering engine.

Members:
- Rohith Vishwajith
- Daniel Hatman
- Nathan Koo
- Justin Yip
- Thien Hoang
- Nofil Amer
- Michael Wang
'''

import math, time
import turtle

RENDER_MODE = 'wire' # modes are: wire, dot
turtle.speed(100)
turtle.hideturtle()


class cube():
  def __init__(self,size,width,height):
      s = (size * 10)
      
      # Vertices in 3D space
      self.verts = [
          [1.000000, 1.000000, -1.000000],
          [1.000000, -1.000000, -1.000000],
          [1.000000, 1.000000, 1.000000],
          [1.000000, -1.000000, 1.000000],
          [-1.000000, 1.000000, -1.000000],
          [-1.000000, -1.000000, -1.000000],
          [-1.000000, 1.000000, 1.000000],
          [-1.000000, -1.000000, 1.000000],
          [1.000000, -1.000000, 0.400000],
          [1.000000, -1.000000, -0.400000],
          [1.000000, 0.200000, 0.400000],
          [1.000000, 0.200000, -0.400000],
          [1.000000, 2.000000, -0.038346],
          [1.000000, 2.000000, 0.038346],
          [-1.000000, 2.000000, -0.038346],
          [-1.000000, 2.000000, 0.038346],
          [-0.624934, -0.420866, 1.000000],
          [-0.624934, 0.420866, 1.000000],
          [0.624934, 0.420866, 1.000000],
          [0.624934, -0.420866, 1.000000]
      ]
      
      self.face = [
        [[7, 8, 17, 18],
        [8, 7, 5, 6],
        [6, 2, 10, 9, 4, 8],
        [2, 1, 3, 4, 9, 11, 12, 10], # Faces don't have to be quadrilaterals
        [6, 5, 1, 2],
        [10, 12, 11, 9],
        [1, 5, 15, 13],
        [7, 3, 14, 16],
        [14, 13, 15, 16],
        [1, 13, 14, 3],
        [7, 16, 15, 5],
        [20, 19, 18, 17],
        [8, 4, 20, 17],
        [3, 7, 18, 19],
        [4, 3, 19, 20]]
      ]

class custom():
  def __init__(self, verts, faces):
    self.face = faces
    self.verts = verts

#Shapes defined below

shapes = [custom([
  [1.000000, 1.000000, -1.000000],
  [1.000000, -1.000000, -1.000000],
  [1.000000, 1.000000, 1.000000],
  [1.000000, -1.000000, 1.000000],
  [-1.000000, 1.000000, -1.000000],
  [-1.000000, -1.000000, -1.000000],
  [-1.000000, 1.000000, 1.000000],
  [-1.000000, -1.000000, 1.000000],
  [1.000000, -1.000000, 0.400000],[1.000000, -1.000000, -0.400000],
  [1.000000, 0.200000, 0.400000],
  [1.000000, 0.200000, -0.400000],
  [1.000000, 2.000000, -0.038346],
  [1.000000, 2.000000, 0.038346],
  [-1.000000, 2.000000, -0.038346],
  [-1.000000, 2.000000, 0.038346],
  [-0.624934, -0.420866, 1.000000],
  [-0.624934, 0.420866, 1.000000],
  [0.624934, 0.420866, 1.000000],
  [0.624934, -0.420866, 1.000000]
 ],

 [
  [[7, 8, 17, 18], [8, 7, 5, 6], [6, 2, 10, 9, 4, 8], [2, 1, 3, 4, 9, 11, 12, 10], [6, 5, 1, 2], [10, 12, 11, 9], [1, 5, 15, 13], [7, 3, 14, 16], [14, 13, 15, 16], [1, 13, 14, 3], [7, 16, 15, 5], [20, 19, 18, 17], [8, 4, 20, 17], [3, 7, 18, 19], [4, 3, 19, 20]]
 ]  
),

custom([
  [0.520834, -0.198774, 0.405077],
  [-0.844957, -0.961232, 0.914078],
  [0.520834, -0.959615, -0.405077],
  [-0.844957, -0.961232, -1.001075],
  [0.520834, -0.959615, 0.405077],
  [0.891278, -0.961232, 0.914078],
  [0.891278, -0.961232, -1.001075],
  [-0.778643, -0.955444, 0.530367],
  [-0.778643, -0.499706, 0.530367],
  [-0.778643, -0.955444, -0.530367],
  [-0.778643, -0.499706, -0.530367],
  [-0.322905, -0.955444, 0.530367],
  [-0.322905, -0.499706, 0.530367],
  [-0.322905, -0.955444, -0.530367],
  [-0.322905, -0.499706, -0.530367],
  [-0.648670, -0.499706, 0.395949],
  [-0.648670, -0.499706, -0.395949],
  [-0.324070, -0.499706, -0.395949],
  [-0.324070, -0.499706, 0.395949],
  [-0.324070, -0.731707, -0.395949],
  [-0.324070, -0.731707, 0.395949],
  [-0.648670, -0.731372, 0.395949],
  [-0.648670, -0.733062, -0.395949],
  [-0.778643, -0.323614, 0.530367],
  [-0.778643, -0.323614, -0.530367],
  [-0.648670, -0.323614, 0.395949],
  [-0.648670, -0.323614, -0.395949],
  [-0.762370, -0.284167, 0.397563],
  [-0.762370, -0.284167, -0.397563],
  [-0.664943, -0.284167, 0.296804],
  [-0.664943, -0.284167, -0.296804],
  [0.002068, -0.822429, 0.384497],
  [0.002068, -0.793784, 0.384497],
  [0.002068, -0.822429, -0.384497],
  [0.002068, -0.793784, -0.384497],
  [0.269089, -0.822429, 0.384497],
  [0.269089, -0.793784, 0.384497],
  [0.269089, -0.822429, -0.384497],
  [0.269089, -0.793784, -0.384497],
  [0.107188, -0.818603, -0.081760],
  [0.107188, -0.818603, 0.081760],
  [0.163968, -0.818603, -0.081760],
  [0.163968, -0.818603, 0.081760],
  [0.107188, -0.991159, -0.081760],
  [0.107188, -0.991159, 0.081760],
  [0.163968, -0.991159, -0.081760],
  [0.163968, -0.991159, 0.081760],
  [0.520834, -0.198774, -0.405077],
  [0.795448, -0.959615, 0.405077],
  [0.795448, -0.198774, 0.405077],
  [0.795448, -0.959615, -0.405077],
  [0.795448, -0.198774, -0.405077],
  [0.520834, -0.282412, 0.305858],
  [0.520834, -0.282412, -0.305858],
  [0.520834, -0.702440, -0.305858],
  [0.520834, -0.702440, 0.305858],
  [0.590787, -0.282412, 0.305858],
  [0.590787, -0.282412, -0.305858],
  [0.590787, -0.702440, -0.305858],
  [0.590787, -0.702440, 0.305858]
 ],

 [
  [[51, 52, 50, 49],
  [3, 48, 52, 51],
  [7, 4, 2, 6],
  [8, 9, 11, 10],
  [10, 11, 15, 14],
  [14, 15, 18, 20],
  [12, 13, 9, 8],
  [17, 11, 25, 27],
  [9, 13, 19, 16],
  [15, 11, 17, 18],
  [12, 21, 19, 13],
  [16, 19, 21, 22],
  [20, 18, 17, 23],
  [17, 16, 22, 23],
  [22, 21, 20, 23],
  [14, 20, 21, 12],
  [27, 25, 29, 31],
  [16, 17, 27, 26],
  [9, 16, 26, 24],
  [11, 9, 24, 25],
  [29, 28, 30, 31],
  [26, 27, 31, 30],
  [24, 26, 30, 28],
  [25, 24, 28, 29],
  [32, 33, 35, 34],
  [34, 35, 39, 38],
  [38, 39, 37, 36],
  [36, 37, 33, 32],
  [38, 36, 43, 42],
  [39, 35, 33, 37],
  [42, 43, 47, 46],
  [36, 32, 41, 43],
  [34, 38, 42, 40],
  [32, 34, 40, 41],
  [5, 1, 53, 56],
  [41, 40, 44, 45],
  [43, 41, 45, 47],
  [40, 42, 46, 44],
  [49, 50, 1, 5],
  [52, 48, 1, 50],
  [56, 53, 57, 60],
  [3, 5, 56, 55],
  [48, 3, 55, 54],
  [1, 48, 54, 53],
  [60, 57, 58, 59],
  [53, 54, 58, 57],
  [55, 56, 60, 59],
  [54, 55, 59, 58]]
 ]
)
] 


# Zoom factor, increase to increase size
zoom = 200 

# Incraeses size of objects, by geting the objects vert and * it by the zoom factor
for x in range(0,len(shapes)):
  for s in range(0,len(shapes[x].verts)):
    for f in range(0,len(shapes[x].verts[s])):
      shapes[x].verts[s][f] = shapes[x].verts[s][f] * zoom


def rotateZ(theta): # Rotation For Z
  for shape in range(0,len(shapes)):
    sinTheata = math.sin(theta)
    cosTheata = math.cos(theta)
    for x in range(0,len(shapes[shape].verts)):
      vert = shapes[shape].verts[x]
      x = vert[0]
      y = vert[1]
      vert[0] = x * cosTheata - y * sinTheata
      vert[1] = y * cosTheata + x * sinTheata

def rotateX(theta): # Rotation For X
  for shape in range(0,len(shapes)):
    sinTheata = math.sin(theta)
    cosTheata = math.cos(theta)
    for x in range(0,len(shapes[shape].verts)):
      vert = shapes[shape].verts[x]
      y = vert[1]
      z = vert[2]
      vert[1] = y * cosTheata - z * sinTheata
      vert[2] = z * cosTheata + y * sinTheata

def rotateY(theta): # Rotation For CY
  for shape in range(0,len(shapes)):
    sinTheata = math.sin(theta)
    cosTheata = math.cos(theta)
    for x in range(0,len(shapes[shape].verts)):
      vert = shapes[shape].verts[x]
      x = vert[0]
      z = vert[2]
      vert[0] = x * cosTheata + z * sinTheata
      vert[2] = z * cosTheata - x * sinTheata

turtle.tracer(0,0)
screen = turtle.getscreen()

## Rendering

turtle.color('cyan')
turtle.pensize(4)

def getKey(item): # Used for the list sort method, used for calculating the cliping plane / viewing distance
  return item[0]

def wire(shape): # Wire rendering by going to each vert defined by a face
  verts = shapes[shape].verts
  face = shapes[shape].face
  toggle = 0
  
  for x in range(0, len(face)):
    for e in range(0,len(face[x])):
      edge0 = verts[face[x][e][0] - 1] * 5
      turtle.penup()
      for b in range(0,len(face[x][e])):
        edge = verts[face[x][e][b] - 1]
        turtle.color('cyan')
        turtle.goto(edge[0],edge[1])
        turtle.dot(5)
        turtle.pendown()
      turtle.goto(edge0[0],edge0[1])

# dot rendering: vertices are represented as a circle
def dot(shape):
  verts = shapes[shape].verts
  face = shapes[shape].face
  toggle = 0
  turtle.penup()

  for x in range(0, len(face)):
    for e in range(0,len(face[x])):
      edge0 = verts[face[x][e][0] - 1] * 5
      for b in range(0,len(face[x][e])):
        edge = verts[face[x][e][b] - 1]
        turtle.goto(edge[0],edge[1])
        turtle.dot(5)
      turtle.goto(edge0[0],edge0[1])
    

frame = 0
render = 1

screen.bgcolor('black')

# Increase the frame rate (this could be better)
while True:
  if render == 1:
    frame = frame + 1
    for shape in range(0,len(shapes)):
      
      if RENDER_MODE == 'wire':
        wire(shape)

      if RENDER_MODE == 'dot':
        dot(shape)

  rotateX(0.0021)
  rotateY(0.021)

  turtle.update()
  turtle.clear()
    