#include <iostream>
#include <string>
using namespace std;

struct Exam {
    string word;
    int points;
    int table[7][7];
};

void computePoints(Exam ary[], int size, string target);

int main() {
    Exam ary[100]; // max of list is 100
    int n = 45; // size of list
    string target = "red";
}

void computePoints(Exam ary[], int size, string target) {
    // parse "ary"
    // each word in the list = ary[i].word
    // if word == target -> points = sum table[i][0] and table [0][i]
    // I was kind of confused what the scope of "points" was, so I made the total points
    // as well for outside of the loop and points whos scope is inside the loop
    int totalPoints = 0;
    
    for(int i = 0; i < size; i++) {
        
        int points = 0;
        if(ary[i].word == target) {
            // if condition 1 is satisfied:
            // make points the sum of the first column and the first row
            // the 2d array is a square, so this is safe
            for(int i = 0; i < 7; i++) {
                // first row
                points += ary[i].table[0][i];
                // first column
                points += ary[i].table[i][0];
            }
        }
        totalPoints += points;
    }
}
