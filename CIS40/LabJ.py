class ParkingLot:
    def __init__(self, name,  totalSpaces, filledSpaces):
        self.name = name
        self.totalSpaces = totalSpaces
        self.filledSpaces = filledSpaces
    def __str__(self):
        return "Name:" + str(self.name) + "\nfilled:" + str(self.filledSpaces) + "\ntotal:" + str(self.totalSpaces)
    def letCarIn(self):
        if self.totalSpaces - self.filledSpaces != 0:
            self.filledSpaces = self.filledSpaces + 1
            return "Open Gate"
        else:
            return "Lot full, gate stays closed."
    def letCarOut(self):
        self.filledSpaces = self.filledSpaces - 1
        return "Open Gate"
    def lotStatus(self):
        if self.totalSpaces - self.filledSpaces != 0:
            return "Spaces available"
        else:
            return "No spaces available"
    def getFilledSpaces(self):
        return str(self.filledSpaces)

lot1 = ParkingLot("Downtown", 80, 79)
lot2 = ParkingLot("Northside", 40, 20)
print(lot1)
print(lot1.lotStatus())
gateAction = lot1.letCarIn()
print(gateAction)
print(lot1.lotStatus())
gateAction = lot1.letCarIn()
print(gateAction)
gateAction = lot1.letCarOut()
print(gateAction)
print(lot1)
print(lot2)

"""
TEST RESULTS
Name:Downtown
filled:79
total:80
Spaces available
Open Gate
No spaces available
Lot full, gate stays closed.
Open Gate
Name:Downtown
filled:79
total:80
Name:Northside
filled:20
total:40
"""
