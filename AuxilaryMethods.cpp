#include "AuxilaryMethods.h"

string AuxilaryMethods::konwerjsaIntNaString(int liczba) {
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

char AuxilaryMethods::wczytajZnak() {
    string wejscie = "";
    char znak  = {0};

    while (true) {
        getline(cin, wejscie);

        if (wejscie.length() == 1) {
            znak = wejscie[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return znak;
}
string AuxilaryMethods::loadLine() {
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
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

string AuxilaryMethods::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst) {
    if (!tekst.empty()) {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
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

