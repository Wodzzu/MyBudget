#include "ExpenseFile.h"


void ExpenseFile::addExpenseToFile(Expense expense){

CMarkup xml;

xml.Load(getFileName());

if(!isFileEmpty()){
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
    xml.AddElem("Amount", expense.getAmount());

    xml.Save(getFileName());

}



