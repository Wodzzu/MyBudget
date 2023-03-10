#include "BudgetManager.h"


int BudgetManager::setNewIncomeId() {
    if (incomes.empty())
        return 1;
    else
        return incomes.back().getIncomeId() + 1;
}

int BudgetManager::setNewExpenseId() {
    if (expenses.empty())
        return 1;
    else
        return expenses.back().getExpenseId() + 1;
}

Income BudgetManager::addNewIncomeData() {

    Income income;
    char pick ;
    int setDate = 0;
    string userEnteredDate ="";
    double amount = 0;

    income.setIncomeId(setNewIncomeId());

    income.setUserId(LOGGED_USER_ID);

    cout << endl << "Would you like to use present day or the previous one? " << endl;
    cout << "If yes press 'y' " << endl;

    pick = AuxilaryMethods::loadMark();
    if ((pick == 'y') || pick == 'Y') {
        setDate = AuxilaryMethods::getTodayDate();
        income.setIncomeDate(setDate);
    } else {
        do {
            cout << endl << "Write income date: In Order yyyy-mm-dd" << endl;
            userEnteredDate = AuxilaryMethods::loadLine();
        } while(!(AuxilaryMethods::checkUserDate(userEnteredDate)));
        setDate = AuxilaryMethods::changeEnteredDateToNumber(userEnteredDate);
        income.setIncomeDate(setDate);
    }

    cout << "Write source of Income: " << endl;
    income.setItem(AuxilaryMethods::loadLine());
    do {
        cout << "Write amount of Income: " << endl;
        amount = AuxilaryMethods::changeStringToDouble(AuxilaryMethods::loadLine());
        if(amount > 0)
            income.setAmount(amount);
        else {
            cout << "You entered wrong amount. Try agian" << endl;
        }
    } while(amount <= 0);
    return income;
}

void BudgetManager::registerIncome() {
    Income income;
    income = addNewIncomeData();
    incomes.push_back(income);
    incomeFile.addIncomeToFile(income);
    cout << endl << "Income registered" << endl << endl;
    system("pause");
}

Expense BudgetManager::addNewExpenseData() {

    Expense expense;
    char pick ;
    int setDate = 0;
    string userEnteredDate ="";
    double amount;

    expense.setExpenseId(setNewExpenseId());

    expense.setUserId(LOGGED_USER_ID);

    cout << endl << "Would you like to use present day or the previous one? " << endl;
    cout << "If yes press 'y' " << endl;
    pick = AuxilaryMethods::loadMark();
    if ((pick == 'y') || pick == 'Y') {
        setDate = AuxilaryMethods::getTodayDate();
        expense.setExpenseDate(setDate);
    } else {
        do {
            cout << endl << "Write expense date: In Order yyyy-mm-dd" << endl;
            userEnteredDate = AuxilaryMethods::loadLine();
        } while(!(AuxilaryMethods::checkUserDate(userEnteredDate)));
        setDate = AuxilaryMethods::changeEnteredDateToNumber(userEnteredDate);
        expense.setExpenseDate(setDate);
    }
    cout << "Write source of Expense: " << endl;
    expense.setItem(AuxilaryMethods::loadLine());
    do {
        cout << "Write amount of Expense: " << endl;
        amount = AuxilaryMethods::changeStringToDouble(AuxilaryMethods::loadLine());
        if(amount > 0)
            expense.setAmount(amount);
        else {
            cout << "You entered wrong amount. Try agian" << endl;
        }
    } while(amount <= 0);
    return expense;
}

void BudgetManager::registerExpense() {
    Expense expense;
    expense = addNewExpenseData();
    expenses.push_back(expense);
    expenseFile.addExpenseToFile(expense);
    cout << endl << "Expense registered" << endl << endl;
    system("pause");
}

void BudgetManager::sortCashOperationByDate() {

    struct incomeOperator {
        bool operator() (Income &i1, Income &i2) {
            return (i1.getIncomeDate() < i2.getIncomeDate());
        }
        bool operator() ( Expense &e1, Expense &e2) {
            return (e1.getExpenseDate() < e2.getExpenseDate());
        }
    };
    sort(incomes.begin(), incomes.end(), incomeOperator());
    sort(expenses.begin(), expenses.end(), incomeOperator());

}

void BudgetManager::runningMonthCashBalance() {

    int firstRunningMonthDay=0, maxDaysNumberInRunningMonth, maxDaysInMonthDateNumber;
    string firstRunningMonthDayText ="", maxDaysInRunningMonthText="";

    firstRunningMonthDayText =  AuxilaryMethods::changeIntToString(AuxilaryMethods::getTodayDate());
    maxDaysNumberInRunningMonth = AuxilaryMethods::howManyDaysInMonth(firstRunningMonthDayText);
    maxDaysInRunningMonthText = firstRunningMonthDayText.replace(6, 2, AuxilaryMethods::changeIntToString(maxDaysNumberInRunningMonth));
    maxDaysInMonthDateNumber = AuxilaryMethods::changeStringToInt(maxDaysInRunningMonthText);
    firstRunningMonthDayText.replace(6, 2, "01");
    firstRunningMonthDay = AuxilaryMethods::changeStringToInt(firstRunningMonthDayText);

    cout << endl << "*****Running Month Cash Balance*****" << endl;

    showBalance(firstRunningMonthDay, maxDaysInMonthDateNumber);

}

void BudgetManager::previousMonthCashBalance() {

    int previousMonthDate = AuxilaryMethods::getPreviousMonthDate();
    string previousMonthDateText = AuxilaryMethods::changeIntToString(previousMonthDate);
    int maxPreviousMonthDays = AuxilaryMethods::howManyDaysInMonth(AuxilaryMethods::changeDateToString(previousMonthDate));
    string maxDaysInMonth = AuxilaryMethods::changeIntToString(maxPreviousMonthDays);
    string maxPreviousMonthDateText = previousMonthDateText.erase(6, 2) + maxDaysInMonth;
    int previousMonthDateMaxNumberOfDays = AuxilaryMethods::changeStringToInt(maxPreviousMonthDateText);

    cout << endl << "*****Previous Month Cash Balance*****" << endl;

    showBalance(previousMonthDate, previousMonthDateMaxNumberOfDays);

}

void BudgetManager::periodCashBalance() {

    string firstDateText, secondDateText;
    int firstDateNumber, secondDateNumber;

    do {
        cout << "Enter first date in order yyyy-mm-dd: " << endl;
        firstDateText = AuxilaryMethods::loadLine();
    } while(!AuxilaryMethods::checkUserDate(firstDateText));
    do {
        cout << "Enter second date in order yyyy-mm-dd: " << endl;
        secondDateText = AuxilaryMethods::loadLine();
    } while(!AuxilaryMethods::checkUserDate(secondDateText));

    firstDateNumber = AuxilaryMethods::changeEnteredDateToNumber(firstDateText);
    secondDateNumber = AuxilaryMethods::changeEnteredDateToNumber(secondDateText);

    if(firstDateNumber>secondDateNumber) {

        int swapDate;
        swapDate = firstDateNumber;
        firstDateNumber = secondDateNumber;
        secondDateNumber = swapDate;
    }

    cout << endl << "*****Period Cash Balance*****" << endl;

    showBalance(firstDateNumber, secondDateNumber);
}

void BudgetManager::showBalance(int firstPeriodDate, int lastPeriodDate) {

    double incomeSum = 0, expenseSum = 0;

    sortCashOperationByDate();

    cout << endl << "Incomes: " << endl;
    cout << fixed << setprecision(2) << endl;
    for(unsigned int i = 0; i < incomes.size(); i++) {
        if(incomes[i].getUserId() == LOGGED_USER_ID && incomes[i].getIncomeDate() >= firstPeriodDate && incomes[i].getIncomeDate() <= lastPeriodDate) {
            cout << "- Date: " << AuxilaryMethods::changeDateToString(incomes[i].getIncomeDate()) << " - Item: " << incomes[i].getItem() << " - Amount: " << incomes[i].getAmount() << " zl" << endl;

            incomeSum = incomeSum + incomes[i].getAmount();
        }
    }
    cout << endl << "Expenses: " << endl;

    for(unsigned int i = 0; i < expenses.size(); i++) {
        if(expenses[i].getUserId() == LOGGED_USER_ID && expenses[i].getExpenseDate() >= firstPeriodDate && expenses[i].getExpenseDate() <= lastPeriodDate) {
            cout << "- Date: " << AuxilaryMethods::changeDateToString(expenses[i].getExpenseDate()) << " - Item: " << expenses[i].getItem() << " - Amount: " << expenses[i].getAmount() << " zl" << endl;

            expenseSum = expenseSum + expenses[i].getAmount();
        }
    }
    cout << endl << "Incomes Total: " << incomeSum << " zl" <<endl;
    cout << "Expenses Total: " << expenseSum << " zl" << endl;
    cout << "Balance: " << incomeSum-expenseSum << " zl" << endl << endl;
    system("pause");

}


