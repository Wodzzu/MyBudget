#include "AuxilaryMethods.h"

string AuxilaryMethods::changeIntToString( int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxilaryMethods::changeDoubleToString( double number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

char AuxilaryMethods::loadMark() {
    string enter = "";
    char mark  = {0};

    while (true) {
        getline(cin, enter);

        if (enter.length() == 1) {
            mark = enter[0];
            break;
        }
        cout << "This is not simple mark. Try agian" << endl;
    }
    return mark;
}

string AuxilaryMethods::loadLine() {
    string line = "";
    getline(cin, line);
    return line;
}

int AuxilaryMethods::changeStringToInt(string number) {
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

double AuxilaryMethods::changeStringToDouble(string number) {


    for ( unsigned int i = 0; i < number.length(); i++) {
        if( number[i]==',')
            number[i]='.';
    }
    double numberDouble;
    istringstream iss(number);
    iss >> numberDouble;

    return numberDouble;
}

string AuxilaryMethods::changeFirstLetterToCapital( string text) {
    if (!text.empty()) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

int AuxilaryMethods::howManyDaysInMonth(string enteredDate) {
    string userMonth, userYear;
    int userMonthNumber, userYearNumber;

    userMonth = enteredDate;
    userMonth.erase(0,5);
    userMonth.erase(2,3);

    userYear = enteredDate;
    userYear.erase(userYear.begin()+4,userYear.end());

    userYearNumber = changeStringToInt(userYear);
    userMonthNumber = changeStringToInt(userMonth);

    if(userMonthNumber>0&&userMonthNumber<13) {

        switch(userMonthNumber) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
            break;
        case 2: {
            if(((userYearNumber%4==0)&&(userYearNumber%100!=0))||(userYearNumber%400==0))
                return 29;
            else
                return 28;
        }
        break;

        }
    }
    return 0;
}

bool AuxilaryMethods::checkYear(string date) {

    time_t today = time(0);
    tm *todayDate = localtime(&today);

    string userYear;
    int presentYear, userYearNumber;

    date.erase(date.begin()+4,date.end());
    userYearNumber = changeStringToInt(date);

    presentYear = 1900 + todayDate->tm_year;

    if(userYearNumber>=2000 && userYearNumber<=presentYear) {
        return true;
    }
    cout<<"You wrote wrong year.Try agian."<<endl;
    return false;

}

bool AuxilaryMethods::checkMonth(string date) {

    string userMonth;
    int userMonthNumber;

    date.erase(0,5);
    date.erase(2,3);

    userMonthNumber = changeStringToInt(date);

    if(userMonthNumber>0 && userMonthNumber <=12) {
        return true;
    }
    cout<<"You wrote wrong month.Try agian."<<endl;
    return false;

}

bool AuxilaryMethods::checkDay(string date) {

    string userDay;
    int maxMonthDays = 0,userDayNumber;

    maxMonthDays = howManyDaysInMonth(date);

    date.erase(0,8);
    userDayNumber = changeStringToInt(date);

    if(userDayNumber>0 && userDayNumber<=maxMonthDays) {
        return true;
    }
    cout<<"You wrote wrong day.Try agian."<<endl;
    return false;
}

bool AuxilaryMethods::checkUserDate(string date) {

    AuxilaryMethods auxMethods;
    string userDate = date;
    bool goodYear, goodMonth, goodDay;

    if (userDate.length() !=10) {
        cout << "Wrong date format. You wrote to many or to low marks." << endl;
        return false;
    } else if (userDate[4]!='-' || userDate[7]!='-') {
        cout << "Wrong yyyy-mm-dd  format." << endl;
        return false;
    } else {
        goodYear = auxMethods.checkYear(userDate);
        goodMonth = auxMethods.checkMonth(userDate);
        goodDay = auxMethods.checkDay(userDate);

        if(goodYear&&goodMonth&&goodDay)
            return true;
        else
            return false;
    }
}

int AuxilaryMethods::changeEnteredDateToNumber(string date) {

    string enteredYear, enteredMonth, enteredDay, textDate;
    int numberEnteredDate;

    for ( unsigned int i = 0; i <date.length(); i++) {
        if(i<4)
            enteredYear = enteredYear+date[i];
        else if(i>4 && i<7)
            enteredMonth = enteredMonth+date[i];
        else if(i>7)
            enteredDay = enteredDay+date[i];
    }
    textDate = enteredYear + enteredMonth + enteredDay;
    numberEnteredDate = AuxilaryMethods::changeStringToInt(textDate);
    return numberEnteredDate;
}

int AuxilaryMethods::getPreviousMonthDate() {

    time_t today = time(0);
    tm *todayDate = localtime(&today);

    int presentMonth, previousMonth, previousMonthYear, previousMonthDateNumber;
    string previousMonthText, previousMonthYearText, previousMonthFirstDayText, previousMonthDate;

    presentMonth = 1+ todayDate->tm_mon;

    previousMonth = presentMonth - 1;
    previousMonthYear = 1900 + todayDate->tm_year;

    previousMonthFirstDayText = "01";

    if(previousMonth == 0) {
        previousMonth = 12;
        previousMonthText = changeIntToString(previousMonth);
        previousMonthYear = previousMonthYear - 1;
        previousMonthYearText = changeIntToString(previousMonthYear);
    } else {
        previousMonthText = changeIntToString(previousMonth);
        previousMonthYearText = changeIntToString(previousMonthYear);
        if(previousMonthText.length()<2)
            previousMonthText='0' + previousMonthText;

    }

    previousMonthDate = previousMonthYearText + previousMonthText + previousMonthFirstDayText;
    previousMonthDateNumber = changeStringToInt(previousMonthDate);
    return previousMonthDateNumber;
}

int AuxilaryMethods::getTodayDate() {

    time_t today = time(0);
    int presentYearNumber, presentMonthNumber, presentDayNumber, presentDateNumber;
    string presentYearText, presentMonthText, presentDayText, presentDateText;
    tm *date = localtime(&today);

    presentYearNumber = 1900 + date->tm_year;
    presentMonthNumber = 1+date->tm_mon;
    presentDayNumber = date->tm_mday;
    presentYearText = AuxilaryMethods::changeIntToString(presentYearNumber);
    presentMonthText = AuxilaryMethods::changeIntToString(presentMonthNumber);
    if(presentMonthText.length() < 2)
        presentMonthText = '0' + presentMonthText;
    presentDayText = AuxilaryMethods::changeIntToString(presentDayNumber);
    if(presentDayText.length() < 2)
        presentDayText = '0' + presentDayText;
    presentDateText = presentYearText + presentMonthText + presentDayText;
    presentDateNumber = AuxilaryMethods::changeStringToInt(presentDateText);
    return presentDateNumber;
}

string AuxilaryMethods::changeDateToString(int dateNumber) {
    string dateText= "";
    dateText = AuxilaryMethods::changeIntToString(dateNumber);
    dateText.insert(4,"-");
    dateText.insert(7,"-");
    return dateText;
}

int AuxilaryMethods::changeDateToInt(string date) {

    int dateNumber;
    date.erase(4,1);
    date.erase(6,1);
    dateNumber = AuxilaryMethods::changeStringToInt(date);
    return dateNumber;
}
