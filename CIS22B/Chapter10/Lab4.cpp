#include <string>
#include <iostream>

using namespace std;

// TODO: Define a generic method called CheckOrder() that
//       takes in four variables of generic type as arguments.
//       The return type of the method is integer
template<typename TheType>
int CheckOrder(TheType item1, TheType item2, TheType item3, TheType item4) {
    
    if(item1 > item2 && item2 > item3 && item3 > item4) {
        return 1;
    }
    else if (item1 < item2 && item2 < item3 && item3 < item4) {
        return -1;
    }
    else {
        return 0;
    }
}

   // Check the order of the input: return -1 for ascending,
   // 0 for neither, 1 for descending


int main(int argc, char* argv[]) {
   // Read in four strings
   string stringArg1, stringArg2, stringArg3, stringArg4;
   cin >> stringArg1;
   cin >> stringArg2;
   cin >> stringArg3;
   cin >> stringArg4;
   
    // Check order of four strings
   cout << "Order: " << CheckOrder(stringArg1, stringArg2, stringArg3, stringArg4) << endl;

   // Read in four doubles
   double doubleArg1, doubleArg2, doubleArg3, doubleArg4;
   cin >> doubleArg1;
   cin >> doubleArg2;
   cin >> doubleArg3;
   cin >> doubleArg4;
   // Check order of four doubles
   cout << "Order: " << CheckOrder(doubleArg1, doubleArg2, doubleArg3, doubleArg4) << endl;
   
   return 0;
}
