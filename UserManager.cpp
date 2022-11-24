#include "UserManager.h"

int UserManager::setNewUserId() {
    if (users.empty())
        return 1;
    else
        return users.back().getId() + 1;
}

User UserManager::setNewUserData() {
    User user;

    user.setId(setNewUserId());

    string fName;
    cout << "Write your first name please: "<<endl;
    cin>>fName;
    user.setFirstName(fName);

        string lName;
    cout << "Write your last name please: "<<endl;
    cin>>lName;
    user.setLastName(lName);

    string login;
    cout << "Set login please: "<<endl;
    cin >> login;
    user.setLogin(login);

    string password;
    cout << "Set password please: "<<endl;
    cin >> password;
    user.setPassword(password);

    return user;
}

void UserManager::registerUser(){

User user = setNewUserData();

users.push_back(user);

cout << endl << "Account registered" << endl << endl;
    system("pause");

}

void UserManager::showAllData()
{
    for (int i = 0; i<users.size(); i++)
    {
        cout<<users[i].getId()<<endl;
        cout<<users[i].getFirstName()<<endl;
        cout<<users[i].getLastName()<<endl;
        cout<<users[i].getLogin()<<endl;
        cout<<users[i].getPassword()<<endl;
    }
}

