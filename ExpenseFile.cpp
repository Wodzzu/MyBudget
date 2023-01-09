#include "ExpenseFile.h"


void ExpenseFile::addExpenseToFile(Expense expense) {

    CMarkup xml;

    xml.Load(getFileName());

    if(!isFileEmpty()) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseId",expense.getExpenseId() );
    xml.AddElem("UserId", expense.getUserId());
    xml.AddElem("ExpenseDate", changeDateToString(expense.getExpenseDate()));
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Amount", AuxilaryMethods::changeDoubleToString(expense.getAmount()));

    xml.Save(getFileName());

}

vector <Expense> ExpenseFile::loadUserExpenses(int loggedUserId) {

    CMarkup xml;
    Expense expense;
    vector <Expense> expenses;
    xml.Load(getFileName());
    int idFromFile = 0;

    if(isFileEmpty()) {
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("Expense")) {

            xml.IntoElem();
            xml.FindElem("ExpenseId");
            expense.setExpenseId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem("UserId");
            idFromFile = atoi(MCD_2PCSZ(xml.GetData()));
            if(idFromFile == loggedUserId) {
                expense.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
                xml.FindElem("ExpenseDate");
                expense.setExpenseDate(DBFile::changeDateToInt(xml.GetData()));
                xml.FindElem("Item");
                expense.setItem(xml.GetData());
                xml.FindElem("Amount");
                expense.setAmount(atof(MCD_2PCSZ(xml.GetData())));
                xml.OutOfElem();
                expenses.push_back(expense);
            } else
                xml.OutOfElem();
        }
    }

    else {

        cout << "I can not load the expenses file."<< endl<<endl;
        Sleep(1500);
    }
    return expenses;

}

