#ifndef DBFile_H
#define DBFile_H

#include <iostream>
#include <windows.h>
#include <string>


#include "Markup.h"
#include "AuxilaryMethods.h"

using namespace std;

class DBFile {

 const string FILE_NAME;

 public:


    DBFile(string fileName): FILE_NAME(fileName) {};

    string getFileName();
     bool isFileEmpty();
     string changeDateToString (int dateNumber);

};
#endif
