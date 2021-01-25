// Rohith Vishwajith
// CIS22B
// Chapter 3
// XCode - Lab10.cpp
// 10/9/20
// Zybooks Lab 3.10 - Arrays of Structures (Search and Sort)

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/* Write the definition of the Airport structure with the following fields:
- code, a string
- city, a string
- enp, and integer
*/
struct Airport {
    string code;
    string city;
    int enp;
};

/*
 filename - The name of the file to be read
 list[] - The array of all of the Aiport structs
 max - the max size of the array
 size - the number of declared Airport structs
 */
void readArpData(string filename, Airport list[], int max, int &size);

/*
 filename - The name of the file to be read
 list[] - The array of all of the Aiport structs
 max - the max size of the array
 size - the number of declared Airport structs
 */
void searchTestDriver(Airport list[], int size);

/*
 list[] - The array of all of the Aiport structs
 size - the number of declared Airport structs
 */
void insertSort(Airport list[], int size);

/*
 list[] - The array of all of the Aiport structs
 size - the number of declared Airport structs
 */
void printArpData(Airport list[], int size);

/*
 filename - The name of the file to be written to
 list[] - The array of all of the Aiport structs
 size - the number of declared Airport structs
 */
void writeToFile(string filename, Airport list[], int size);

/*
 list[] - The array of all of the Aiport structs
 size - the number of declared Airport structs
 key - the string that is searched for
 checks for the key in the array of valid Airport structs
*/
int binarySearch(Airport list[], int size, string key);

int main(){
    // constants definitions
    const int AIRPORTS = 30;                 // maximum size of array
    
    // array definition
    Airport list[AIRPORTS];
    
    // other variables
    int size = 0;           // actual size of arrays
    string filename;
    
    // function calls
    cout << "Enter input file name: ";
    cin >> filename;
    readArpData(filename, list, AIRPORTS, size);
    searchTestDriver(list, size);
    insertSort(list, size);
    
    string answer;
    cout << "\nShow Report(Y/N)? ";
    cin >> answer;
    if (answer == "y" || answer == "Y") {
        cout << endl;
        printArpData(list, size);
    }
    writeToFile("report.txt", list, size);
    return 0;
}

void readArpData(string filename, Airport list[], int max, int &size) {
    
    ifstream inputFile;
    //open the file
    inputFile.open(filename);
    
    //check exception
    if(inputFile.fail()){
        cout << "Error opening the input file: " << filename << "." << endl;
        exit(EXIT_FAILURE);
    }

    // when a string is read in (one line of the file)
    string line;

    // Line by line parsing:
    // First space is always after the code
    // Second space is always after number of enplanements -> convert to int
    // Read until end of line for full city
    while(getline(inputFile, line)) {
      string code = line.substr(0, line.find(" "));
      line = line.substr(code.length() + 1, line.length() - 1);
      string intTemp = line.substr(0, line.find(" "));
      int enp = stoi(intTemp, nullptr, 10);
      line = line.substr(intTemp.length() + 1, line.length() - 1);
      string city = line;

      Airport a = {code, city, enp};
      list[size] = a;
      size++;

      if(size >= 30) {
        cout << "\nThe file contains more than 30 lines!" << endl;
        inputFile.close();
        exit(EXIT_FAILURE);
      }
    }
    inputFile.close();

}

void searchTestDriver(Airport list[], int size) {
    bool keepSearch = true;

    while(keepSearch) {
        string inCode;
        cout << "\nPlease enter an airport code, such as LAX: ";
        cin >> inCode;
        cout << endl;

        int num = binarySearch(list, size, inCode);
        if(num != -1) {
            cout << list[num].code << " found! See related data below:\n";
            cout << "        Code: " << list[num].code << endl;
            cout << "        City: " << list[num].city << endl;
            cout << "Enplanements: " << list[num].enp << endl;
        }
        else {
            cout << inCode << " not found!\n";
        }

        string answer;
        cout << "Would you like to look up another airport(Y/N)? ";
        cin >> answer;
        if (answer != "y" && answer != "Y") {
            keepSearch = false;
        }
    }
}

void insertSort(Airport list[], int size) {
    for(int i = 1; i < size; i++) {
        Airport sortVal = list[i];
        
        int j = i;
        while(j > 0 && list[j - 1].enp < sortVal.enp) {
            list[j] = list[j - 1];
            j--;
        }
        list[j] = sortVal;
    }
}

void printArpData(Airport list[], int size) {

    string fileName = "report.txt";
    cout << "Sorted List:\n";

    insertSort(list, size);
    for(int i = 0; i < size; i++) {
      cout << list[i].code << " " << list[i].city << " (" << list[i].enp << ")" << endl;
    }
    
}

void writeToFile(string filename, Airport list[], int size) {

    cout << "\nThe updated data has been saved into the file \"" << filename << "\"." << endl;
    ofstream myFile;
    myFile.open(filename);

    myFile << "Sorted List:\n";

    insertSort(list, size);
    for(int i = 0; i < size; i++) {
      myFile << list[i].code << " " << list[i].city << " (" << list[i].code << ")" << endl;
    }
}

int binarySearch(Airport list[], int size, string key) {
   int mid;
   int low;
   int high;
   
   low = 0;
   high = size - 1;
   
   while (high >= low) {
      mid = (high + low) / 2;
      if (list[mid].code < key) {
         low = mid + 1;
      }
      else if (list[mid].code > key) {
         high = mid - 1;
      }
      else {
         return mid;
      }
   }
   
   return -1; // not found
}
