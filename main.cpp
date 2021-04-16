#include <iostream>
#include <fstream>
#include <string>

using namespace std;
ifstream wejscie;
ofstream wyjscie;
bool wynik=true;
bool sprawdz() {
    if (wejscie.good() && wyjscie.good()) 
	return true;
    else return false;
}
bool wyszukaj(string sprawdzana) {
    char liczba = sprawdzana[0];
    for (int i = 1; i < sprawdzana.length(); i++) {
        if (liczba == sprawdzana[i]&&liczba == '1') {
        	return false;
        }
        liczba = sprawdzana[i];
    }
    return true;
}
int main()
{
    wejscie.open("ciagi.txt");
    wyjscie.open("wynik.txt");
    string ciag;
    if (sprawdz() == true) {
        while (!wejscie.eof()) {
            wejscie >> ciag;
            if (wyszukaj(ciag) == true) {
                cout << ciag << endl;
                wyjscie << ciag << endl;
            }
        }
        wejscie.close();
        wyjscie.close();
    }
    return 0;
}
