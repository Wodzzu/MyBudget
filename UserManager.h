#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>

#include "User.h"

using namespace std;

class UserManager {

int loggedUserId;
vector <User> users;

User setNewUserData();
int setNewUserId();

public:
  void registerUser();
  void logInUser();
  void logOutUser();
  void changeUserPassword();
  void showAllData();

};
