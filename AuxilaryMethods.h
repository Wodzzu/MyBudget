#ifndef AuxilaryMethods_H
#define AuxilaryMethods_H
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <ctime>



using namespace std;

class AuxilaryMethods {
    time_t today = time(0);
    tm *todayDate = localtime(&today);


public:
    static string changeIntToString(int number);
    static char loadMark();
    static string loadLine();
    static int changeStringToInt(string number);
    static string changeFirstLetterToCapital(string tekst);
     bool checkYear(string date);
       bool checkMonth(string date);
       bool checkDay(string date);
       int howManyDaysInMonth(string enteredDate);
       static bool checkUserDate(string date);
       static int changeEnteredDateToNumber(string date);

    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static int wczytajLiczbeCalkowita();
};
#endif
