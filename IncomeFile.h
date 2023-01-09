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

    IncomeFile(string incomeFileName) : DBFile(incomeFileName) {};

    void addIncomeToFile(Income income);
    vector <Income> loadUserIncomes(int loggedUserId);


};
#endif
