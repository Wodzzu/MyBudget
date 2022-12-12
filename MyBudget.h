#include <iostream>

#include "UserManager.h"
#include "BudgetManager.h"


using namespace std;

class MyBudget {

UserManager userManager;
BudgetManager *budgetManager;

const string INCOME_FILE_NAME;
const string EXPENSE_FILE_NAME;



public:
    MyBudget(string userFileName,string incomeFileName, string expenseFileName)
    : userManager(userFileName), INCOME_FILE_NAME(incomeFileName), EXPENSE_FILE_NAME(expenseFileName){
    budgetManager = NULL;

    };
~MyBudget() {
        delete budgetManager;
        budgetManager = NULL;
    }
};
