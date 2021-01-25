/*
 CIS 22B: Create and process an array of Patient objects
 Name: Rohith Vishwajith
 IDE: XCode
*/

#include "Patient.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

const int MAX_SIZE = 100;

/* Write your code here:
declare the function you are going to call in this program
*/
void createArray(string filename, Patient patArr[], int size);
void displayOutput(Patient patArr[], int size);
void writeToFile(string oldName, Patient patArr[], int size);

int main()
{
    Patient patArr[MAX_SIZE];
    int size = 0;

    string fileName;
    cout << "Please enter the input file's name: ";
    cin >> fileName;
    cout << endl;
   /* Write your code here:
     function calls
   */
    createArray(fileName, patArr, MAX_SIZE);
    displayOutput(patArr, MAX_SIZE);
    writeToFile(fileName, patArr, MAX_SIZE);
   return 0;
}

/* This method parses through a given textfile and creates an
 array of valid Patient objects to attach to the array */
void createArray(string filename, Patient patArr[], int size) {
    
    ifstream myFile;
    myFile.open(filename);
    
    if(myFile.fail()){
        cout << "Input file: " << filename << " not found!\n";
        exit(EXIT_FAILURE);
    }
    
    string line;
    int age, weight;
    double height;
    string name;
    
    int i = 0;
    
    while(getline(myFile, line) && i < MAX_SIZE) {
        age =  stoi(line.substr(0, line.find(" ")));
        line = line.substr(line.find(" ") + 1, line.length());
        
        height = stod(line.substr(0, line.find(" ")));
        line = line.substr(line.find(" ") + 1, line.length());
        
        weight = stoi(line.substr(0, line.find(" ")));
        line = line.substr(line.find(" ") + 1, line.length());
        
        name = line;
        patArr[i] = Patient(name, age, height, weight);
        i++;
    }
    myFile.close();
}

/* Dispays the patient if they are in an unhealthy weight category */
void displayOutput(Patient patArr[], int size) {
    
    int underweightCnt = 0;
    int overweightCnt = 0;
    int obeseCnt = 0;
    
    cout << "Showing patients with the \"Underweight\" status:" << endl;
    for(int i = 0; i < size; i++) {
        if(patArr[i].weightStatus() == "Underweight") {
            cout << patArr[i].getName() << endl;
            underweightCnt++;
        }
    }
    if(underweightCnt == 0) {
        cout << "none\n";
    }
    else {
        cout << endl;
    }
    
    cout << "Showing patients with the \"Overweight\" status:" << endl;
    for(int i = 0; i < size; i++) {
        if(patArr[i].weightStatus() == "Overweight") {
            cout << patArr[i].getName() << endl;
            overweightCnt++;
        }
    }
    if(overweightCnt == 0) {
        cout << "none\n";
    }
    else {
        cout << endl;
    }
    
    cout << "Showing patients with the \"Obese\" status:" << endl;
    for(int i = 0; i < size; i++) {
        if(patArr[i].weightStatus() == "Obese") {
            cout << patArr[i].getName() << endl;
            obeseCnt++;
        }
    }
    if(obeseCnt == 0) {
        cout << "none\n";
    }
    else {
        cout << endl;
    }
}

/*
modifies the file name to add report" before the "."
for the output file and wrties to the file
*/

void writeToFile(string oldName, Patient patArr[], int size) {
    
    string newFileName = oldName.substr(0, oldName.find(".")) + "Report.";
    // this may be necessary because files are not always .txt
    string fileType = oldName.substr(oldName.find(".") + 1, oldName.length());
    newFileName += fileType;
    
    // writing to file
    ofstream myFile;
    myFile.open(newFileName);
    
    myFile << "Weight Status Report\n";
    myFile << "==================== === ====== ====== =============\n";
    myFile << "Name                 Age Height Weight Status\n";
    myFile << "==================== === ====== ====== =============\n";
    
    for(int i = 0; i < size; i++) {
        myFile << left << setw(20) << patArr[i].getName() << " ";
        myFile << right << setw(3) << patArr[i].getAge() << " ";
        myFile << right << setw(4) << patArr[i].getHeight() << "   ";
        myFile << right << setw(5) << patArr[i].getAge() << "  ";
        myFile << left << " " << patArr[i].weightStatus() << endl;
    }
    myFile.close();
    
    cout << "Report saved in:  " << newFileName << endl;
}
