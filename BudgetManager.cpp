#include "BudgetManager.h"

string BudgetManager::getTodayDate(){

 time_t today = time(0);
int yearNumber,monthNumber,dayNumber;
string yearText,monthText,dayText,dateText;
   tm *date = localtime(&today);


   yearNumber = 1900 + date->tm_year;
   monthNumber = date->tm_mon;
   dayNumber = date->tm_mday;
yearText = AuxilaryMethods::changeIntToString(yearNumber);
monthText = AuxilaryMethods::changeIntToString(monthNumber);
dayText = AuxilaryMethods::changeIntToString(dayNumber);

dateText = yearText+'-'+monthText+'-'+dayText;
return dateText;
}

void BudgetManager::addIncome(){

Income income;
char pick ;
string setDate;


cout<<endl<< "Would you like to use present day or the previous one? "<<endl;
cout<<"If yes press 'y' "<<endl;
pick = AuxilaryMethods::loadMark();
if (pick == 'y'||'Y')
{
    setDate = getTodayDate();
}
else
    cout<<endl<<"Write income date: In Order yyyy-mm-dd"<<endl;
    setDate = AuxilaryMethods::loadLine();


system("pause");

}
