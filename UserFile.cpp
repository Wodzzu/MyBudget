#include "UserFile.h"

void UserFile::addUserToFile(User user) {

    CMarkup xml;

    xml.Load(getFileName());

    if(!isFileEmpty()) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getId() );
    xml.AddElem("FirstName", user.getFirstName());
    xml.AddElem("LastName", user.getLastName());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());

    xml.Save(getFileName());

}

vector <User> UserFile::loadUsersFromFile() {

    CMarkup xml;
    User user;
    vector <User> users;
    xml.Load(getFileName());

    if(isFileEmpty()) {
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("User")) {

            xml.IntoElem();
            xml.FindElem("UserId");
            user.setId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem("FirstName");
            user.setFirstName(xml.GetData());
            xml.FindElem("LastName");
            user.setLastName(xml.GetData());
            xml.FindElem("Login");
            user.setLogin(xml.GetData());
            xml.FindElem("Password");
            user.setPassword(xml.GetData());
            xml.OutOfElem();
            users.push_back(user);
        }
    }
    return users;

}

void UserFile::addChangedPasswordToFile(string newPassword, int loggedUserId) {

    int idFromFile = 0;

    CMarkup xml;

    xml.Load(getFileName());
    if(isFileEmpty()) {
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("User")) {

            xml.IntoElem();
            xml.FindElem("UserId");
            idFromFile = atoi(MCD_2PCSZ(xml.GetData()));
            if(idFromFile == loggedUserId) {
                xml.FindElem("Password");
                xml.SetData(newPassword);
            }
            xml.OutOfElem();
        }
    }
    xml.Save(getFileName());
}
