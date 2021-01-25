// Rohith Vishwajith
// CIS22B
// Chapter 7
// XCode - Lab16.cpp
// 11/8/20
// Zybooks Lab 7.16 - Patient Class - Array of Patient objects (overload operators)

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
void sortPatients(Patient arr[], int size);

int main()
{
    Patient patArr[MAX_SIZE];

    string fileName;
    cout << "Please enter the input file's name: ";
    cin >> fileName;
    cout << endl;
    
    createArray(fileName, patArr, MAX_SIZE);
    displayOutput(patArr, MAX_SIZE);
    writeToFile(fileName, patArr, MAX_SIZE);
   return 0;
}

 /* Write your code here:
     function definitions
   */

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
    
    sortPatients(patArr, i);
}

/* Dispays the patient if they are in an unhealthy weight category */
void displayOutput(Patient patArr[], int size) {
    
    int underweightCnt = 0;
    int overweightCnt = 0;
    int obeseCnt = 0;
    
    string showUnderweight;
    cout << "Display \"Underweight\"[Y/N]? ";
    cin >> showUnderweight;
    
    for (int i = 0; i < showUnderweight.length(); i++)
        showUnderweight[i] = (toupper(showUnderweight[i]));
    
    if(showUnderweight == "Y" || showUnderweight == "YES") {
        
        cout << "Showing patients with the \"Underweight\" status:" << endl;
        
        for(int i = 0; i < size; i++) {
            if(patArr[i].weightStatus() == "Underweight") {
                cout << patArr[i];
                underweightCnt++;
            }
        }
        if(underweightCnt == 0) {
            cout << "none\n";
        }
        else {
            cout << endl;
        }
    }
    
    string showOverweight;
    cout << "Display \"Overweight\"[Y/N]? ";
    cin >> showOverweight;
    
    for (int i = 0; i < showOverweight.length(); i++)
        showOverweight[i] = (toupper(showOverweight[i]));
    
    if(showOverweight == "Y" || showOverweight == "YES") {
        cout << "Showing patients with the \"Overweight\" status:" << endl;
        for(int i = 0; i < size; i++) {
            if(patArr[i].weightStatus() == "Overweight") {
                cout << patArr[i];
                overweightCnt++;
            }
        }
        if(overweightCnt == 0) {
            cout << "none\n";
        }
        else {
            cout << endl;
        }
    }
    
    string showObese;
    cout << "Display \"Obese\"[Y/N]? ";
    cin >> showObese;
    
    for (int i = 0; i < showObese.length(); i++)
        showObese[i] = (toupper(showObese[i]));
    
    if(showObese == "Y" || showObese == "YES") {
        cout << "Showing patients with the \"Obese\" status:" << endl;
        for(int i = 0; i < size; i++) {
            if(patArr[i].weightStatus() == "Obese") {
                cout << patArr[i];
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
    
    string showNormal;
    cout << "Display \"Normal\"[Y/N]? ";
    cin >> showNormal;
    
    for (int i = 0; i < showNormal.length(); i++)
        showNormal[i] = (toupper(showNormal[i]));
    
    // the checks for "Y" or "YES" and the capitalization could
    // be made more efficient using additional methods, I wasn't
    // sure if this was allowed or not.
    
    if(showNormal == "Y" || showNormal == "YES") {
        cout << "Showing patients with the \"Normal\" status:" << endl;
        for(int i = 0; i < size; i++) {
            if(patArr[i].weightStatus() == "Normal") {
                cout << patArr[i];
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
        myFile << patArr[i];
    }
    myFile.close();
    
    cout << "Report saved in:  " << newFileName << endl;
}

void sortPatients(Patient arr[], int size) {
    
    int j;
    Patient temp;
    
    for (int i = 1; i < size; ++i) {
       
       temp = arr[i];
       j = i - 1;
       while(j >= 0 && temp < arr[j]) {
           // shift elements to the right by one index
           arr[j + 1] = arr[j];
           j = j - 1;
       }
       arr[j + 1] = temp;
    }
}
