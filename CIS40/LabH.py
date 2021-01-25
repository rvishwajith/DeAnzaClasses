import random

rollA = 0
rollB = 0
totalA = 0
totalB = 0

A = open("Player_A.txt", "w")
B = open("Player_B.txt","w")

for i in range(3):
    rollA = random.randint(1,6)
    A.write(str(rollA))
    A.write("\n")
    rollB = random.randint(1,6)
    B.write(str(rollB))
    B.write("\n")
A = open("Player_A.txt")
B = open("Player_B.txt")

for line in A:
    totalA = totalA + int(line)
for line in B:
    totalB = totalB + int(line)
A.close()
B.close()
if(totalA > totalB):
    print("Winner: Player A")
    print("Player A:", totalA, "Player B:", totalB)
elif(totalA < totalB):
    print("Winner: Player B")
    print("Player A:", totalA, "Player B:", totalB)
else:
    print("ie")
    print("Player A:", totalA, "Player B:" , totalB)
"""
Results:
============ RESTART: F:/FALL 2020 CLASSES/INTRO TO PYTHON/UnitH.py ============
Winner: Player A
Player A: 17 Player B: 9
"""
