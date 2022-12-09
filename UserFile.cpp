#include "UserFile.h"


void UserFile::addUserToFile(User user){

CMarkup xml;

xml.Load(getFileName());

if(!isFileEmpty()){
xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
xml.AddElem("Users");
}
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId",user.getId() );
    xml.AddElem("FirstName", user.getFirstName());
    xml.AddElem("LastName", user.getLastName());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());

    xml.Save(getFileName());

}

vector <User> UserFile::loadUsersFromFile(){

CMarkup xml;
User user;
vector <User> users;
xml.Load(getFileName());


if(isFileEmpty()){
xml.FindElem();
xml.IntoElem();
while(xml.FindElem("User")){

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
else {

 cout << "I can not load the file."<< endl<<endl;
}
return users;


}



/*void UserFile::pobieranieElementow(){

CMarkup xml;
User user;

xml.Load(getFileName());
xml.FindElem();
xml.IntoElem();
while(xml.FindElem("User")){

        xml.IntoElem();
        xml.FindElem("UserId");
        user.setId(atoi(MCD_2PCSZ(xml.GetData())));
   cout<<     user.getId() <<endl;
        xml.FindElem("FirstName");
        user.setFirstName(xml.GetData());
    cout << user.getFirstName()<<endl;
        xml.FindElem("LastName");
        user.setLastName(xml.GetData());
        cout << user.getLastName() <<endl;
        xml.FindElem("Login");
        user.setLogin(xml.GetData());
            cout << user.getLogin()<<endl;
        xml.FindElem("Password");
        user.setPassword(xml.GetData());
            cout << user.getPassword()<<endl;
             xml.OutOfElem();
}
}
*/
