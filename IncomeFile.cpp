#include "IncomeFile.h"



void IncomeFile::addIncomeToFile(Income income){

CMarkup xml;

xml.Load(getFileName());

if(!isFileEmpty()){
xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
xml.AddElem("Incomes");
}
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId",income.getIncomeId() );
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("IncomeDate", changeDateToString(income.getIncomeDate()));
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", AuxilaryMethods::changeDoubleToString(income.getAmount()));

    xml.Save(getFileName());

}



