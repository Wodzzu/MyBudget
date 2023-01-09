#include <iostream>


using namespace std;

class Income {

    int incomeId;
    int userId;
    int incomeDate;
    string item;
    double amount;

public:
    void setIncomeId(int newId);
    void setUserId(int userId);
    void setIncomeDate(int newIncomeDate);
    void setItem(string newItem);
    void setAmount(double newAmount);

    int getIncomeId();
    int getUserId();
    int getIncomeDate();
    string getItem();
    double getAmount();
};
