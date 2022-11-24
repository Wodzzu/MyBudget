#include <iostream>


using namespace std;

class User {

    int id;
    string firstName;
    string lastName;
    string login;
    string password;

    public:
    void setId(int newId);
    void setFirstName(string newFirstName);
    void setLastName(string newLastName);
    void setLogin(string newLogin);
    void setPassword(string newPassword);

    int getId();
    string getFirstName();
    string getLastName();
    string getLogin();
    string getPassword();

};
