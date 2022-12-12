#include "MyBudget.h"

char MyBudget::pickMenuOption(){

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
void MyBudget::userRegistration(){

userManager.registerUser();
}

void MyBudget::mainMenu(){

 while (true) {
        if (userManager.getLoggedUserId() == 0) {
            pick = pickMenuOption();

            switch (pick) {
            case '1':
                userRegistration();
                break;
            case '2':
                //logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Wrong number, try agian." << endl << endl;
                system("pause");
                break;


}
        }
 }
}
