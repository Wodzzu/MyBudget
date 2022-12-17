#include "AuxilaryMethods.h"

string AuxilaryMethods::changeIntToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

char AuxilaryMethods::loadMark() {
    string enter = "";
    char mark  = {0};

    while (true) {
        getline(cin, enter);

        if (enter.length() == 1) {
            mark = enter[0];
            break;
        }
        cout << "This is not simple mark. Try agian" << endl;
    }
    return mark;
}
string AuxilaryMethods::loadLine() {
    string line = "";
    getline(cin, line);
    return line;
}

int AuxilaryMethods::konwersjaStringNaInt(string liczba) {
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;

    return liczbaInt;
}

string AuxilaryMethods::pobierzLiczbe(string tekst, int pozycjaZnaku) {
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku])) {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}

string AuxilaryMethods::changeFirstLetterToCapital(string text) {
    if (!text.empty()) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}
int AuxilaryMethods::wczytajLiczbeCalkowita() {
    string wejscie = "";
    int liczba = 0;

    while (true) {
        getline(cin, wejscie);

        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return liczba;
}

