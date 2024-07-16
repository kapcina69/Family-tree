#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;




string izvadiIme(const string& input) {
    // Pronalazi prvu pojavu '(' i zatim prvu pojavu ')' nakon toga
    size_t start = input.find('(');
    size_t end = input.find(')');

    // Ako nismo pronašli ni poèetak ni kraj, ili ako je poèetak poslije kraja, ili ako nema imena
    if (start == string::npos || end == string::npos || start >= end) {
        return ""; // Prazan string
    }

    // Izdvajamo podstring izmeðu '(' i ')'
    return input.substr(0, start);
}

string zajednickaPocetnaSlova(const std::string& str1, const std::string& str2) {
    std::string rezultat;
    int min_duzina = std::min(str1.length(), str2.length());

    for (int i = 0; i < min_duzina; ++i) {
        if (str1[i] == str2[i]) {
            rezultat += str1[i];
        }
        else {
            // Ako se naiðe na prvi karakter koji se razlikuje, zaustavi se
            break;
        }
    }

    return rezultat;
}

string skratiLevel(const string& level) {
    return level.substr(0, level.length() - 1);
}

// Funkcija za pronalaženje najpribližnije reèi u fajlu
std::string pronadjiNajpribliznijuRec(const std::string& trazenaRec, const std::vector<std::string>& reciIzFajla) {
    // Inicijalizacija promenljive za najpribližniju reè
    std::string najpribliznijaRec;
    int najmanjeRazlike = std::numeric_limits<int>::max(); // Inicijalno postavljeno na maksimalnu vrednost

    // Iteriranje kroz sve reèi iz fajla i pronalaženje najpribližnije
    for (const std::string& rec : reciIzFajla) {
        // Pronalazi poziciju zatvorene zagrade
        size_t pozicija = rec.find(')');
        if (pozicija != std::string::npos) {
            // Izdvaja samo ime iz reèi
            std::string ime = rec.substr(0, pozicija + 1);
            int razlike = 0;
            // Raèuna broj razlika izmeðu tražene reèi i imena iz fajla
            for (size_t i = 0; i < std::min(ime.size(), trazenaRec.size()); ++i) {
                if (ime[i] != trazenaRec[i]) {
                    ++razlike;
                }
            }

            if (razlike < najmanjeRazlike) {
                najmanjeRazlike = razlike;
                najpribliznijaRec = ime;
            }
        }
    }

    return najpribliznijaRec;
}


// Funkcija za proveru unete reèi i pronalaženje najpribližnije u fajlu
bool proveriRec(const std::string& unetaRec) {
    std::ifstream fajl("porodica.txt");
    std::vector<std::string> reciIzFajla;

    // Uèitavanje svih reèi iz fajla
    std::string rec;
    while (fajl >> rec) {
        reciIzFajla.push_back(rec);
    }

    // Provera da li se uneta reè nalazi u fajlu
    auto it = std::find(reciIzFajla.begin(), reciIzFajla.end(), unetaRec);
    if (it == reciIzFajla.end()) {
        std::cout << "Da li ste mislili: " << pronadjiNajpribliznijuRec(unetaRec, reciIzFajla) << std::endl;
        return false;
    }
    else {
        std::cout << "Uneto ime je ispravno." << std::endl;
        return true;
    }
}