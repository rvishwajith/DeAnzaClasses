// Rohith Vishwajith
// CIS22B
// Midterm 2

#include <iostream>
#include <iomanip>
using namespace std;

class Book {
   private:
    string name;
    int year;
    double price;
   public:
    Book(string n, int a, double h);
    
    string GetTitle() {
        return name;
    }
    
    int GetYear() {
        return year;
    }
};

Book::Book(string n, int a, double h)
{
    name = n;
    year = a;
    price = h;
}

// step 1 check if there are any books
// step 2 create array
// step 3 initialize arrays in loop
// step 4 delete original array
// return
bool seperate(Book books[], int size, string tAry[], int yAry[]) {
    
    if (size == 0) {
        return false;
    }
    
    tAry = new string[size];
    yAry = new int[size];
    
    for(int i = 0; i < size; i++) {
        
        // change to gettitle
        string title = books[i].GetTitle();
        // change to getyear
        int year = books[i].GetYear();
        
        tAry[i] = title;
        yAry[i] = year;
    }
    
    delete[] books;
    return true;
}

int main() {
    
    Book bAry[] = {
        {"C++", 2015, 45.99},
        {"Python", 2016, 75.25},
        {"Java", 2014, 40.00},
        {"Perl", 2016, 88.99}
    };
    
    string *tAry;
    int *yAry;
    
    cout << seperate(bAry, 4, tAry, yAry);
}
