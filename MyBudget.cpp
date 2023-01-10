#include "MyBudget.h"

void MyBudget::userChangePassword() {
    userManager.changeUserPassword();
}

void MyBudget::userRegistration() {
    userManager.registerUser();
}

void MyBudget::logIn() {

    userManager.logInUser();
    budgetManager = new BudgetManager(INCOME_FILE_NAME,EXPENSE_FILE_NAME,userManager.getLoggedUserId());

}

void MyBudget::logOut() {

    userManager.setLoggedUserId(0);
    delete budgetManager;
    budgetManager = NULL;

}

char MyBudget::pickMenuOption() {

    system("cls");
    cout << "    >>> MAIN  MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. REGISTRATION" << endl;
    cout << "2. LOG IN" << endl;
    cout << "9. EXIT" << endl;
    cout << "---------------------------" << endl;
    cout << "Pick Number: ";
    pick = AuxilaryMethods::loadMark();

    return pick;
}

char MyBudget::userMenu() {
    char pick;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add Income" << endl;
    cout << "2. Add Expense" << endl;
    cout << "3. Running month Balance" << endl;
    cout << "4. Previous month Balance" << endl;
    cout << "5. Date to Date Balance" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change Password" << endl;
    cout << "7. Log Out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your pick: ";
    pick = AuxilaryMethods::loadMark();

    return pick;
}

void MyBudget::mainMenu() {

    while (true) {
        if (userManager.getLoggedUserId() == 0) {
            pick = pickMenuOption();

            switch (pick) {
            case '1':
                userRegistration();
                break;
            case '2':
                logIn();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Wrong number, try agian." << endl << endl;
                system("pause");
                break;
            }
        } else {

            pick = userMenu();

            switch (pick) {
            case '1':
                budgetManager->registerIncome();
                break;
            case '2':
                budgetManager->registerExpense();
                break;
            case '3':
                budgetManager->runningMonthCashBalance();
                break;
            case '4':
                budgetManager->previousMonthCashBalance();
                break;
            case '5':
                budgetManager->periodCashBalance();
                break;
            case '6':
                userChangePassword();
                break;
            case '7':
                logOut();
                break;

            }
        }
    }
}

