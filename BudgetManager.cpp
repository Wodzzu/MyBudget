#include "BudgetManager.h"

int BudgetManager::setNewIncomeId() {
    if (incomes.empty())
        return 1;
    else
        return incomes.back().getIncomeId() + 1;
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
income.setAmount(AuxilaryMethods::changeStringToInt(AuxilaryMethods::loadLine()));
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
