#ifndef ENCYCLOPEDIAH
#define ENCYCLOPEDIAH

#include "Book.h"

class Encyclopedia : public Book {

public:
   // TODO: Declare mutator functions -
   //       SetEdition(), SetNumVolumes()
    void SetEdition(string n);
    void SetNumVolumes(int n);

   // TODO: Declare accessor functions -
   //       GetEdition(), GetNumVolumes()
    string GetEdition();
    int GetNumVolumes();


   // TODO: Declare a PrintInfo() function that overrides
   //       the PrintInfo in Book class
    void PrintInfo();

   // TODO: Declare private fields: edition, numVolumes
private:
    string edition;
    int numVolumes;
};

#endif
