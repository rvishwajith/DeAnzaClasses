// Rohith Vishwajith
// CIS22B
// Chapter 4
// XCode - Lab4.cpp
// 10/19/20
// Zybooks Lab 4.4 - Arrays of Pointers to Structures (Sort)

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

struct Airport
{
    string code;
    string city;
    int enp;
};

// function prototypes
Airport *readArpData(string filename, int &size);
Airport **createPtrArray(Airport *list, int size);
void insertSort(Airport **pArp, int size);
void displayReport(Airport **pArp, Airport *list, int size);

int main()
{
    Airport *list;  // pointer to work with a dynamically allocated array of structs
    Airport **pArp; // pointer to work with an array of pointers to structs
    int size;
    string filename = "airports.txt";
    
    // function calls
    cout << "Enter input file name: ";
    cin >> filename;
    
    list = readArpData(filename, size);
    pArp = createPtrArray(list, size);
    insertSort(pArp, size);
    displayReport(pArp, list, size);
  
    return 0;
}

/*~*~*~*~*~*~
This function does the following:
 - opens the input file(with validation: exit if file not found)
 - reads size from the input file (the first number)
 - dynamically allocates an array of size Airport structures
 - reads data for size airports into the dynamically allocated array
 - closes the input file
 - returns the pointer to the dynamically allocated array
*~*/
Airport *readArpData(string filename, int &size)
{
    ifstream inputFile;
    Airport *list;
    
    //open the file
    inputFile.open(filename);
    
    //check exception
    if(inputFile.fail()){
        cout << "Error opening the input file: " << filename << "." << endl;
        exit(EXIT_FAILURE);
    }

    // when a string is read in (one line of the file)
    string line;
    inputFile >> size;
    list = new Airport[size];

    for(int i = -1; i < size; i++) {
      
      getline(inputFile, line);

      if(i >= 0) {
        //cout << "Line|" << line << "|"<< endl;
        string code = line.substr(0, line.find(" "));
        line = line.substr(code.length() + 1, line.length() - 1);

        
        string intTemp = line.substr(0, line.find(" "));
        int enp = stoi(intTemp, nullptr, 10);

        line = line.substr(intTemp.length() + 1, line.length() - 1);
        string city = line;

        Airport a = {code, city, enp};
        list[i] = a;
      }
    }
    inputFile.close();

    return list;
}

/*~*~*~*~*~*~
This function does the following:
- takes an array of n pointers to Airport structures
- initialize each pointer to point to the corresponding
element in the array of Airport structures.

*~*/
Airport **createPtrArray(Airport *list, int size)
{
    Airport **pArp;
    pArp = new Airport*[size];
    
    for(int i = 0; i < size; i++) {
        pArp[i] = &list[i];
    }
    
    return pArp;
}

/*~*~*~*~*~*~
This function does the following:
- sorts an array of n p.nters to Airports structures
using an insertion sort.
*~*/
void insertSort(Airport **list, int size)
{
    bool flag = true;
    Airport *temp;
    for(int i = size - 1; i > 0 && flag; i--) {
        flag = false;
        for (int j = 0; j < i; j++) {
            if (list[j+1] -> enp >= list[j] -> enp) {
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
                flag = true;
            }
        }
    }
}

/*~*~*~*~*~*~
This function does the following:
- prints out the airport data in the provided format, for both
and descending order:
BFL Bakersfield        100433
*~*/
void displayReport(Airport **pArp, Airport *list, int size)
{
    cout << "\nOriginal Data                    Descending (enp)" << endl;
    for (int i = 0; i < size; i++){
        cout << list[i].code << " "
             << setw(15) << left << list[i].city
             << setw(10) << right << list[i].enp << "    ";
        cout << pArp[i] -> code << " "
             << setw(15) << left << pArp[i]->city
             << setw(10) << right << pArp[i]->enp << endl;
    }
}
