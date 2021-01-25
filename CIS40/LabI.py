tagChoice = input("Enter one to four tags that you are interested in: Action, Adventure, Arcade, Casual, Funny, Horror, Indie, Puzzle, Racing, RPG, Simulation, Strategy: ").split()
tagNum = len(tagChoice)
handle = open("Lab9_CatGames.txt")
gameList = []

for line in handle:
    matchcount = 0
    infoList = line.split()
    for tag in tagChoice:
        if tag in infoList:
            matchcount = matchcount + 1
    if matchcount == tagNum:
        gameList.append(infoList[0])
handle.close()

if len(gameList) == 0:
    print("Sorry, no games match your criteria.")
else:
    print("There are", len(gameList), tagChoice, "games.", "Games that match your choice:")
    for line in gameList:
        wordList = line.split()
        for word in wordList:
            print(word, end = " ")
        print()


"""
Test:
There are 19 ['Action'] games. Games that match your choice:
AttackCat 
BlinkyCat 
BorisCat 
CalicoCat 
CatEye 
CatFish 
CatSoup 
CatTales 
ChesireCat 
ColossalCat 
DancingCat 
EpiCat 
FatCats 
HelloKitty 
MagicCat 
PaddingtonCat 
QuixoticCat 
SchrodingerCat 
SleepyCat
"""
