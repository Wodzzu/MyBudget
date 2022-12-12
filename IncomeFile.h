#ifndef IncomeFile_H
#define IncomeFile_H
#include <iostream>
#include <vector>
#include <cstdlib>

#include "Income.h"
#include "DBFile.h"

using namespace std;

class IncomeFile : public DBFile {

public:

IncomeFile(string fileName) : DBFile(fileName){};




};
#endif
