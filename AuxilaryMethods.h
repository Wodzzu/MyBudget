#ifndef MetodyPomocnicze_H
#define MetodyPomocnicze_H
#include <iostream>
#include <sstream>
#include <algorithm>


using namespace std;

class AuxilaryMethods {
public:
    static string konwerjsaIntNaString(int liczba);
    static char wczytajZnak();
    static string loadLine();
    static int konwersjaStringNaInt(string liczba);
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    static int wczytajLiczbeCalkowita();
};
#endif
