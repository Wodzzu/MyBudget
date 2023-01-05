#include "Expense.h"

    void Expense::setExpenseId(int newId){

        if(newId>0)
        expenseId = newId;
    }
    void Expense::setUserId(int newUserId){

        if(newUserId>0)
        userId = newUserId;
    }
    void Expense::setExpenseDate(int newExpenseDate){

        if(newExpenseDate>0)
        expenseDate = newExpenseDate;
    }
    void Expense::setItem(string newItem){

    item=newItem;

    }
    void Expense::setAmount(double newAmount){

    if(newAmount>0)
        amount = newAmount;
    }

    int Expense::getExpenseId(){
    return expenseId;
    }
    int Expense::getUserId(){
    return userId;
    }
    int Expense::getExpenseDate(){
    return expenseDate;
    }
    string Expense::getItem(){
    return item;
    }
    double Expense::getAmount(){
    return amount;
    }
