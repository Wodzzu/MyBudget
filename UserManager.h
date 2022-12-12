#ifndef UserManager_H
#define UserManager_H

#include <iostream>
#include <vector>
//#include <windows.h>
//#include <fstream>

#include "Markup.h"
#include "User.h"
#include "UserFile.h"
#include "AuxilaryMethods.h"

using namespace std;

class UserManager {


    UserFile userFile;

    int loggedUserId;
    vector <User> users;

    User setNewUserData();
    int setNewUserId();

public:
    UserManager(string userFileName) : userFile(userFileName) {
        loggedUserId =0;
        users = userFile.loadUsersFromFile();
    };
    void loadUsersFromFile();
    void registerUser();
    int logInUser();
    void logOutUser();
    void changeUserPassword();
    void showAllData();
    bool ifLoginExists(string login);
    int getLoggedUserId();
    void setLoggedUserId(int newId);

};
#endif
