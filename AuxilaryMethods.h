#ifndef AuxilaryMethods_H
#define AuxilaryMethods_H
#include <iostream>
#include <sstream>
#include <algorithm>



using namespace std;

class AuxilaryMethods {
public:
    static string changeIntToString(int number);
    static char loadMark();
    static string loadLine();
    static int konwersjaStringNaInt(string liczba);
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static string changeFirstLetterToCapital(string tekst);
    static int wczytajLiczbeCalkowita();
};
#endif
