#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "funkcije.h"
#include "klasa_osoba.h"



using namespace std;













int main() {
    string putanja = "porodica.txt"; // Promenjena putanja do datoteke
    vector<Osoba> osobe = procitajFajlINapraviOsobe(putanja);

    string answer;
pocetak:cout << "Za nalazenje predaka unesi 1\nZa ispitivanje zajednickog pretka unesi 2\n\nUnesi odgovor:";
    cin >> answer;
    if (answer == "1") {
        string unosIme;
    ponovo_ime:cout << "Unesite ime osobe: ";
        cin >> unosIme;
        if (unosIme == "izlaz") {
            exit(0);
        }
        string level_skraceni;
        bool osobaNadjen = false;
        bool izuzetak = false;
        if (unosIme == "Mihailo(Jovan)") {
            izuzetak = true;
        }
        for (const auto& osoba : osobe) {
            if (osoba.ime == unosIme) {
                osobaNadjen = true;
                cout << izvadiIme(unosIme) << "-";
                level_skraceni = skratiLevel(osoba.level);
                while (level_skraceni.size() != 0) {
                    for (auto& osobaa : osobe) {
                        if (osobaa.level == level_skraceni) {
                            if (level_skraceni.size() != 1) {
                                cout << izvadiIme(osobaa.ime) << "-";
                            }
                            else {
                                cout << izvadiIme(osobaa.ime);
                            }
                            level_skraceni = skratiLevel(level_skraceni);
                        }
                    }
                }cout << "\n\n\n\n";
            }
        }

        if (!osobaNadjen) {
            cout << "Osoba sa imenom '" << unosIme << "' nije pronaðena." << endl;
            vector<string> imena;
            for (auto& osoba : osobe) {
                imena.push_back(osoba.ime);
            }
            proveriRec(unosIme);
            goto ponovo_ime;

        }
    }
    else if (answer == "2") {

        bool pronadjen;



        string ime1, ime2;
    ponovo_imee:cout << "\nUnesi prvo ime:";
        cin >> ime1;
        pronadjen = proveriRec(ime1);
        if (pronadjen == false) {
            goto ponovo_imee;
        }

        pronadjen = false;

    ponovo_imeee:cout << "Unesi drugo ime:";
        cin >> ime2;
        pronadjen = proveriRec(ime2);
        if (pronadjen == false) {
            goto ponovo_imeee;
        }

        string level1;
        string level2;
        for (auto& osoba : osobe) {
            if (ime1 == osoba.ime) {
                level1 = osoba.level;
            }
        }

        for (auto& osoba : osobe) {
            if (ime2 == osoba.ime) {
                level2 = osoba.level;
            }
        }
        string level_zajednicki = zajednickaPocetnaSlova(level1, level2);
        for (auto& osoba : osobe) {
            if (level_zajednicki == osoba.level) {
                cout << "\nPrvi zajednicki predak je " << osoba.ime << endl << endl << endl;
            }
        }


    }
    else {
        cout << "Pogresan unos!";
        goto pocetak;
    }
    return 0;
}
