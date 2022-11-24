#include <iostream>

#include "UserManager.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    UserManager usermanager;
    usermanager.registerUser();
    usermanager.showAllData();




    return 0;
}
