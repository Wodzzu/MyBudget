#ifndef AuxilaryMethods_H
#define AuxilaryMethods_H
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <ctime>

using namespace std;

class AuxilaryMethods {

public:
    static string changeIntToString(int number);
    static char loadMark();
    static string loadLine();
    static int changeStringToInt(string number);
    static string changeFirstLetterToCapital(string tekst);
    bool checkYear(string date);
    bool checkMonth(string date);
    bool checkDay(string date);
    static  int howManyDaysInMonth(string enteredDate);
    static bool checkUserDate(string date);
    static int changeEnteredDateToNumber(string date);
    static string changeDoubleToString(double number);
    static double changeStringToDouble(string number);
    static int getPreviousMonthDate();
    static int getTodayDate();
    static string changeDateToString(int dateNumber);
    static int changeDateToInt(string date);
};
#endif
