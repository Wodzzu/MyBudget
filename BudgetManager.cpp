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
if(presentMonthText.length()<2)
    presentMonthText='0'+presentMonthText;
presentDayText = AuxilaryMethods::changeIntToString(presentDayNumber);
if(presentDayText.length()<2)
    presentDayText='0'+presentDayText;
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
bool operator() ( Expense &e1, Expense &e2)
{
   return (e1.getExpenseDate() < e2.getExpenseDate());
}
};

sort(incomes.begin(),incomes.end(),incomeOperator());
sort(expenses.begin(),expenses.end(),incomeOperator());

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
void BudgetManager::runningMonthCashBalance(){

int firstRunningMonthDay=0;
double runningMonthIncome=0,runningMonthExpense=0;
string firstRunningMonthDayText ="";

firstRunningMonthDayText =  AuxilaryMethods::changeIntToString(getTodayDate());
firstRunningMonthDayText.replace(6,2,"01");
firstRunningMonthDay = AuxilaryMethods::changeStringToInt(firstRunningMonthDayText);

cout<<endl<<"*****Running Month Cash Balance*****"<<endl;

cout<<endl<<"Incomes: "<<endl;

sortCashOperationByDate();

for(int i = 0;i<incomes.size();i++)
{
    if(incomes[i].getUserId()==LOGGED_USER_ID && incomes[i].getIncomeDate()>=firstRunningMonthDay ){
    cout<<"Id :"<<incomes[i].getIncomeId()<<" - Date: "<<incomes[i].getIncomeDate()<<" - Item: "<<incomes[i].getItem()<<" - Amount: "<<incomes[i].getAmount()<<endl;

        runningMonthIncome= runningMonthIncome + incomes[i].getAmount();
    }
}
cout<<endl<<"Expenses: "<<endl;

for(int i = 0;i<expenses.size();i++)
{
    if(expenses[i].getUserId()==LOGGED_USER_ID && expenses[i].getExpenseDate()>=firstRunningMonthDay ){
    cout<<"Id :"<<expenses[i].getExpenseId()<<" - Date: "<<expenses[i].getExpenseDate()<<" - Item: "<<expenses[i].getItem()<<" - Amount: "<<expenses[i].getAmount()<<endl;

        runningMonthExpense= runningMonthExpense + expenses[i].getAmount();
    }
}
cout<<endl<<"Incomes Total: "<< runningMonthIncome<<endl;
cout<<"Expenses Total: "<< runningMonthExpense<<endl;
cout<<"Balance: "<<runningMonthIncome-runningMonthExpense<<endl<<endl;
system("pause");
}

void BudgetManager::previousMonthCashBalance(){

int previousMonthDate = AuxilaryMethods::getPreviousMonthDate();
string previousMonthDateText = AuxilaryMethods::changeIntToString(previousMonthDate);
int maxPreviousMonthDays = AuxilaryMethods::howManyDaysInMonth(incomeFile.changeDateToString(previousMonthDate));
string maxDaysInMonth = AuxilaryMethods::changeIntToString(maxPreviousMonthDays);
string maxPreviousMonthDateText = previousMonthDateText.erase(6,2)+maxDaysInMonth;
int previousMonthDateMaxNumberOfDays = AuxilaryMethods::changeStringToInt(maxPreviousMonthDateText);



double previousMonthIncome=0,previousMonthExpense=0;


cout<<endl<<"*****Previous Month Cash Balance*****"<<endl;

cout<<endl<<"Incomes: "<<endl;

sortCashOperationByDate();

for(int i = 0;i<incomes.size();i++)
{
    if(incomes[i].getUserId()==LOGGED_USER_ID && incomes[i].getIncomeDate()>=previousMonthDate && incomes[i].getIncomeDate()<=previousMonthDateMaxNumberOfDays ){
    cout<<"Id :"<<incomes[i].getIncomeId()<<" - Date: "<<incomes[i].getIncomeDate()<<" - Item: "<<incomes[i].getItem()<<" - Amount: "<<incomes[i].getAmount()<<endl;

        previousMonthIncome= previousMonthIncome + incomes[i].getAmount();
    }
}
cout<<endl<<"Expenses: "<<endl;

for(int i = 0;i<expenses.size();i++)
{
    if(expenses[i].getUserId()==LOGGED_USER_ID && expenses[i].getExpenseDate()>=previousMonthDate && expenses[i].getExpenseDate()<=previousMonthDateMaxNumberOfDays ){
    cout<<"Id :"<<expenses[i].getExpenseId()<<" - Date: "<<expenses[i].getExpenseDate()<<" - Item: "<<expenses[i].getItem()<<" - Amount: "<<expenses[i].getAmount()<<endl;

        previousMonthExpense= previousMonthExpense + expenses[i].getAmount();
    }
}
cout<<endl<<"Incomes Total: "<< previousMonthIncome<<endl;
cout<<"Expenses Total: "<< previousMonthExpense<<endl;
cout<<"Balance: "<<previousMonthIncome-previousMonthExpense<<endl<<endl;
system("pause");



}
