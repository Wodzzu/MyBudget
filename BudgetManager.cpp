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

int BudgetManager::getTodayDate(){

 time_t today = time(0);
int presentYearNumber,presentMonthNumber,presentDayNumber,presentDateNumber;
string presentYearText,presentMonthText,presentDayText,presentDateText;
   tm *date = localtime(&today);


   presentYearNumber = 1900 + date->tm_year;
   presentMonthNumber = 1+date->tm_mon;
   presentDayNumber = date->tm_mday;
presentYearText = AuxilaryMethods::changeIntToString(presentYearNumber);
presentMonthText = AuxilaryMethods::changeIntToString(presentMonthNumber);
presentDayText = AuxilaryMethods::changeIntToString(presentDayNumber);

presentDateText = presentYearText+presentMonthText+presentDayText;
presentDateNumber = AuxilaryMethods::changeStringToInt(presentDateText);
return presentDateNumber;
}

Income BudgetManager::addNewIncomeData(){

Income income;
char pick ;
int setDate = 0;
string userEnteredDate ="";

income.setIncomeId(setNewIncomeId());

income.setUserId(LOGGED_USER_ID);

cout<<endl<< "Would you like to use present day or the previous one? "<<endl;
cout<<"If yes press 'y' "<<endl;
pick = AuxilaryMethods::loadMark();
if ((pick == 'y') || pick == 'Y')
{
    setDate = getTodayDate();
    income.setIncomeDate(setDate);

}
else{
        do{
    cout<<endl<<"Write income date: In Order yyyy-mm-dd"<<endl;
    userEnteredDate = AuxilaryMethods::loadLine();
    }while(!(AuxilaryMethods::checkUserDate(userEnteredDate)));
        setDate = AuxilaryMethods::changeEnteredDateToNumber(userEnteredDate);
        income.setIncomeDate(setDate);


}

cout << "Write source of Income: "<<endl;
income.setItem(AuxilaryMethods::loadLine());

cout<<"Write amount of Income: "<<endl;
income.setAmount(AuxilaryMethods::changeStringToDouble(AuxilaryMethods::loadLine()));
return income;


}

void BudgetManager::registerIncome(){
Income income;
 income = addNewIncomeData();
 incomes.push_back(income);
incomeFile.addIncomeToFile(income);


cout << endl << "Income registered" << endl << endl;
    system("pause");
}
Expense BudgetManager::addNewExpenseData(){

Expense expense;
char pick ;
int setDate = 0;
string userEnteredDate ="";

expense.setExpenseId(setNewExpenseId());

expense.setUserId(LOGGED_USER_ID);

cout<<endl<< "Would you like to use present day or the previous one? "<<endl;
cout<<"If yes press 'y' "<<endl;
pick = AuxilaryMethods::loadMark();
if ((pick == 'y') || pick == 'Y')
{
    setDate = getTodayDate();
    expense.setExpenseDate(setDate);

}
else{
        do{
    cout<<endl<<"Write expense date: In Order yyyy-mm-dd"<<endl;
    userEnteredDate = AuxilaryMethods::loadLine();
    }while(!(AuxilaryMethods::checkUserDate(userEnteredDate)));
        setDate = AuxilaryMethods::changeEnteredDateToNumber(userEnteredDate);
        expense.setExpenseDate(setDate);


}

cout << "Write source of Expense: "<<endl;
expense.setItem(AuxilaryMethods::loadLine());

cout<<"Write amount of Expense: "<<endl;
expense.setAmount(AuxilaryMethods::changeStringToDouble(AuxilaryMethods::loadLine()));
return expense;


}

void BudgetManager::registerExpense(){
Expense expense;
 expense = addNewExpenseData();
 expenses.push_back(expense);
expenseFile.addExpenseToFile(expense);


cout << endl << "Expense registered" << endl << endl;
    system("pause");
}



void BudgetManager::sortCashOperationByDate(){

struct incomeOperator{
   bool operator() ( Income &i1, Income &i2)
{
   return (i1.getIncomeDate() < i2.getIncomeDate());
}

};

sort(incomes.begin(),incomes.end(),incomeOperator());

}

void BudgetManager::showAllData() {
    for (int i = 0; i<incomes.size(); i++) {
        cout<<incomes[i].getIncomeId()<<endl;
        cout<<incomes[i].getUserId()<<endl;
        cout<<incomes[i].getIncomeDate()<<endl;
        cout<<incomes[i].getItem()<<endl;
        cout<<incomes[i].getAmount()<<endl;
    }
    system("pause");
}
