#include <iostream>
#include <algorithm>
#include <iomanip>

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
    Income addNewIncomeData();
    Expense addNewExpenseData();
    void sortCashOperationByDate();
    void showBalance(int firstPeriodDate, int lastPeriodDate);
public:
    BudgetManager(string incomeFileName, string expenseFileName, int loggedUserId) : incomeFile(incomeFileName), expenseFile(expenseFileName), LOGGED_USER_ID(loggedUserId) {
        if (LOGGED_USER_ID > 0){
        incomes = incomeFile.loadUserIncomes(LOGGED_USER_ID);
        expenses = expenseFile.loadUserExpenses(LOGGED_USER_ID);
        }
    };

    void runningMonthCashBalance();
    void previousMonthCashBalance();
    void registerIncome();
    void registerExpense();
    void periodCashBalance();
};
