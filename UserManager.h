#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>

#include "User.h"
#include "AuxilaryMethods.h"

using namespace std;

class UserManager {

int loggedUserId;
vector <User> users;

User setNewUserData();
int setNewUserId();

public:
  void registerUser();
  int logInUser();
  void logOutUser();
  void changeUserPassword();
  void showAllData();

};
