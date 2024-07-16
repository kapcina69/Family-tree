#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;




class Osoba {
public:
    string ime;
    string level;

    Osoba(string ime, string level) {
        this->ime = ime;
        this->level = level;
    }
};

vector<Osoba> procitajFajlINapraviOsobe(const string& putanjaFajla) {
    vector<Osoba> osobe;
    ifstream file(putanjaFajla);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            size_t pos = line.find(' ');
            if (pos != string::npos) {
                string ime = line.substr(0, pos);
                string level = line.substr(pos + 1);
                osobe.push_back(Osoba(ime, level));
            }
        }
        file.close();
    }
    else {
        cout << "Neuspesno otvaranje fajla: " << putanjaFajla << endl;
    }

    return osobe;
}