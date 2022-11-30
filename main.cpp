#include <iostream>

#include "UserManager.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    UserManager usermanager("users.xml");
    usermanager.registerUser();
   usermanager.registerUser();
    usermanager.showAllData();
    usermanager.logInUser();




    return 0;
}
