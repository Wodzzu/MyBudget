#include <iostream>

using namespace std;

class Expense {

    int expenseId;
    int userId;
    int expenseDate;
    string item;
    double amount;

public:
    void setExpenseId(int newId);
    void setUserId(int userId);
    void setExpenseDate(int newExpenseDate);
    void setItem(string newItem);
    void setAmount(double newAmount);

    int getExpenseId();
    int getUserId();
    int getExpenseDate();
    string getItem();
    double getAmount();
};
