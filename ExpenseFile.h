#ifndef ExpenseFile_H
#define ExpenseFile_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include "Expense.h"

#include "DBFile.h"

using namespace std;

class ExpenseFile : public DBFile {

public:

    ExpenseFile(string fileName) : DBFile(fileName) {};

    void addExpenseToFile(Expense expense);
    vector <Expense> loadUserExpenses(int loggedUserId);


};
#endif
