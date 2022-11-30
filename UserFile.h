#ifndef UserFile_H
#define UserFile_H
#include <iostream>
#include <vector>

#include "Markup.h"
#include "DBFile.h"
#include "User.h"

using namespace std;

class UserFile : public DBFile {

public:

UserFile(string UserFileName) : DBFile(UserFileName) {
    };
void addUserToFile(User user);

};
#endif
