#include "DBFile.h"

string DBFile::getFileName(){

    return FILE_NAME;

}

string DBFile::changeDateToString(int dateNumber)
{
    string dateText= "";
    dateText = AuxilaryMethods::changeIntToString(dateNumber);
    dateText.insert(4,"-");
     dateText.insert(7,"-");
     return dateText;
}

bool DBFile::isFileEmpty(){

CMarkup xml;

bool succes = xml.Load(getFileName());
return succes;

}
