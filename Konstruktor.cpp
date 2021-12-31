#include <iostream>

#include <math.h>

using namespace std;

class Okrag {
    private:
        string nazwa;
    float promien;
    public:
        Okrag() {};
    Okrag(string nazwa_, float promien_): nazwa(nazwa_), promien(promien_) {}~Okrag() {};
    string getNazwa() {
        return nazwa;
    }
    float getPromien() {
        return promien;
    }
    float obwod() {
        return 2 * 3.14 * promien;
    }
    void wyswietl() {
        cout << getNazwa() << " " << obwod() << " ";
    }
    void wprowadzDane() {
        cin >> nazwa;
        cin >> promien;
    }
};

int main() {
    int rozmiarTablicy = 0;
    cin >> rozmiarTablicy;

    Okrag * tablica = new Okrag[rozmiarTablicy];
    for (int i = 0; i < rozmiarTablicy; i++) {
        tablica[i].wprowadzDane();
    }
    int i, j;
    for (i = 0; i < rozmiarTablicy; i++) {
        for (j = 0; j < rozmiarTablicy - i - 1; j++) {
            if (tablica[j].obwod() < tablica[j + 1].obwod())
                swap(tablica[j], tablica[j + 1]);
        }
    }
    for (int i; i < rozmiarTablicy; i++) {
        tablica[i].wyswietl();
    }
    return 0;
}