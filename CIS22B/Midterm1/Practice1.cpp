c

struct Game {
    string name;
    int points;
};

int showAverages(Game list[]);

int main() {
    
    Game list[40] =
    {
        {"Bob Doe", 23},
        {"Bob Doe", 0},
        {"Bob Doe", 20},
        {"Dan Jo", 0},
        {"John Smith", 18},
        {"John Smith", 10},
        {"", 999},
    };
    showAverages(list);
}

int showAverages(Game list[]) {
    
    // We know the name has changed if it is not the first struct name AND is not equal to the prior struct's name
    
    // iterator
    int i = 0;
    
    // total points of the currentname
    double currentTotal = 0;
    // total number of values for the current name
    double currentVals = 0;
    
    do {
        
        bool nameChanged = false;
        
        // name has changed
        if(i > 0 && list[i].name != list[i - 1].name) {
            nameChanged = true;
        }
        
        if(nameChanged && currentVals) {
            cout << list[i-1].name << ": " << currentTotal/currentVals << endl;
            currentTotal = 0;
            currentVals = 0;
        }
        else {
            if(list[i].points > 0) {
                currentVals++;
                currentTotal += list[i].points;
            }
        }
        
        i++;
    }
    while (list[i].name != "" && list[i].points != 999);
    
    return 2;
}
