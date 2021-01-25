// Rohith Vishwajith
// CIS22B
// Chapter 2
// XCode - Lab8.cpp
// 9/29/20
// Zybooks Lab 2.8 - Airports (2D Arrays and Files)

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int MAXARP = 15;  // maximum number of airports in a state

//function prototypes
void readData(string fileName, string airports[], int price[][MAXARP], const int MAXARP, int &size);
int getMenuOption(int low, int high);
void displayTable(const string airports[], const int price[][MAXARP], const int size);
void countDestination(const int price[][MAXARP], int numOfDestination[MAXARP], const int size);
void displayDestination(const string airports[],const int price[][MAXARP],
                        const int numOfDestination[MAXARP], const int size);
void displayConnection(const string airports[], const int price[][MAXARP], const int size);

int main( void )
{
    //array definitions
    string airports[MAXARP];
    int price[MAXARP][MAXARP];
    int numOfDestination[MAXARP] = {0};

    //other variables
    int size = 0; // actual number of airports in the file
    string fileName;

    // read data from file
    cout << "What is the input file's name? ";
    cin >> fileName;
    readData(fileName, airports, price, MAXARP, size);
    int option = getMenuOption(1, 4);
    switch( option )
    {
        case 1: // display the original informations as a table
            /* Write your code here: call diplayTable */
            displayTable(airports, price, size);
            break;
        case 2: // count the number of destination
            /* Write your code here: call countDestination */
            countDestination(price, numOfDestination, size);
                // list each airport's destinations, including the number of destination airports
            /* Write your code here: call displayDestination */
            displayDestination(airports, price, numOfDestination, size);
            break;
        case 3: // list all groups of two airports connected by flights, including the flight price
             /* Write your code here: call displayConnection */
            displayConnection(airports, price, size);
            break;
        case 4: cout << "\n\nEnd of Program!" << endl;
            break;
    }
    
    
    return 0;
}   // main

/*~*~*~*~*~*~
 This function displays the menu
*~*/
void displayMenu()
{
    cout << "Choose one of the following options: " << endl;
    cout << " 1. Display the original informations as a table" << endl;
    cout << " 2. Display each airport's destinations, including the number of destination airports" << endl;
    cout << " 3. Display direct flights, including price" << endl;
    cout << " 4. Exit the program" << endl;
}

/*~*~*~*~*~*~
 This function calls a function to display the program's menu
 and gets a valid option from the user
*~*/
int getMenuOption( int low, int high)
{
    if( low > high) // if out of order, swap
    {
        int hold = low;
        low = high;
        high = hold;
    }
    
    displayMenu();
    
    int option;
    bool success;
    do
    {
        cout << "Please enter a number (" << low << " to " << high << "): ";
        success = (bool)(cin >> option);
        cin.clear();          // to clear the error flag
        cin.ignore(80, '\n'); // to discard the unwanted input from the input buffer
    }while(!success || option < low || option > high);

    return option;
}

/*~*~*~*~*~*~
 This function reads data into two parallel arrays.
 The 1D string array holds the airports codes while 2D array holds the flight price of
 each airport connected to another. The first line of the file represents the number of airports,
 which will be stored in the size variable.
*~*/
void readData(string fileName, string airports[], int price[][MAXARP], const int MAXARP, int &size){
    ifstream inputFile;
    //open the file
    inputFile.open(fileName);
    
    //check exception
    if(inputFile.fail()){
        cout << "Please check the file. Try again.\n";
        exit(EXIT_FAILURE);
    }

    //read numbers of airports
    inputFile >> size;
    if(size > MAXARP) {
        cout << "\nInput from file: " << size << "." << endl << "It is greater than 15, the array's capacity." << endl << "Program ends here!\n";
        exit (EXIT_FAILURE);
    }

    // check if size reaches maximum size of array
      /* Write your code here */

    // read airports codes into 1D array
    for (int r = 0; r < size; r++ )
    {
        inputFile >> airports[r];
    }

    // read flight price between two airports into 2D array
    /* Write your code here */
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            inputFile >> price[i][j];
        }
    }
    
    inputFile.close();
}

/*~*~*~*~*~*~
 This function display the airports codes and information as a table. The header and first row list
 all airport codes. The number represents the flight price of two airports. '0' means no flights
 between these two airports.
*~*/
void displayTable(const string airports[], const int price[][MAXARP], const int size){
    cout << "\n\nAirport codes and original table:\n\n";
    
    // Line 1
    cout << "    | ";
    for(int i = 0; i < size; i++) {
        cout << airports[i];
        if(i < size - 1) {
            cout << " ";
        }
    }
    cout << endl;
    
    // Line 2
    cout << "---   ";
    for(int i = 0; i < size; i++) {
        cout << "---";
        if(i < size - 1) {
            cout << " ";
        }
    }
    cout << endl;
    
    // Remaining Lines
    for(int i = 0; i < size; i++) {
        cout << airports[i] << " | ";
        for(int j = 0; j < size; j++) {
            cout << right << setw(3) << price[i][j];
            if(j < size - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    
    cout << endl;
}

/*~*~*~*~*~*~
 This function counts the number of destination from one airports to another, then stores it into one
 1D parallel array.
*~*/
void countDestination(const int price[][MAXARP], int numOfDestination[MAXARP], const int size){
     
    for(int i = 0; i < size; i++) {
        int numAirports = 0;
        
        for(int j = 0; j < size; j++) {
            if(price[i][j] > 0) {
                numAirports++;
            }
        }
        numOfDestination[i] = numAirports;
    }
}

/*~*~*~*~*~*~
 This function displays each airports' destinations, including the number of destination airports.
*~*/
void displayDestination(const string airports[], const int price[][MAXARP],
                        const int numOfDestination[MAXARP], const int size){
    cout << "\n\nAirports' destinations: \n\n";
    /* Write your code here */
    for(int i = 0; i < size; i++) {
        
        cout << airports[i] << " (" << numOfDestination[i] << "): ";
        int numOfCommas = numOfDestination[i] - 1;
        
        for(int j = 0; j < size; j++) {
            
            if(price[i][j] > 0) {
                cout << airports[j];
                if(numOfCommas > 0) {
                    cout << ", ";
                    numOfCommas--;
                }
            }
        }
        cout << endl;
    }
    cout << endl;
}

/*~*~*~*~*~*~
 This function displays all groups of two airports connected by flights, including flight.
 It determines whether two airports are connected by checking the right side of diagonal of flight price.
 It will print groups of two airports including flight price if price is not zero, otherwise no connected
 between two airports.
*~*/
void displayConnection(const string airports[], const int price[][MAXARP], int size){
    cout << "\n\nDirect Flights: \n\n";
    
    /* Write your code here */
    /*
    for(int i = 0; i < size; i++) {
        
        for(int j = 0; j < size; j++) {
            if(price[i][j] > 0 && price[j][i] > 0) {
                cout << airports[i] << " -> " << airports[j] << endl;
            }
        }
    }
     */
    
    for(int i = 0; i < size; i++) {
        for(int j = i; j < size; j++) {
            if(price[i][j] > 0) {
                cout << airports[i] << " -> " << airports[j] << right << setw(4) << price[i][j] << endl;
            }
        }
    }
    cout << endl;
}
/** Save the output below

 */
