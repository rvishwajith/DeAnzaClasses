/*
 Build and procees a sorted linked list of Patient objects.
 The list is sorted in ascending order by name.
 Assume that the name is unique.
*/

// Written By: A. Student
// Changed By:
// IDE: Xcode


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>
#include "LinkedList.h"

using namespace std;

void buildList(const string &filename, LinkedList &list);
void deleteManager(LinkedList &list);
void searchManager(const LinkedList &list);
void displayManager(const LinkedList &list);

int main()
{

    string inputFileName = "patient.txt";
    LinkedList list;

    buildList(inputFileName, list);
    displayManager(list);
    searchManager(list);
    deleteManager(list);
    displayManager(list);
    return 0;
}

/*
 This function reads data about patients from a file and inserts them
 into a sorted linked list. The list is sorted in ascending order by name
 */
void buildList(const string &filename, LinkedList &list)
{
    ifstream inFile(filename);
    cout << "Reading data from \"" << filename << "\"\n";

    if(!inFile)
    {
        cout << "Error opening the input file: \""<< filename << "\"" << endl;
        exit(EXIT_FAILURE);
    }

    int age;
    double height;
    int weight;
    string name;

    while (inFile >> age >> height >> weight )
    {
        inFile.ignore(); //ignore a space
        getline(inFile, name);
        // create a Patient object and initialize it with data from file
        
        Patient p = Patient(name, age, height, weight);
        
        // call insert to insert this new Patient object into the sorted list
        list.insertNode(p);
    }

    inFile.close();
}

/*
 Delete manager: delete items from the list until the user enters Q to quit
 deleting
 Input Parameter: list
 */
void deleteManager(LinkedList &list)
{
    string target = "";

    cout << "\n Delete\n";
    cout << "=======\n";

    while(target != "Q")
    {
        cout << endl << "Enter a name (or Q to stop deleting) : \n";
        getline(cin, target);
        cout << endl;
        target[0] = toupper(target[0]);
        if(target != "Q")
        {
            if(list.deleteNode(target))
                cout << target << " has been deleted!\n";
            else
                cout << "College \"" << target << "\" was not found in this list." << endl;
        }
    }
    cout << "___________________END DELETE SECTION_____\n";
}

/*
 Search manager: search the list until the user enters Q to quit searching
 Input Parameter: list
 */
void searchManager(const LinkedList &list)
{
    string target = "";
    Patient aPatient;

    cout << "\n Search\n";
    cout <<   "=======\n";

   /* Write your code here */
    cout << "___________________END SEARCH SECTION _____\n";
}

/*
Display manager: diplay a header, formatted list content, and footer,
 depending on the user's choice;
 displays the number of nodes (always)
Input Parameter: list
*/
void displayManager(const LinkedList &list)
{
    // Sub-functions of displayManager()
    void showMenu(void);
    string getOption(void);
    void showHeader(string line);
   
    
    string line = "==================== ========= ============= =========== =============\n";
    string option;
    
    showMenu();
    option = getOption();
    while(option[0] != 'Q')
    {
        showHeader(line);
        switch (option[0])
        {
            case 'A':
               list.displayList();
                break;
            case 'U':
                list.displayList("Underweight");
                break;
            case 'N':
                list.displayList("Normal");
                break;
            case 'O':
                list.displayList("Overweight");
                break;
            case 'B':
                list.displayList("Obese");
                break;
        }
        cout << line;
        option = getOption();
    }
    cout << "Number of patients: " << list.getLength() << endl;
}

/*
Displays the header of the list used in displayManager()
Input Parameter: line
*/
void showHeader(string line)
{
    cout << line;
    cout << left << setw(21) << "Name"
              << setw(11) << "Age"
              << setw(13) << "Height"
              << setw(12) << "Weight"
              << setw(13) << "Status" << endl;
     cout << line;
}

/*
Displays a menu, gets and returns the user's option (used in displayManager())
*/
string getOption(void)
{
    void showMenu(void);
    
    string option;
    cout << "What is your option [A/U/N/O/B/Q]? ";
    cin >> option;
    cin.ignore();
    option[0] = toupper(option[0]);
    while (option != "A" && option != "U" && option != "N" && option != "O" && option != "B" && option != "Q")
    {
        cout << "Invalid Option: Try again!";
        cout << "What is your option [A/U/N/O/B/Q]? ";
        cin >> option;
        cin.ignore();
        option[0] = toupper(option[0]);
    }
    
    return option;
}
/*
Displays a menu - used in displayManager()
*/
void showMenu(void)
{
    cout << "The following reports are available: " << endl;
    cout << "[A] - All" << endl
         << "[U] - Underweight" << endl
         << "[N] - Normal" << endl
         << "[O] - Overweight" << endl
         << "[B] - Obese" << endl
         << "[Q] - Quit" << endl;
}
