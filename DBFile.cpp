#include "DBFile.h"

string DBFile::getFileName() {

    return FILE_NAME;
}

bool DBFile::isFileEmpty() {

    CMarkup xml;

    bool succes = xml.Load(getFileName());
    return succes;
}
