#include <iostream>
#include <algorithm>


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
int setNewExpenseId();
int getTodayDate();
Income addNewIncomeData();
Expense addNewExpenseData();
void sortCashOperationByDate();
public:
    BudgetManager(string incomeFileName, string expenseFileName, int loggedUserId) : incomeFile(incomeFileName), expenseFile(expenseFileName), LOGGED_USER_ID(loggedUserId)
    {incomes = incomeFile.loadUserIncomes(LOGGED_USER_ID);expenses = expenseFile.loadUserExpenses(LOGGED_USER_ID);};


void runningMonthCashBalance();
void previousMonthCashBalance();
void registerIncome();
void registerExpense();
void showAllData();
void periodCashBalance();

};
