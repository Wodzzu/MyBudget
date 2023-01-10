#include "IncomeFile.h"

void IncomeFile::addIncomeToFile(Income income) {

    CMarkup xml;

    xml.Load(getFileName());

    if(!isFileEmpty()) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId",income.getIncomeId() );
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("IncomeDate", AuxilaryMethods::changeDateToString(income.getIncomeDate()));
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", AuxilaryMethods::changeDoubleToString(income.getAmount()));

    xml.Save(getFileName());

}

vector <Income> IncomeFile::loadUserIncomes(int loggedUserId) {

    CMarkup xml;
    Income income;
    vector <Income> incomes;
    int idFromFile = 0;

    xml.Load(getFileName());

    if(isFileEmpty()) {
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("Income")) {

            xml.IntoElem();
            xml.FindElem("IncomeId");
            income.setIncomeId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem("UserId");
            idFromFile = atoi(MCD_2PCSZ(xml.GetData()));
            if(idFromFile == loggedUserId) {
                income.setUserId(idFromFile);
                xml.FindElem("IncomeDate");
                income.setIncomeDate(AuxilaryMethods::changeDateToInt(xml.GetData()));
                xml.FindElem("Item");
                income.setItem(xml.GetData());
                xml.FindElem("Amount");
                income.setAmount(atof(MCD_2PCSZ(xml.GetData())));
                xml.OutOfElem();
                incomes.push_back(income);
            } else
                xml.OutOfElem();
        }
    }
    return incomes;

}



