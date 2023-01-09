#ifndef UserFile_H
#define UserFile_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "DBFile.h"
#include "User.h"

using namespace std;

class UserFile : public DBFile {

public:

    void addChangedPasswordToFile(string newPassword, int loggedUserId);
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();

    UserFile(string UserFileName) : DBFile(UserFileName) {
    };


};
#endif
