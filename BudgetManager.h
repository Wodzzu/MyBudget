#include <iostream>
#include <ctime>


#include "AuxilaryMethods.h"
#include "IncomeFile.h"
#include "ExpenseFile.h"


using namespace std;

class BudgetManager {

IncomeFile incomeFile;
ExpenseFile expenseFile;

const int LOGGED_USER_ID;
vector <Expense> expenses;
vector <Income> incomes;

public:
    BudgetManager(string incomeFileName, string expenseFileName, int loggedUserId) : incomeFile(incomeFileName), expenseFile(expenseFileName), LOGGED_USER_ID(loggedUserId)
    {};

string getTodayDate();
void addIncome();
};
