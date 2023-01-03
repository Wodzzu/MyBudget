#include <iostream>



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
int setNewIncomeId();
int getTodayDate();
Income addNewIncomeData();
Expense addNewExpenseData();
int setNewExpenseId();
public:
    BudgetManager(string incomeFileName, string expenseFileName, int loggedUserId) : incomeFile(incomeFileName), expenseFile(expenseFileName), LOGGED_USER_ID(loggedUserId)
    {incomes = incomeFile.loadUserIncomes();expenses = expenseFile.loadUserExpenses();};



void registerIncome();
void registerExpense();
void showAllData();
};
