// Rohith Vishwajith
// CIS22B
// Chapter 1
// XCode - Lab11.cpp
// 9/26/20
// Zybooks Lab 1.11 - Airports 3

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

// function prototypes
void printInfo();
void readArpData(string filename, int &size, int limit, string code[], int enp[], string city[]);
int binarySearch(const string codes[], int size, string key);
void searchTestDriver(const string [], const int [], const string [], int [], int);
void writeToFile(string, const string [], const int [], const string [], const int [], int size);

int main()
{
    // constant definition
    const int AIRPORTS = 500;   // maximum size of arrays
    
    // filenames
    string infilename = "airports.txt";
    string outfilename = "searchReport.txt";
    
    // arrays definitions
    string city[AIRPORTS];
    string code[AIRPORTS];
    int enp[AIRPORTS];
    int searchCount[AIRPORTS];

    for(int i = 0; i < AIRPORTS; i++) {
      searchCount[i] = 0;
    }
    
    int size;
    // function calls
    printInfo();
    readArpData(infilename, size, AIRPORTS, code, enp, city);
    //cout << "\nsize" << size << endl;
    searchTestDriver(code, enp, city, searchCount, size);
    writeToFile(outfilename, code, enp, city, searchCount, size);

    return 0;
}
/*~*~*~*~*~*~
This function displays the project's title
*~*/
void printInfo()
{
    cout << "Project: Airports" << endl;
}

/*~*~*~*~*~*~
This function reads data about airports from a file into 3 parallel arrays.
The size variable will hold the number of airports that were stored in these arrays.
*~*/
void readArpData(string filename, int &size, int limit, string code[], int enp[], string city[])
{
    ifstream inputFile;
    
    // open file
    inputFile.open(filename);
    
    // validation
    if(inputFile.fail()){
        cout << "Error opening the input file: " << filename << ".\n";
        exit(EXIT_FAILURE);
    }
    
    // read data from file into three parallel arrays
    size = 0;
    while (size < limit && inputFile >> code[size] >> enp[size]){
        inputFile.ignore();
        getline(inputFile, city[size]);
        size++;
    }

    // check if size reaches maximum size of array and there is more data in the file
    if(size == limit && !inputFile.eof()){
        cout << "\nThe file contains more than "<< limit << "lines!\n";
        exit(EXIT_FAILURE);
    }

    // close file
    inputFile.close();
}

/*~*~*~*~*~*~
 This function performs the binary search on a string array. The array has
 size elements. A value stored in this array will be searched. It will
 return the array subscript if found. Otherwise, -1 will be returned.
*~*/
int binarySearch(const string codes[], int size, string key) {
   int mid;
   int low;
   int high;
   
   low = 0;
   high = size - 1;
   
   while (high >= low) {
      mid = (high + low) / 2;
      if (codes[mid] < key) {
         low = mid + 1;
      }
      else if (codes[mid] > key) {
         high = mid - 1;
      }
      else {
         return mid;
      }
   }
   
   return -1; // not found
}

/*~*~*~*~*~*~
 This writeToFile function accepts four arrays and their size, and a string value as arguments.
 It will show the number of searches for each airport, and airports information into an output
 file.
*~*/
void writeToFile(string filename,
                 const string code[],
                 const int enp[],
                 const string city[],
                 const int searchCount[],
                 int size)
{
  cout << "\nThe updated data has been saved into the file \"" << filename << "\"." << endl;
  ofstream myfile;
  myfile.open("searchReport.txt");

  for(int i = 0; i < size; i++) {
    myfile << searchCount[i] << " " << code[i] << " " << city[i] << " (" << enp[i] << ")" << endl;
  }

  myfile.close();
}
/*~*~*~*~*~*~
 This function:
    - prompts the user to enter an airport code
    - calls binary search to search for that code
    - displays related data if found, or an error message
    - keeps track of the number of searches
    - asks the user if they want to continue searching
 *~*/
void searchTestDriver(const string code[],
                      const int enp[],
                      const string city[],
                      int searchCount[],
                      int size)
{
    bool lookupMore = true;
    while(lookupMore) {
      cout << "Please enter an airport code, such as LAX: ";
      string inputCode;
      cin >> inputCode;
      int position = binarySearch(code, size, inputCode);
      if(position >= 0) {
        cout << code[position] << " found! See related data below:\n";
        cout << "        " << "Code: " << code[position] << endl;
        cout << "        " << "City: " << city[position] << endl;
        cout << "Enplanements: " << enp[position] << endl;
        searchCount[position]++;
      }
      else {
        cout << inputCode << " not found!" << endl;
      }
      cout << "Would you like to look up another airport(Y/N)? ";
      char inputChar;
      cin >> inputChar;
      if(inputChar == 'N') {
        lookupMore = false;
      }
    }
}


/*~*~*~*~*~*~ Save the output below



*~*/
