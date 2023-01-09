#ifndef UserManager_H
#define UserManager_H

#include <iostream>
#include <vector>


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
    void loadUsersFromFile();
    bool ifLoginExists(string login);

public:
    UserManager(string userFileName) : userFile(userFileName) {
        loggedUserId =0;
        users = userFile.loadUsersFromFile();
    };

    void registerUser();
    int logInUser();
    void logOutUser();
    int getLoggedUserId();
    void setLoggedUserId(int newId);
    void changeUserPassword();

};
#endif
