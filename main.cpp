#include <iostream>

#include "MyBudget.h"

using namespace std;

int main()
{

    MyBudget myBudget("users.xml","incomes.xml","expences.xml");
    myBudget.mainMenu();




    return 0;
}
