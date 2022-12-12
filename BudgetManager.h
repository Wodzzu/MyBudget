#include <iostream>

#include "IncomeFile.h"
#include "ExpenseFile.h"


using namespace std;

class BudgetManager {

IncomeFile incomeFile;
ExpenseFile expenseFile;

//const int LOGGED_USER_ID;
vector <Expense> expenses;
vector <Income> incomes;

public:
    BudgetManager(string incomeFileName,string expenseFileName) : incomeFile(incomeFileName), expenseFile(expenseFileName)
    {};
};
