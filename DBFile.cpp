#include "DBFile.h"

string DBFile::getFileName() {

    return FILE_NAME;
}

string DBFile::changeDateToString(int dateNumber) {
    string dateText= "";
    dateText = AuxilaryMethods::changeIntToString(dateNumber);
    dateText.insert(4,"-");
    dateText.insert(7,"-");
    return dateText;
}

int DBFile::changeDateToInt(string date) {

    int dateNumber;
    date.erase(4,1);
    date.erase(6,1);
    dateNumber = AuxilaryMethods::changeStringToInt(date);
    return dateNumber;

}

bool DBFile::isFileEmpty() {

    CMarkup xml;

    bool succes = xml.Load(getFileName());
    return succes;
}
