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
    fName = AuxilaryMethods::loadLine();
    user.setFirstName(AuxilaryMethods::changeFirstLetterToCapital(fName));

    string lName;
    cout << "Write your last name please: "<<endl;
    lName = AuxilaryMethods::loadLine();
    user.setLastName(AuxilaryMethods::changeFirstLetterToCapital(lName));

    string login;
    cout << "Set login please: "<<endl;
    login = AuxilaryMethods::loadLine();
    user.setLogin(login);

    string password;
    cout << "Set password please: "<<endl;
    password = AuxilaryMethods::loadLine();
    user.setPassword(password);

    return user;
}



void UserManager::registerUser(){

User user = setNewUserData();
userFile.addUserToFile(user);
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
    system("pause");
}

int UserManager::logInUser()
{
    User user;
    string login = "", password = "";

    cout << endl << "Write login: ";
    login = AuxilaryMethods::loadLine();

    for (int i = 0; i <users.size(); i++) {
        if (users[i].getLogin() == login) {
            for (int trialNumber = 3; trialNumber > 0; trialNumber--) {
                    if(trialNumber > 1){
                cout << "Write password. " << trialNumber << " trials left."<<endl;
                    }
                    else {
                    cout << "Write password. " << trialNumber << " trial left."<<endl;
                    }
                password = AuxilaryMethods::loadLine();

                if (users[i].getPassword() == password) {
                    cout << endl << "You are logged in." << endl << endl;
                    system("pause");
                    loggedUserId = users[i].getId();
                    return  loggedUserId;
                }
            }
            cout << "You entered 3 times wrong password." << endl;
            system("pause");
            return 0;
        }

    }
    cout << "User with this login doesn't exist" << endl << endl;
    system("pause");
    return 0;
}


